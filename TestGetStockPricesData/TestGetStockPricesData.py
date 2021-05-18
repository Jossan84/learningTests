# TestGetPriceStockData.py
# 18/05/2021

from getStockPricesData import getMultiStockData, exportStockPricesDataToExcel  

# Define symbols stocks to get the financial data
symbols = ['SCYR.MC', 'GEST.MC', 'CABK.MC', 'MRL.MC', 'PSG.MC', 'MAP.MC']

ds = getMultiStockData(symbols)
exportStockPricesDataToExcel('stockPricesData', ds)