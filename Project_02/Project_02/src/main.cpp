#include <Arduino.h>

#define SENSOR_PIN A5
#define BASELINE_TEMP 20.0
#define RED_PIN 13
#define YELLOW_PIN 12
#define GREEN_PIN 11

void	active_lights(float temperature)
{
	if (temperature < BASELINE_TEMP + 2)
	{
		digitalWrite(RED_PIN, LOW);
		digitalWrite(YELLOW_PIN, LOW);
		digitalWrite(GREEN_PIN, LOW);
	}
	else if (temperature >= BASELINE_TEMP + 2 && temperature < BASELINE_TEMP + 4)
	{
		digitalWrite(RED_PIN, LOW);
		digitalWrite(YELLOW_PIN, LOW);
		digitalWrite(GREEN_PIN, HIGH);
	}
	else if (temperature >= BASELINE_TEMP + 4 && temperature < BASELINE_TEMP + 6)
	{
		digitalWrite(RED_PIN, LOW);
		digitalWrite(YELLOW_PIN, HIGH);
		digitalWrite(GREEN_PIN, HIGH);
	}
	else
	{
		digitalWrite(RED_PIN, HIGH);
		digitalWrite(YELLOW_PIN, HIGH);
		digitalWrite(GREEN_PIN, HIGH);
	}
}

void	setup()
{
	Serial.begin(9600);
	for (int pin_number = RED_PIN; pin_number >= GREEN_PIN; pin_number--)
	{
		pinMode(pin_number, OUTPUT);
		digitalWrite(pin_number, LOW);
	}
}

void	loop()
{
	int		_sensor_value;
	float	_voltage;
	float	_temperature;

	_sensor_value = analogRead(SENSOR_PIN);
	Serial.print("Sensor value : ");
	Serial.print(_sensor_value);

	_voltage = (_sensor_value / 1024.0) * 5.0;
	Serial.print(", volts : ");
	Serial.print(_voltage);

	_temperature = (_voltage - 0.5) * 100;
	Serial.print(", degrees C : ");
	Serial.println(_temperature);

	active_lights(_temperature);
	delay(1);
}
