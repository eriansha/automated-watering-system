/*
 * Automated Watering System
 * developed by Ivan Putra Eriansya, 2018
 */

const int moisturePin = A0;
const int relayPin = 8;

// TODO: using timer for powering Soil Moisture sensor

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  // Calculate moisture in the plant
  int moistureValue = analogRead(moisturePin);

  // DEBUG: Print its value via serial port
  Serial.print("Soil Moisture: ");
  Serial.println(moistureValue);

  // Turn on pump if moisture is greater than 500
  if(moistureValue > 500)
    digitalWrite(relayPin, HIGH);
   else
    digitalWrite(relayPin, LOW);
}
