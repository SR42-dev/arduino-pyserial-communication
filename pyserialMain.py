# pyserial code

import serial

Arduino_Serial = serial.Serial('COM9',9600)

def write_read(x):
    x = str(x)
    Arduino_Serial.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = str(Arduino_Serial.readline())
    print(data)

while True :

    incoming_data = str(Arduino_Serial.readline())

    ser.write('f'.encode()) # continually encoding f to secure go ahead

    if 'obstacle' in incoming_data: # obstacle kill
        break

    if cv2.waitKey(1) & 0xFF == ord('q'): # keyboard kill
        break
