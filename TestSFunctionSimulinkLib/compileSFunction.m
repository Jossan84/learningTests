%compileSFunctions
%03/07/2020

function compileSFunction( buildPath , modelPath)

    cd(buildPath);
    
    % Compile ProcessFunction with Legacy Code Tool
    def = legacy_code('initialize');
    def.SrcPaths = {fullfile(modelPath, '\SFunction')};
    def.IncPaths = {fullfile(modelPath, '\libs\windowsSDK\include'), fullfile(modelPath, '\SFunction')};
    def.LibPaths = {fullfile(modelPath, '\libs\windowsSDK\lib')};
    def.SourceFiles = {'ProcessFunction.c'};
    def.HeaderFiles = {'ProcessFunction.h'};
    def.HostLibFiles = {'sumDouble_rtwlib'};
    def.TargetLibFiles = {'sumDouble_rtwlib'};
    def.SFunctionName = 'SfcnProcessFunction';
    def.InitializeConditionsFcnSpec = 'void ProcessFunctionInit()';
    def.OutputFcnSpec = 'void ProcessFunction(double u1[1], double u2[1], double y1[2], double y2[1])';
    legacy_code('sfcn_cmex_generate', def);
    legacy_code('compile', def,'-g');
    legacy_code('sfcn_tlc_generate', def);
    legacy_code('rtwmakecfg_generate', def)

end

