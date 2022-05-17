%modelParameters
%02/07/2020

% Model paths
paths = modelPaths();

addpath(paths.modelPath);
addpath(paths.buildPath);
addpath(paths.sFunctionsPath);
addpath(paths.incluedPath);
addpath(paths.libsPath);

% Model configuration
load(fullfile(paths.modelPath, 'config/ConfigGeneric.mat'));

% Compile Sfunction
compileSFunction(paths.buildPath, paths.modelPath);

%rmpath(modelPath);
%rmpath(buildPath);
