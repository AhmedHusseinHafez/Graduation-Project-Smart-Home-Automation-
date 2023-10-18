#include "DHT.h"

#include <Servo.h>

Servo servoDoor;
Servo servoWindow;

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "iotfinalproject-d6593-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "bwXi9VgdhlTJzlhUi4YREg2rrA8BXK3BT0FMNJfw"
#define WIFI_SSID "~:Ahmed:~"
#define WIFI_PASSWORD "@siu77771162001"

#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE); 


int ENA = 016;
int IN1 = 05;
int IN2 = 04;

void setup() {
  Serial.begin(9600);
  
//  pinMode(12,OUTPUT);
//  pinMode(14,OUTPUT);
  
  Serial.begin(115200);

    
  dht.begin();
  Serial.println(F("Init....")) ;

  servoDoor.attach(00); //D3
  //servoDoor.write(0);

  servoWindow.attach(15); //D8
  //servoWindow.write(0);


  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT); 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
 delay(0);


  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

  bool fan;
  bool HomeDoor;
  bool WindowDoor;
  bool HomeLightOne;
  bool HomeLightTwo;
  
  void loop() {

  float h = dht.readHumidity();                                 // Read Humidity
  float t = dht.readTemperature();                              // Read temperature

  Serial.print("Humidity: ");
  Serial.print(h);
  
  Serial.print("% Temperature: ");
  Serial.print(t);
  Serial.println("°C ");

  Firebase.setFloat("DHT11part1/Temp",t);        
  Firebase.setFloat("DHT11part2/Humidity",h);
  delay(500);    
  
  

    
  setDirection();
  delay(1000);
  changeSpeed();
  delay(1000);
  
   fan = Firebase.getBool("fan/Switch");
   Serial.print("fan: ");
   Serial.println(fan);
  if (fan == true) {
  analogWrite(ENA, 255);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //delay(5000);
  }
  if (fan == false) {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW); 
  }
//    delay(500);



   HomeDoor = Firebase.getBool("HomeDoor/Switch");
   Serial.print("HomeDoor: ");
   Serial.println(HomeDoor);
  if (HomeDoor == false) {
    servoDoor.write(90);
    delay(500);
  
  }
  if (HomeDoor== true) {
    servoDoor.write(0);
    delay(500);
  }
//    delay(500);

   WindowDoor = Firebase.getBool("WindowDoor/Switch");
   Serial.print("WindowDoor: ");
   Serial.println(WindowDoor);
  if (WindowDoor == false) {
    servoWindow.write(90);
    delay(500);
  
  }
  if (WindowDoor== true) {
    servoWindow.write(0);
    delay(500);
  }
//    delay(500);


//  HomeLightOne = Firebase.getBool("HomeLightOne/Switch");
//  Serial.print("HomeLightOne: ");
//  Serial.println(HomeLightOne);
//  if (HomeLightOne == true) {
//    digitalWrite(12, HIGH);
//  }
//  if (HomeLightOne == false) {
//    digitalWrite(12, LOW);
//  }
//   delay(500);
//
//  HomeLightTwo = Firebase.getBool("HomeLightTwo/Switch");
//  Serial.print("HomeLightTwo: ");
//  Serial.println(HomeLightTwo);
//  if (HomeLightTwo == true) {
//    digitalWrite(14, HIGH);
//  }
//  if (HomeLightTwo == false) {
//    digitalWrite(14, LOW);
//  }
//    delay(500);
    }

  void setDirection() {
  analogWrite(ENA, 255);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(5000);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(5000);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void changeSpeed() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
  for (int i = 0; i < 256; i++) {
    analogWrite(ENA, i);
    delay(20);
  }
  
  for (int i = 255; i >= 0; --i) {
    analogWrite(ENA, i);
    delay(20);
  }
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
