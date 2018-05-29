/*
 * Automated Watering System
 * developed by Ivan Putra Eriansya, 2018
 */

// Define constant
const int moisturePin = A0;
const int relayPin = 8;
const int power = 12;

// Define timer for powering soil moisture sensor
const int TIMER = 60; // in seconds
const int RESET = TIMER - 1;
const int SENSOR_DELAY = 10; // in miliseconds
int counter;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  pinMode(power, OUTPUT);

  // Start with sensor OFF
  digitalWrite(power, LOW);

  // Setup timer
  counter = RESET;
}

void loop() {
  if(counter <= 0) {
    // Turn on Sensor and wait a moment
    digitalWrite(power, HIGH);
    delay(SENSOR_DELAY);
  
    // Calculate moisture in the plant
    int moistureValue = analogRead(moisturePin);

    // Watering the plant
    WateringPlant(moistureValue);
    
    // turn sensor OFF again
    digitalWrite(power, LOW);
    
    // Start new countdown
    counter = RESET;
  }
  else
    delay(SENSOR_DELAY);
  
  // Decrement counter and delay until next second
  counter--;
  delay(1000 - SENSOR_DELAY);

  // DEBUG: print counter from 5 second
  if(counter <= 5) {
    Serial.print("Counter: ");
    Serial.println(counter);
  }
}

void WateringPlant(int moistureValue) {
  // Watering plant if moisture valus is greater than 500
  while(moistureValue > 500) {
    // continue when relay is still ON
    if(relayPin == HIGH)
      continue;

    // DEBUG: Print its value via serial port
    Serial.print("Soil Moisture: ");
    Serial.println(moistureValue);
    
    // turn ON relay
    digitalWrite(relayPin, HIGH);
  }
  
  // turn OFF relay
  digitalWrite(relayPin, LOW);
}
