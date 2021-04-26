function Diary(varargin)

    fileStatus = [];
    filename = [];
           
    for i = 1 : 2 : nargin
        switch varargin{i}
            case 'on'
                fileStatus = varargin{i};
            case 'off'
                fileStatus = varargin{i};
            otherwise
                filename = varargin{i};
        end
    end
    
    if strcmp('on', fileStatus)
        if isempty(filename)
            fid = fopen('diary','W','n','utf-8');
        end
    elseif strcmp('off', fileStatus)   
            fid = fopen('all');
            cmdWinDoc = com.mathworks.mde.cmdwin.CmdWinDocument.getInstance;
            txt = char(cmdWinDoc.getText(0,cmdWinDoc.getLength));
            fwrite(fid,txt,'char');
            fclose(fid);
    elseif ~isempty(filename)
        fid = fopen(filename,'W','n','utf-8');
    else
        error('Wrong input argument');
    end
       
end

