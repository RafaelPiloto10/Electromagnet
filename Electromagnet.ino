// Magnet connections
int enA = 9;
int in1 = 8;
int in2 = 7;


float strength = .8;
bool magnetState = false;

int timeON = 2000;
int timeOFF = 2000;

void setup() {
	Serial.begin(9600);
	pinMode(enA, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(LED_BUILTIN, OUTPUT);

	
	// Turn off  - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
}

void loop() {
	if(Serial.available() > 0){
		int command = Serial.read() - '0';
		if(command == 1){
			magnetState = true;
		} else if(command == 0){
			magnetState = false;
		}
	} else {
	}

	if(magnetState){
		magnetOn();
	} else {
		magnetOff();
	}
}

void magnetOn(){
	analogWrite(enA, round(255 * strength));
	magnetState = true;
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(LED_BUILTIN, HIGH);
}	

void magnetOff(){
	analogWrite(enA, 0);
	magnetState = false;
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(LED_BUILTIN, LOW);
}

