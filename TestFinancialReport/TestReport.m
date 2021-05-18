% TestReport
% 17/05/2021

close all;
clear;
clc;

% Load io package to use xlsread()
pkg load io


fileName = 'financialReport20210517.xlsx';
sheet = 'Sheet1';

[numArr, txtArr, rawArr, limits] = xlsread(fileName, sheet);