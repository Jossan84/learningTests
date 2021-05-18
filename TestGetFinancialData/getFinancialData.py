# getFinancialData.py
# 17/05/2021
from datetime import datetime
import pandas as pd
import xlwt
from yahooFinanceScraper import scrapeMulti

# Get financial data
def getFinancialData(symbols) :
    df = scrapeMulti(symbols)
    return df
    
# Export financial data to .xlsx file    
def exportFinancialDataToExcel(fileName, df) :
    date = datetime.today().strftime('%Y%m%d')
    # writer = pd.ExcelWriter(fileName + date + '.xls',  engine = 'xlwt')
    writer = pd.ExcelWriter(fileName + date + '.xlsx')
    df.to_excel(writer)
    writer.save()




