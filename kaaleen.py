
import serial
import urllib.request
import time

serial_port = 'COM6';
baud_rate = 9600; #In arduino, Serial.begin(baud_rate)

ser = serial.Serial(serial_port, baud_rate)
arr = ['0','0']
count =0 
while True:
	if count!=0:
		b = a 
	else:
		b = '0'
	count+=1
	line = ser.readline();
	line = line.decode("utf-8") #ser.readline returns a binary, convert to string
	line = line[0]
	if line!='\r':
		arr.append(line)
	print(arr[-1],arr[-2])
	
	if (arr[-2]=='0' and arr[-1]=='1') or (arr[-1]=='0' and arr[-2]=='1'):
		a = str(1)
	elif (arr[-2]=='0' and arr[-1]=='2') or (arr[-1]=='0' and arr[-2]=='2'):
		a = str(2)
	elif (arr[-2]=='1' and arr[-1]=='2') or (arr[-1]=='1' and arr[-2]=='2'):
		a = str(3)
	elif (arr[-2]=='0' and arr[-1]=='3') or (arr[-1]=='0' and arr[-2]=='3'):
		a = str(3)
	elif (arr[-2]=='0' and arr[-1]=='0') or (arr[-1]=='0' and arr[-2]=='0'):
		a = str(0)

	if not(a == b):
		url = urllib.request.urlopen('https://kaaleen.now.sh/set?n=' + a)







    

