#include <Arduino.h>

#define GREEN_LED 4
#define YELLOW_LED 3
#define RED_LED 2
#define SWITCH 5

int  switchState;

void setup() {
	switchState = 0;
	pinMode(GREEN_LED, OUTPUT);
	pinMode(YELLOW_LED, OUTPUT);
	pinMode(RED_LED, OUTPUT);
	pinMode(SWITCH, INPUT);
}

void loop() {
	switchState = digitalRead(SWITCH);
	if (switchState == LOW)
	{
		digitalWrite(GREEN_LED, HIGH);
		digitalWrite(YELLOW_LED, LOW);
		digitalWrite(RED_LED, LOW);
	}
	else
	{
		digitalWrite(GREEN_LED, LOW);
		digitalWrite(YELLOW_LED, LOW);
		digitalWrite(RED_LED, HIGH);

		delay(250);

		digitalWrite(YELLOW_LED, HIGH);    
		digitalWrite(RED_LED, LOW);

		delay(250);
	}
}