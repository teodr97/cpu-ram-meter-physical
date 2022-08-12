# cpu-ram-meter-physical
A little program which connects to an Arduino Nano which in turn has to be connected to an LCD display. It polls CPU and RAM usage data from the PC in real time and displays percentages, as well as a usage graph for the CPU, on the LCD display.

# How to use 
Make sure the Arduino Board is connected to both the PC and an LCD display.
1. Load the Arduino program on your Arduino Nano.
  - You may use other boards too if you wish, but you will have to make some changes to the project config as it is configured to work on the Nano board.
2. Start the Python program through IDLE or any other Python interpreter.
  - Make sure to run the Python program first before powering up the Arduino board, otherwise the program will NOT work.

And done! The program should now begin displaying real-time CPU and RAM usage on the LCD display.

# Copyright / License
This program operates under the Creative Commons BY-NC-SA licence. You may use and modify it for your own purposes, but you may not use it commercially.
