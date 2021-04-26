% testTToIntegerAndDecimal.m
% 23/09/2019
% Test conversion from continuous t to positive integer and decimal part [0.0, 1.0]
% 
close all;
clear;
more off;
clc;

addpath('../functions');

if exist('OCTAVE_VERSION', 'builtin') ~= 0% OCTAVE
    markerSize = 12;
    % Compile mex function
    clear tToIntegerAndDecimalC
    mkoctfile --mex '-std=c99' tToIntegerAndDecimalC.c
else% MATLAB
    markerSize = 6;
    % Compile mex function
    %clear tToIntegerAndDecimalC
    mex tToIntegerAndDecimalC.c
end



% Test getPointsBeziers
t_test = [-2.6, 2, 0.4;...
        -1.9, 2, 0.9;...
        -1.3, 2, 0.3;...
        -0.15, 1, 0.15;...
        0, 1, 0;...
       0.2, 1, 0.2;...
       0.9, 1, 0.9;...
       1, 1, 1;...
       1.15, 2, 0.15;...
       2, 2, 1;...
       2.4, 2, 0.6;...
       3.8, 1, 0.2;...
       4.6, 1, 0.6];

t_i = t_test(:, 1);
i_o = t_test(:, 2);
t_o = t_test(:, 3);
maxInteger = 2;

% Run function
[tInt, tDec] = tToIntegerAndDecimal(t_i(1), maxInteger);
% Run C function
[tIntC, tDecC] = tToIntegerAndDecimalC(t_i(1), int16(maxInteger));

[tInt, tIntC]
[tDec, tDecC]