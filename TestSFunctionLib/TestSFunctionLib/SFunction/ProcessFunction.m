% legacy_code( 'help' )
clc
def = legacy_code('initialize');
%def.SrcPaths = {'..\..\PerceptionSfcn\SharedCodePerception', '..\SharedCodeFunctions'};
def.IncPaths = {'..\libs\mingw32\include'};
%def.IncPaths = {'..\libs\gnu\include'};
%def.IncPaths = {'..\libs\dspace\include'};
def.LibPaths = {'..\libs\mingw32\lib'};
%def.LibPaths = {'..\libs\gnu\lib'};
%def.LibPaths = {'..\libs\dspace\lib'};
def.SourceFiles = {'ProcessFunction.c'};
def.HeaderFiles = {'ProcessFunction.h'};
def.HostLibFiles = {'libmatrix'};
def.TargetLibFiles = {'libmatrix'};
def.SFunctionName = 'SfcnProcessFunction';
%def.InitializeConditionsFcnSpec = 'void ProcessFunctionInit()';
def.OutputFcnSpec = 'void ProcessFunction(double u1[], double u2[], double y1[2], double y2[1])';
legacy_code('sfcn_cmex_generate', def);
legacy_code('compile', def,'-g');
legacy_code('sfcn_tlc_generate', def);