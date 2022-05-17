%testLauncher
%30/01/2020

%% Add to to path build folder
% Model route
this_model = pwd;
backslash_index = strfind( this_model, '\' );

% Add build folder to the project
buildPath = [this_model,'\buildFiles'];
addpath(buildPath);

% Model Busses
bussesDefinition();

% Open model
open_system('testSFunctionBuilder.slx');

% Move to build folder
cd(buildPath);

%rmpath([this_model,'\buildFiles']);
clear this_model backslash_index buildPath
