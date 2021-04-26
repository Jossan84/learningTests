%TestGenerateMatlabScript.m
%02/11/2020

close all;
clear;
clc;

addpath('functions');

config = struct;
config.a = 25;
config.b = 25;
config.c = 25;
config.d = 25;

dlmwrite('configuration.m',char(gencode(config)),'delimiter','');

rmpath('functions');