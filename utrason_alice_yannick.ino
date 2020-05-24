/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/

// defines pins numbers
const int trigPin = 2;
const int echoPin = 3;

// defines variables
long duration;
int distance;

void setup() {
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

Serial.begin(9600); // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.print(distance);

if (distance<7) {
  
  Serial.println("allumer");
  allumer_rouge();
  eteindre_vert();
} else {
  Serial.println("eteindre");
  allumer_vert();
  eteindre_rouge();
}

}

void allumer_rouge() {
  digitalWrite(10, HIGH);
}
void eteindre_rouge() {
  digitalWrite(10, LOW);
}
void allumer_vert() {
  digitalWrite(11, HIGH);
}
void eteindre_vert() {
  digitalWrite(11, LOW);
}
