import serial

PORT = '/dev/cu.usbmodem14101'
BAUDRATE = 9600	

ON = '1'
OFF = '0'

if __name__ == "__main__":
	arduino = serial.Serial(PORT, BAUDRATE)
	if arduino.is_open:
		while True:
			state = int(input("Enter the state of the magnet (0 - off, 1 - on) or 9 to turn it off: "))
			if state == 9:
				arduino.close()
				break
			else:
				if state:
					arduino.write(str.encode(ON))
				else:
					arduino.write(str.encode(OFF))
	else:
		print("ERROR: Could not connect to port: " + PORT)