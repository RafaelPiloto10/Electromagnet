// Magnetconnections
int enA = 9;
int in1 = 8;
int in2 = 7;


void setup() {
	pinMode(enA, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	
	// Turn off  - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
}

void loop() {
	magnetOn();
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

