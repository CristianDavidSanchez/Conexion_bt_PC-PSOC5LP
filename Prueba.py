import serial
import time

 
puerto   = serial.Serial(port = 'COM9',
                         baudrate = 9600,
                         bytesize = serial.EIGHTBITS,
                         parity   = serial.PARITY_NONE,
                         stopbits = serial.STOPBITS_ONE)
print("Bluetooth connected")
 
while(True):
    cadena = input("Introduce una cadena de texto: ")
    try:
        puerto.write(cadena.encode())
        time.sleep(1)
        #puerto.close()
    except serial.SerialException:
        print('Port is not available') 

    except serial.portNotOpenError:
        print('Attempting to use a port that is not open')
        print('End of script') 