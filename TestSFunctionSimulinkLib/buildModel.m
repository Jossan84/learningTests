%buildModel
%26/06/2020

function buildModel( paths )

    compileSFunction(paths.buildPath, paths.modelPath);
    cd(paths.buildPath);
    rtwbuild('TestSFunctionLib');

end


