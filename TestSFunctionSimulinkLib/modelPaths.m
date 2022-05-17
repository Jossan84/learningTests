function [ paths] = modelPaths()

    paths.modelPath = pwd;
    paths.buildPath = fullfile(paths.modelPath, '\build');
    paths.sFunctionsPath = fullfile(paths.modelPath,'\SFunction');
    paths.libsPath = fullfile(paths.modelPath, '\libs\windowsSDK\lib');
    paths.incluedPath = fullfile(paths.modelPath, '\libs\windowsSDK\include');
%     paths.libsPath = fullfile(paths.modelPath, '\libs\dspace\lib');
%     paths.incluedPath = fullfile(paths.modelPath, '\libs\dspace\include');

end

