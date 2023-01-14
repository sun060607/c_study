#include <Arduino.h>
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>
//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"
#include <ESP32_Servo.h>
// Insert your network credentials
#define WIFI_SSID "bssm_free"
#define WIFI_PASSWORD "bssm_free"

// Insert Firebase project API Key
#define API_KEY "AIzaSyDLrpRoxpxUZULsRfT4U8FeKKdoCLfFVkM"

// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "https://gesture-d7295-default-rtdb.firebaseio.com" 
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;     
int Volume1;
int Play1;
int Switch1;
int Kon1;
bool signupOK = false;
int num = 0;
int Red1;
int Blue1;
int Green1;
int Red2 = 21;
int Blue2 = 23;
int Green2 = 22;
int num2=0;
static const int servoPin = 13;
Servo servo1;

void setup() {
  Serial.begin(115200);
  servo1.attach(servoPin); 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("ok");
    signupOK = true;
  }
  else {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }
  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
  pinMode(Red2,OUTPUT);
  pinMode(Green2,OUTPUT);
  pinMode(Blue2,OUTPUT);
}

void loop() {
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 1000 || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();
    if (Firebase.RTDB.getInt(&fbdo, "/Color")) {
      if (fbdo.dataType() == "int") {
        Play1 = fbdo.intData();
        Serial.print("Color");
        Serial.println(Play1);
      }
    }
    if (Firebase.RTDB.getFloat(&fbdo, "/Switch")) {
      if (fbdo.dataType() == "int") {
        Switch1 = fbdo.floatData();
        Serial.print("Switch1");
        Serial.println(Switch1);
      }
    }
    if (Firebase.RTDB.getFloat(&fbdo, "/Kon")) {
      if (fbdo.dataType() == "int") {
        Kon1 = fbdo.floatData();
        Serial.print("Kon1");
        Serial.println(Kon1);
      }
    }
    if (Firebase.RTDB.getFloat(&fbdo, "/Blue")) {
      if (fbdo.dataType() == "int") {
        Blue1 = fbdo.floatData();
        Serial.print("Blue");
        Serial.println(Blue1);
      }
    }
    if (Firebase.RTDB.getFloat(&fbdo, "/Red")) {
      if (fbdo.dataType() == "int") {
        Red1 = fbdo.floatData();
        Serial.print("Red");
        Serial.println(Red1);
      }
    }
    if (Firebase.RTDB.getFloat(&fbdo, "/Green")) {
      if (fbdo.dataType() == "int") {
        Green1 = fbdo.floatData();
        Serial.print("Green");
        Serial.println(Green1);
      }
    }
    else {
      Serial.println(fbdo.errorReason());
    }
  }
  if(Kon1==1){
    if(num2==0){
      for(int angle = 0; angle < 90; angle++) { 
        servo1.write(angle); 
        delay(15); 
      }
      num2=1;
    }
  }else if(Kon1==0){
    if(num2==1){
      for(int angle = 90; angle > 0; angle--) { 
        servo1.write(angle); 
        delay(15); 
      }
    }
    num2=0;
  }
  if(Switch1==0){
    digitalWrite(Red2, LOW);
    digitalWrite(Blue2, LOW);
    digitalWrite(Green2, LOW);
  }
  else if(Play1 == 0){
    digitalWrite(Red2, HIGH);
    digitalWrite(Blue2, HIGH);
    digitalWrite(Green2, HIGH);
  }else{
    if(Red1==1){
      digitalWrite(Red2, HIGH);
    }else{
      digitalWrite(Red2, LOW);
    }
    if(Blue1==1){
      digitalWrite(Blue2, HIGH);
    }else{
      digitalWrite(Blue2, LOW);
    }
    if(Green1==1){
      digitalWrite(Green2, HIGH);
    }else{
      digitalWrite(Green2, LOW);
    }
  }
}
