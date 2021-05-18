# TestGetFinancialData.py
# 17/05/2021

from getFinancialData import getFinancialData, exportFinancialDataToExcel

# Define symbols stocks to get the financial data
symbols = ['SCYR.MC', 'GEST.MC', 'CABK.MC', 'MRL.MC', 'PSG.MC', 'MAP.MC']

df = getFinancialData(symbols)
exportFinancialDataToExcel('financialReport', df)