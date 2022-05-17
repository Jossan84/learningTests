
close all
clc

%% Get Data
getData;

%% Plot Data

fig = figure;
plot(t,vy,'b.-');
xlabel('Time [s]');
ylabel('[m/s]');
title('Lateral velocity');
grid on

fig = figure;
plot(t,vx,'b.-');
xlabel('Time [s]');
ylabel('[m/s]');
title('Longitudinal velocity');
grid on

fig = figure;
plot(t,phi,'b.-');
xlabel('Time [s]');
ylabel('[rad/s]');
title('Yaw Rate');
grid on

fig = figure;
plot(x_G,y_G,'b.-');
xlabel('x [m]');
ylabel('y [m]');
title('Trajectory');
grid on

fig = figure;
plot(t,90-rad2deg(yaw_G),'b.-');
xlabel('Time [s]');
ylabel('[deg]');
title('Heading');
grid on

fig = figure;
plot(t,rad2deg(delta),'b.-');
xlabel('Time [s]');
ylabel('[deg]');
title('Wheel angle');
grid on



