/*
Basic Voltmeter
Khaled Abdul-Baki
August 23, 2026

Description:
This voltmeter is used to measure and display the voltage to the user's serial monitor
in the Arduino IDE.

Given the maximun voltage the allowed on most Arduino boards is 5 volts, the following equation must satisfy:
Voltage_OUT = Voltage_IN * (R2/ (R1 + R2)), solve this equation for Voltage_OUT = 5 and the maximum anticipated
Voltage_IN value to know which resistor values you should use.
The more excess resistance in the circuit, the less accurate the voltage reading is.
The red and green light serve as binary indicators, to display if there is voltage in a given path.


CAUTION:
This voltmeter is NOT in anyway intended for high voltage use.
Checking the voltage of a high voltage appliance may lead to burning the wires, and destroying one's Arduino.

Reference Video:
https://youtu.be/FV0SPRDhAqM?si=akImN5Pa1S4ZpFZI

NOTICE:
Make sure to read the repository README.md Disclaimer before running or experimenting with this code!
*/

float vin;
float vout;

float R1= 220; //from Battery positive to AB
float R2 = 220; //from A0 too Battery ground
float ratio = R2 /(R1 + R2);

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
}

void loop() {
  vin = analogRead(A0); //analogRead can read volages between 0V and 5V and maps those between 0 and 1023
  vout = vin * (5.0 / 1023.0) / ratio; //to get a voltage again we can multiply by 5 and devide by 1023
  
  // Red Light: No voltage
  if(vout < 0.10){
    digitalWrite(2,5);
    digitalWrite(3,0);
  }

  // Green Light: Present Voltage
  else{
    digitalWrite(2,0);
    digitalWrite(3,5);
  }

  // Print out to the serial monitor
  Serial.print("Voltage: ");
  Serial.println(vout);
  delay(300);
}
