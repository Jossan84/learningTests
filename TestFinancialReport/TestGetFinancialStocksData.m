% TestGetFinancialStocksData
% 21/05/2021

close all;
clear;
clc;

% Load io package to use xlsread()
pkg load io

addpath('functions');

financialFile = 'data/financialReport20210517.xlsx';
stockPriceFile = 'data/stockPricesData20210518.xlsx';
stockInfoFile = 'data/stockInfo20210521.xlsx';

financialData = getFinancialStocksData('financialFile', financialFile, 'stockPriceFile', stockPriceFile, 'stockInfoFile', stockInfoFile);

##ratios = getRatios(financialData);

rmpath('functions');
clearvars financialFile stockPriceFile stockInfoFile