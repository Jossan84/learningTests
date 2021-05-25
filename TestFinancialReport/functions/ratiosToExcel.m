function ratiosToExcel(ratios)


  
  xlswrite('data/ratios.xls', [ratios.ticker;ratios.PER]);  
  
  
  
  
end
