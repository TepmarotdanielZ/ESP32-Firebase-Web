
#include <Arduino.h>
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>

/* PROVIDE THE TOKEN GENERATION PROCESS INFO */
#include "addons/TokenHelper.h"
/*  PROVIDE THE RTDB PAYLOAD PRINTING INFO AND OTHER HELPER FUNCTIONS */ 
#include "addons/RTDBHelper.h"

/* INSERT YOUR NETWORK CREDENTIALS */ 
#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

/* INSERT FIREBASE PROJECT API KEY */ 
#define API_KEY "YOUR_API_KEY"

/* INSERT AUTHORIZED EMAIL AND CORRESPONDING PASSWORD */ 
#define USER_EMAIL "YOUR_EMAIL"
#define USER_PASSWORD "YOUR_EMAIL_PASSWORD"

#define DATABASE_URL "YOUR_DATABASE_URL"

/* DEFINE FIREBASE OBJECTS */ 
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

/* VARIABLE TO SAVE USER UID */ 
String uid;

/* VARIABLES TO SAVE DATABASE PATHS */ 
String databasePath;
String tempPath;
String humPath;
String presPath;
String ledPath;

float temperature;
float humidity;
float pressure;
const int led = 13; /* LED PIN */ 

/* TIMER VARIABLES (SEND NEW READINGS EVERY 2 SECONDS) */ 
unsigned long sendDataPrevMillis = 0;
unsigned long timerDelay = 200;

// Initialize WiFi
void initWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
  Serial.println();
}

/* WRITE FLOAT VALUES TO THE DATABASE */ 
void sendFloat(String path, float value) {
  if (Firebase.RTDB.setFloat(&fbdo, path.c_str(), value)) {
    Serial.print("Writing value: ");
    Serial.print(value);
    Serial.print(" on the following path: ");
    Serial.println(path);
    Serial.println("PASSED");
    Serial.println("PATH: " + fbdo.dataPath());
    Serial.println("TYPE: " + fbdo.dataType());
  }
  else {
    Serial.println("FAILED");
    Serial.println("REASON: " + fbdo.errorReason());
  }
}

/* READ LED STATE FROM FIREBASE */ 
void readData(String path) {
  String readIncoming = "";
  if (Firebase.RTDB.getString(&fbdo, path.c_str())) {
    Serial.println("PATH: " + fbdo.dataPath());
    Serial.println("TYPE: " + fbdo.dataType());
    if (fbdo.dataType() == "string") {
      readIncoming = fbdo.stringData();
      Serial.println("DATA: " + readIncoming);
      if (readIncoming == "ON") {
        digitalWrite(led, HIGH);   /* TURN LED ON */ 
      }
      else {
        digitalWrite(led, LOW);    /* TURN LED OFF */ 
      }
    }
  }
  else {
    Serial.println("FAILED");
    Serial.println("REASON: " + fbdo.errorReason());
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  initWiFi();

  /* ASSIGN THE API KEY */ 
  config.api_key = API_KEY;

  /* ASSIGN THE USER SIGN IN CREDENTIALS */ 
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  /* ASSIGN THE RTDB URL */ 
  config.database_url = DATABASE_URL;

  Firebase.reconnectWiFi(true);
  fbdo.setResponseSize(4096);

  /* ASSIGN THE CALLBACK FUNCTION FOR THE LONG RUNNING TOKEN GENERATION TASK */ 
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  /* ASSIGN THE MAXIMUM RETRY OF TOKEN GENERATION */ 
  config.max_token_generation_retry = 5;

  /* INITIALIZE THE LIBRARY WITH THE FIREBASE AUTHEN AND CONFIG */ 
  Firebase.begin(&config, &auth);

  /* GETTING THE USER UID MIGHT TAKE A FEW SECONDS */ 
  Serial.println("Getting User UID");
  while ((auth.token.uid) == "") {
    Serial.print('.');
    delay(1000);
  }
  /* PRINT USER UID */ 
  uid = auth.token.uid.c_str();
  Serial.print("User UID: ");
  Serial.println(uid);

  /* UPDATE DATABASE PATH */ 
  databasePath = "/UsersData/" + uid;

  /* UPDATE DATABASE PATH FOR SENSOR READINGS */ 
  tempPath = databasePath + "/temperature"; /* --> UsersData/<user_uid>/temperature */ 
  humPath = databasePath + "/humidity";     /* --> UsersData/<user_uid>/humidity */ 
  presPath = databasePath + "/pressure";    /* --> UsersData/<user_uid>/pressure */ 
  ledPath = databasePath + "/led";          /* --> UsersData/<user_uid>/led */ 
}

void loop() {
  /* SEND NEW READINGS TO DATABASE EVERY 2 SECONDS */ 
  if (Firebase.ready() && (millis() - sendDataPrevMillis > timerDelay || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();

    /* GENERATE RANDOM VALUES FOR TESTING */ 
    temperature = random(200, 350) / 10.0;     /* 20.0°C to 35.0°C */ 
    humidity    = random(300, 800) / 10.0;     /* 30.0% to 80.0% */ 
    pressure    = random(9500, 10500) / 10.0;  /* 950.0 hPa to 1050.0 hPa */ 

    /* SEND READINGS TO DATABASE: */ 
    sendFloat(tempPath, temperature);
    sendFloat(humPath, humidity);
    sendFloat(presPath, pressure);

    /* READ LED STATE FROM FIREBASE */ 
    readData(ledPath);
  }
}
