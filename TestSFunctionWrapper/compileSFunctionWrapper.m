%compileSFunctionWrapper
%23/03/2020

%Note:
%       Use a MEX S-function wrapper only in the 
%       MATLAB® version in which you created the wrapper.

%Appreciations: 
%       This method is alternative to Legacy Code Tool
%       Writing the .tlc we reduce the overhead of generate initializtions
%       of SimStruct if we have more than one calls to the wrapper into the
%       model.

% Generate mex file
mex wrapsfcn.c
