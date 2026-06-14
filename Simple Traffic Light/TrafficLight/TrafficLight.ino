void setup() {
  // MAKE SURE TO USE 220 OHM RESISTOR WITH LED
  // USE 5V
  // USE GND

  // initializing pins

  int redLightPin = 9;
  int yellowLightPin = 7;
  int greenLightPin = 4;

  pinMode(redLightPin, OUTPUT);
  pinMode(yellowLightPin, OUTPUT);
  pinMode(greenLightPin, OUTPUT);
}

void loop() {

  int redLightPin = 9;
  int yellowLightPin = 7;
  int greenLightPin = 4;
  
  // Red Light
  digitalWrite(redLightPin, HIGH);
  delay(3000);
  digitalWrite(redLightPin, LOW);

  // Yellow Light
  digitalWrite(yellowLightPin, HIGH);
  delay(1000);
  digitalWrite(yellowLightPin, LOW);

  // Red Light
  digitalWrite(greenLightPin, HIGH);
  delay(3000);
  digitalWrite(greenLightPin, LOW);

}
