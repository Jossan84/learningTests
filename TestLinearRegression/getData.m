
close all
clc

addpath('Z:/Workspace/Tools/Library/Linear Regression/data');

load('sigle_track_trajectorie.mat');

%% Get Features to the Single Track Model
%  Features:
%  [vy]    =  lateral velocity [m/s]
%  [vx]    =  longitudinal velocity [m/s]
%  [phi]   =  yaw rate  [rad/s]
%  [delta] =  wheel angle [rad]  (steering wheel angle * 1/steering ratio)
%  [d_vy]  =  vy(k) - vy(k-1)
%  [d_phi] =  phi(k) - phi(k-1)
%  [t]     =  time [s]

d_vy  = [diff(vy(1:end-1)) ,0,0];  % ?????
d_phi = [diff(phi(1:end-1)),0,0];  % ?????

x1 = vy./vx ;
x2 = phi./vx;
x3 = vx.*phi;
x4 = delta;
y1 = d_vy;
y2 = d_phi;

x1 = x1';
x2 = x2';
x3 = x3';
x4 = x4';
y1 = y1';
y2 = y2';

[m n] = size(x1);

X1 = [x1(:,1), x2(:,1), x3(:,1), x4(:,1)];
X2 = [x1(:,1), x2(:,1), x4(:,1)];

X1 = [ones(m, 1) X1];
X2 = [ones(m, 1) X2];

