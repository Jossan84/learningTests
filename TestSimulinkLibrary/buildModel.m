%buildModel
%26/06/2020

% load('ConfigDSPACE.mat');
load('ConfigGeneric.mat');

tic
path = pwd;
buildPath = [path,'\build'];

addpath(path);
addpath(buildPath);

cd(buildPath);

rtwbuild('testSimulinkLibrary')

rmpath(path);
rmpath(buildPath);
toc