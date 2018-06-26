# Psychtoolbox-to-Brain-Products-Marker

Software required to make an Arduino interface for transmitting markers from Psychtoolbox to Brain Products "Recorder" software via the BrainAmp EEG USB adapter.

This solution is designed to work best with an Arduino Micro or Arduino Leonardo as both of these have an integrated USB controler leading to a lower latency connection between MATLAB and the EEG recording hardware other Arduino's should work though. In addition to this software a small amount of hardware will be needed. A 25 pin D-Sub connector should be soldered onto the Arduino as shown in the table below.

| Function  | Parallel Connector Pin | Arduino Pin |
|-----------|------------------------|-------------|
| Ground    | 25                     | GND         |
| S1        | 2                      | D2          |
| S2        | 3                      | D3          |
| S4        | 4                      | D4          |
| S8        | 5                      | D5          |
| S16       | 6                      | D6          |
| S32       | 7                      | D7          |
| S64       | 8                      | D8          |
| Debug LED | N/A                    | D13         |
