%testGenerateCFile
%30/01/2020

%  readID=fopen('XYZ.c','r');
%  writeID=fopen('NEW.c','w');
%  fprintf(writeID,'%s\n','XYZ');
%  fwrite(writeID,fread(readID));
%  fclose(readID);
%  fclose(writeID);

% Create the file    
  writeID=fopen('file.c','w');
  
  