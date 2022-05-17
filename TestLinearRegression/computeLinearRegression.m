
close all
clc

addpath('Z:/Workspace/Tools/Library/Linear Regression/functions');

getData;

%% Single Track Model for Linear Regression 
%  Single Track Model Continuous
%    A=[ -(c1 + c2)/(m*vx(i)),      - vx(i) - (a*c1 - b*c2)/(m*vx(i));
%        -(a*c1 - b*c2)/(J*vx(i)),  -(c1*a^2 + c2*b^2)/(J*vx(i))    ];

%    B=[c1/m (a*c1)/J]';

%  Single Track Model Parametrization
%  A = [a11 a12
%       a21 a22] 
%  B = [b1
%       b2]
%  X = [vy
%       phi]
%  
%  State-Space Model
%  A*X + B*delta

% Extract two ecuations from State-Space Model
% d_vy  =  (-(c1 + c2)/(m))*vy/vx + (- (a*c1 - b*c2)/(m*vx(i))*(phi/vx) +
%          (-1)*(vx*phi) + (c1/m)*delta
% d_phi =  (-(a*c1 - b*c2)/(J)) * vy/vx + (-(c1*a^2 + c2*b^2)/J) *
%          (phi/vx)+ ((a*c1)/J) * delta

% Parametrization off two equations
% y1 = theta0 + theta1*x1 + theta2*x2 + theta3*x3 + theta4*x4
% y2 = theta0 + theta1*x1 + theta2*x2 + theta3*x3

%% Compute Linear Regression
Theta1 = [0;0;0;0];
Theta2 = [0;0;0];

% Calculate the parameters for first equation of Single Track Model 
% with the Normal Equation
Theta1 = normalEqn(X1, y1);

% Calculate the parameters for second equation of Single Track Model 
% with the Normal Equation
Theta2 = normalEqn(X2, y2);

%% Display Parameters
%  Display Sigle Track Model parameters
a11 = Theta1(2);
a12 = Theta1(3) + Theta1(4);
a21 = Theta2(2);
a22 = Theta2(3);
b1  = Theta1(5);
b2  = Theta2(4);

A = [a11, a12; a21, a22];
B = [b1, b2];

fprintf('Single Track Model: \n');
fprintf('A: \n');
fprintf('a11 = %f \n', a11);
fprintf('a12 = %f \n', a12);
fprintf('a21 = %f \n', a21);
fprintf('a22 = %f \n', a22);

fprintf('B: \n');
fprintf('b1 = %f \n', b1);
fprintf('b2 = %f \n', b2);

fprintf('\n');

