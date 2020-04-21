// Magnet connections
int enA = 9;
int in1 = 8;
int in2 = 7;


int buttonPin = 2;
float strength = .8;

void setup() {
	Serial.begin(9600);
	pinMode(enA, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(LED_BUILTIN, OUTPUT);

	pinMode(buttonPin, INPUT);
	
	// Turn off  - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
}

void loop() {
	magnetOn();
	digitalWrite(LED_BUILTIN, HIGH);
	delay(2000);
	magnetOff();
	digitalWrite(LED_BUILTIN, LOW);
	delay(2000);
}

void magnetOn(){
	analogWrite(enA, round(255 * strength));

	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
}

void magnetOff(){
	analogWrite(enA, 0);

	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
}

