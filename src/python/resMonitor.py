import serial
import time
import psutil

ArduinoSerial = serial.Serial('com3', 9600)
time.sleep(5)

cpuUsage = 0

if __name__ == "__main__":
    ArduinoSerial.write("[LOG] Python script initialised!".encode())
    while 1:
        try:
        #print(int(ArduinoSerial.readline()))
        #print('b\'ready\\r\\n\'')
            cpuUsage = psutil.cpu_percent(interval = 1)
            if (int(ArduinoSerial.readline()) == 1):
                try:
                    ArduinoSerial.write(("CPU: " + str(cpuUsage) + "%\nRAM: " + str(psutil.virtual_memory().percent) + "%").encode())
                except:
                    ArduinoSerial.write(("[EXCEPT] Python script: KeyboardInterrupt - connection closed").encode())
                    ArduinoSerial.close()
        except:
            ArduinoSerial.write(("[EXCEPT] Python script: KeyboardInterrupt - connection closed").encode())
            ArduinoSerial.close()
