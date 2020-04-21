import serial

PORT = "/dev/cu.usbmodem14101"
BAUDRATE = 9600	

ON = 1
OFF = 0

if __name__ == "__main__":
	arduino = serial.Serial(PORT, BAUDRATE)
	arduino.open()
	if arduino.is_open:
		while true:
			state = int(input("Enter the state of the magnet (0 - off, 1 - on) or 69 to turn it off: "))
			if state == 69:
				arduino.close()
				return
			else:
				if state:
					arduino.write((ON).to_bytes(2, byteorder='big'))
				else:
					arduino.write((OFF).to_bytes(2, byteorder='big'))
	else:
		print("ERROR: Could not connect to port: " + PORT)