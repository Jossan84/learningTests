%TestDiaryReport
%12/02/2021

close all;
clear;
clc;

% TEST 1: diary 
% diary('fichero.txt');
% TEST 2: sldiagviewer 
% sldiagviewer.diary('fichero1.txt','UTF-8');

disp('DON QUIJOTE DE LA MANCHA Miguel de Cervantes Saavedra PRIMERA PARTE')
disp('CAPÍTULO 1: Que trata de la condición y ejercicio del famoso hidalgo D. Quijote de la Mancha')

% diary('off');
% END TEST 1
% sldiagviewer.diary('off');
% END TEST 2

%TEST 3: Workaround
saveCmdWinText_UTF8('fichero2.txt');

