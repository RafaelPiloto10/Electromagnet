// Magnet connections
int enA = 9;
int in1 = 8;
int in2 = 7;


int buttonPin = 2;	

void setup() {
	Serial.begin(9600);
	pinMode(enA, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);

	pinMode(buttonPin, INPUT);
	
	// Turn off  - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
}

void loop() {
	magnetOn();
	delay(2);
	magnetOff();
	delay(2);
}

void magnetOn(){
	analogWrite(enA, 255);

	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
}

void magnetOff(){
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
}

