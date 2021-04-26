%script.m
%08/04/2020

%% Create .txt [Not probed]
% fid = fopen( 'results.txt', 'wt' );
% 
% fprintf( fid, '%f\n', 1);
% 
% fclose(fid);

%% Pass system variable [Not work]
%cmd = sprintf('alpha=%d beta=%d ls | head -$beta | tail -$alpha', alpha, beta);
%system(cmd);

%% Print in command window and use -logfile option in .sh
disp('Build successful')
