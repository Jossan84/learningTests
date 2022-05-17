%testFilter
%31/10/2019

close all;
clear;
clc;  

% Simulation Parameters
tInit=0;
tEnd = 5;
T=0.0025;

t=tInit:T:tEnd;  %time vector [s]

options=odeset('RelTol',1e-3,'InitialStep',2.5e-3,'MaxStep',2.5e-3);

[t,x]=ode45('firstOrderFilter',t,0,options);

u = 5 * sin(t);
uNoise= u + random('Normal',t,t);

% Plots
figure;
plot(t,uNoise,'b.-');
hold on;
plot(t,u,'k.-');
plot(t,x,'r.-');
xlabel('Time [s]');
ylabel('Signal []');
legend('uNoise','u','uFiltered','Location','NorthWest');
