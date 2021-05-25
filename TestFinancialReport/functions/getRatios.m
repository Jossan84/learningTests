function [ratios] = getRatios(financialData)
  ratios = struct("ticker", [], "PER", [],...
                  "PriceCashFlow", [],...
                  "EarningYieldGap", [], "PriceToBookValue", [],...
                  "ROE", [],...
                  "RelatedPer", [], "ROA", [],...
                  "BookValue", []);
  
  tenYearsBondValue = -0.544;                                  
                                    
  for i = 1 : length(financialData.ticker)  
    ratios.ticker{i} =  financialData.ticker{i};
    ratios.PER{i} = financialData.price{i}/(financialData.netIncomeFromContinuingAndDiscontinuedOperation{i}/financialData.numStocks{i});
    ratios.PriceCashFlow{i} = financialData.price{i}/(financialData.freeCashFlow{i}/financialData.numStocks{i});
    ratios.EarningYieldGap{i} = (1/ratios.PER{i}) - tenYearsBondValue ;
    ratios.PriceToBookValue{i} = (financialData.price{i}*financialData.numStocks{i})/financialData.commonStockEquity{i};
    ratios.ROE{i} = (financialData.netIncomeFromContinuingAndDiscontinuedOperation{i}/financialData.commonStockEquity{i})*100;
    ratios.RelatedPer{i} = ratios.PriceToBookValue{i}/(ratios.ROE{i}/100);
    ratios.BookValue{i} = financialData.totalEquityGrossMinorityInterest{i}/financialData.numStocks{i};
    ratios.ROA{i} = (financialData.netIncomeFromContinuingAndDiscontinuedOperation{i}/financialData.totalAssets{i})*100;
  end
end