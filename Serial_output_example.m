% USB to Brain Products BrainAmp adapter example script
% Test output of makers S1 - S127

% Using psyctoolbox IOPort, open a serial port pointing at the adapter
% (found using windows device manager) at a specified number of bits per
% second and input buffer size. This port is now associated with the handle
% adapter. Any error messages will be output to errmsg.
[adapter, errmsg] = IOPort('OpenSerialPort', ...
                           'COM8', ...
                           ['BaudRate=128000', 'InputBufferSize=4096']);

% Cycle through generating one of each marker                       
for marker = 1:(2^7)-1
    
    % Make string to be sent to serial device. This string should be the
    % ID number of the marker you want to output followed by a none number
    % character, in this case a comma. If the string doesn't end with a
    % none number character the marker will be output roughly 1000 ms later
    % then intended.
    outputstring = strcat(num2str(marker), ',');
    
    % Write the string to the adapter.
    IOPort('Write', adapter, outputstring);
    
    % Pause for 100 ms before looping again. It is not recommended that
    % this method of pausing is used for time sensitive experiments, it is
    % used here for convenience.
    pause(0.1)    
end

% Close the serial port to allow it to be used by other processes.
IOPort('Close', adapter);