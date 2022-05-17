%bussesDefinition
%30/01/2020

function bussesDefinition()
    % Bus1
    clear elems;
    elems(1) = Simulink.BusElement;
    elems(1).Name = 'num1';
    elems(1).Dimensions = 1;
    elems(1).DimensionsMode = 'Fixed';
    elems(1).DataType = 'double';
    elems(1).SampleTime = -1;
    elems(1).Complexity = 'real';

    elems(2) = Simulink.BusElement;
    elems(2).Name = 'num2';
    elems(2).Dimensions = 1;
    elems(2).DimensionsMode = 'Fixed';
    elems(2).DataType = 'double';
    elems(2).SampleTime = -1;
    elems(2).Complexity = 'real';

    Bus1 = Simulink.Bus;
    Bus1.Elements = elems;
    assignin('base','Bus1', Bus1);
    
    % Bus2
    clear elems;
    elems(1) = Simulink.BusElement;
    elems(1).Name = 'num1';
    elems(1).Dimensions = 1;
    elems(1).DimensionsMode = 'Fixed';
    elems(1).DataType = 'double';
    elems(1).SampleTime = -1;
    elems(1).Complexity = 'real';

    elems(2) = Simulink.BusElement;
    elems(2).Name = 'num2';
    elems(2).Dimensions = 1;
    elems(2).DimensionsMode = 'Fixed';
    elems(2).DataType = 'double';
    elems(2).SampleTime = -1;
    elems(2).Complexity = 'real';

    elems(3) = Simulink.BusElement;
    elems(3).Name = 'num3';
    elems(3).Dimensions = 1;
    elems(3).DimensionsMode = 'Fixed';
    elems(3).DataType = 'double';
    elems(3).SampleTime = -1;
    elems(3).Complexity = 'real';

    Bus2 = Simulink.Bus;
    Bus2.Elements = elems;
    assignin('base','Bus2', Bus2);

    clear elems

end
