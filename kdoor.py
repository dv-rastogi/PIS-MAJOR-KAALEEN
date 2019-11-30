
import serial
import urllib.request
import time

serial_port = 'COM7';
baud_rate = 9600; #In arduino, Serial.begin(baud_rate)

ser = serial.Serial(serial_port, baud_rate)
a = 0 
while True:
	line = ser.readline();
	line = line.decode("utf-8") #ser.readline returns a binary, convert to string
	line = line[0]
	if a == line:
		url = urllib.request.urlopen('https://kaaleen3.now.sh/set?n=' + str(line))
	str(a) = line






    

