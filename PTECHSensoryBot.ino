#include <DHT.h>
#include <NewPing.h>

#define TRIGGER_PIN 11
#define ECHO_PIN 10
#define MAX_DISTANCE 500

#define DHTPIN 9     // what pin we're connected to for temp
#define DHTTYPE DHT11   // DHT 11 tye of temp sensor
DHT dht(DHTPIN, DHTTYPE);

int motorPinA = 3;
int motorPinB = 4;
int gasPin = 7;
int gasPinRead = 0;
int lightPin = 0;  //define a pin for Photo resistor
int lightPinRead = 0;
int tiltPin = 6; //buttonpin
int tiltPinRead = 0; //buttonstate
int ultrasonicDistanceCM = 300;
//  int f2 = 0;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

void setup() {
//   Serial.begin(9600); 
//   Serial.begin(115200); 
 pinMode(motorPinA, OUTPUT);
  pinMode(motorPinB, OUTPUT);
  pinMode(gasPin, INPUT);
pinMode(tiltPin, INPUT);
pinMode(13, OUTPUT);
digitalWrite(13, LOW);
digitalWrite(12, LOW);

  Serial.begin(9600); 
  Serial.println("DHTxx test!");
   dht.begin();
}


void loop() {
//  digitalWrite(motorPinB, LOW);
//  digitalWrite(motorPinA, LOW);
//
////  delay(1000);
//  digitalWrite(motorPinB, HIGH);
//  digitalWrite(motorPinA, HIGH);


// digitalWrite(motorPinB, LOW);
//  digitalWrite(motorPinA, LOW);
gasPinRead = digitalRead(gasPin);
//int gasReadValue = digitalRead(gasPin);

lightPinRead =  analogRead(lightPin);
//int lightReadValue = analogRead(lightPin);

tiltPinRead = digitalRead(tiltPin);
//int tiltReadValue = digitalRead(tiltPin);

//delay(50); 
int uS = sonar.ping();
//Serial.print("Ping: ");
//Serial.print(uS / US_ROUNDTRIP_CM); 
//Serial.println("cm");

ultrasonicDistanceCM = uS / US_ROUNDTRIP_CM;
//int distanceReadValue = uS / US_ROUNDTRIP_CM;
//Serial.println(distanceReadValue);



  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);
//  f2 = f + 1;
  
   Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: "); 
//  Serial.print(t);
//  Serial.print(" *C ");
  Serial.print(f);
  Serial.print("Temp limit: "); 
//    Serial.print(f2);
  Serial.print(" *F\t");
//  Serial.print("Heat index: ");
//  Serial.print(hi);
  Serial.println(" *F");

   Serial.print("Air safety: "); 
Serial.println(gasPinRead);
   Serial.print("Light intensity: "); 
Serial.println(lightPinRead );
   Serial.print("Sonar object detection: "); 
Serial.println(ultrasonicDistanceCM);
   Serial.print("Tilt Condition: "); 
Serial.println(tiltPinRead);
//Serial.print(f);
//Serial.print(h);
delay(1000);
//if (gasReadValue < 1 || lightReadValue <125 || distanceReadValue <3 || f>80 || h>26)
if (gasPinRead = 1 && lightPinRead > 125 && ultrasonicDistanceCM > 3)
{
  //environment is okay to go!
digitalWrite(13, LOW);  //red
digitalWrite(12, HIGH);  //green
  digitalWrite(motorPinB, HIGH);
  digitalWrite(motorPinA, HIGH);
delay(1500);  
digitalWrite(motorPinB, LOW);
  digitalWrite(motorPinA, LOW);
delay(250);  

}
//int f2 = f + 2

//else if (f > f2)
//{
//   //environmental temp issues detected!!
//  digitalWrite(13, HIGH); //red
//    digitalWrite(12, LOW); //green
//  digitalWrite(motorPinB, LOW);
//  digitalWrite(motorPinA, LOW);
//delay(5000); 
//  
//}
else
{
 //environmental issues detected!!
  digitalWrite(13, HIGH); //red
    digitalWrite(12, LOW); //green
  digitalWrite(motorPinB, LOW);
  digitalWrite(motorPinA, LOW);
delay(5000);  

}




  
// digitalWrite(motorPinA, LOW);
// delay(1000);



}
