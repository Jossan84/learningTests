# yahooFinanceScraper.py
# 17/05/2021

from datetime import datetime
import lxml
from lxml import html
import requests
import numpy as np
import pandas as pd

def getPage(url):
    # Set up the request headers that we're going to use, to simulate
    # a request by the Chrome browser. Simulating a request from a browser
    # is generally good practice when building a scraper
    headers = {
        'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3',
        'Accept-Encoding': 'gzip, deflate, br',
        'Accept-Language': 'en-US,en;q=0.9',
        'Cache-Control': 'max-age=0',
        'Pragma': 'no-cache',
        'Referrer': 'https://google.com',
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/77.0.3865.120 Safari/537.36'
    }

    return requests.get(url, headers)

def parseRows(tableRows):
    parsedRows = []

    for tableRow in tableRows:
        parsedRow = []
        el = tableRow.xpath("./div")

        noneCount = 0

        for rs in el:
            try:
                (text,) = rs.xpath('.//span/text()[1]')
                parsedRow.append(text)
            except ValueError:
                parsedRow.append(np.NaN)
                noneCount += 1

        if (noneCount < 4):
            parsedRows.append(parsedRow)
            
    return pd.DataFrame(parsedRows)

def cleanData(df):
    df = df.set_index(0) # Set the index to the first column: 'Period Ending'.
    df = df.transpose() # Transpose the DataFrame, so that our header contains the account names
    
    # Rename the "Breakdown" column to "Date"
    cols = list(df.columns)
    cols[0] = 'Date'
    df = df.set_axis(cols, axis='columns', inplace=False)
    
    numericColumns = list(df.columns)[1::] # Take all columns, except the first (which is the 'Date' column)

    for columnIndex in range(1, len(df.columns)): # Take all columns, except the first (which is the 'Date' column)
        df.iloc[:,columnIndex] = df.iloc[:,columnIndex].str.replace(',', '') # Remove the thousands separator
        df.iloc[:,columnIndex] = df.iloc[:,columnIndex].astype(np.float64) # Convert the column to float64
        
    return df

def scrapeTable(url):
    # Fetch the page that we're going to parse
    page = getPage(url);

    # Parse the page with LXML, so that we can start doing some XPATH queries
    # to extract the data that we want
    tree = html.fromstring(page.content)

    # Fetch all div elements which have class 'D(tbr)'
    tableRows = tree.xpath("//div[contains(@class, 'D(tbr)')]")
    
    # Ensure that some table rows are found; if none are found, then it's possible
    # that Yahoo Finance has changed their page layout, or have detected
    # that you're scraping the page.
    assert len(tableRows) > 0
    
    df = parseRows(tableRows)
    df = cleanData(df)
        
    return df

def scrape(symbol):
    print('Attempting to scrape data for ' + symbol)

    dfBalanceSheet = scrapeTable('https://finance.yahoo.com/quote/' + symbol + '/balance-sheet?p=' + symbol)
    dfBalanceSheet = dfBalanceSheet.set_index('Date')

    dfIncomeStatement = scrapeTable('https://finance.yahoo.com/quote/' + symbol + '/financials?p=' + symbol)
    dfIncomeStatement = dfIncomeStatement.set_index('Date')
    
    dfCashFlow = scrapeTable('https://finance.yahoo.com/quote/' + symbol + '/cash-flow?p=' + symbol)
    dfCashFlow = dfCashFlow.set_index('Date')
    
    dfJoined = dfBalanceSheet \
        .join(dfIncomeStatement, on='Date', how='outer', rsuffix=' - Income Statement') \
        .join(dfCashFlow, on='Date', how='outer', rsuffix=' - Cash Flow') \
        .dropna(axis=1, how='all') \
        .reset_index()
            
    dfJoined.insert(1, 'Symbol', symbol)
    
    return dfJoined
    
def scrapeMulti(symbols):
    return pd.concat([scrape(symbol) for symbol in symbols], sort=False)    