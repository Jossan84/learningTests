# getStockPricesData.py
# 18/05/2021

from datetime import datetime
import pandas as pd

# Get stock prices info
def getStockData(symbol) :
    print('Attempting to scrape data for ' + symbol)
    
    url = 'https://finance.yahoo.com/quote/'+ symbol + '?p='+ symbol
    summary = pd.read_html(url)
    dsPricesSheet = summary[0]
    dsRatiosSheet = summary[1]

    dsJoined = dsPricesSheet \
            .join(dsRatiosSheet, how='outer', rsuffix=' - Ratio Statement') \
            .dropna(axis=1, how='all') \
            .reset_index()    
    dsJoined.insert(1, 'Symbol', symbol)
    return dsJoined

# Get multiple stocks prices info
def getMultiStockData(symbols) :
    return pd.concat([getStockData(symbol) for symbol in symbols], sort=False) 
    
# Export financial data to .xlsx file    
def exportStockPricesDataToExcel(fileName, ds) :
    date = datetime.today().strftime('%Y%m%d')
    # writer = pd.ExcelWriter(fileName + date + '.xls',  engine = 'xlwt')
    writer = pd.ExcelWriter(fileName + date + '.xlsx')
    ds.to_excel(writer)
    writer.save()