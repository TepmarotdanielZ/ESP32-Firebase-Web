
#include <Arduino.h>
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif

#include <Firebase_ESP_Client.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "DHT.h"

/* PROVIDE THE TOKEN GENERATION PROCESS INFO */
#include "addons/TokenHelper.h"
/* PROVIDE THE RTDB PAYLOAD PRINTING INFO AND OTHER HELPER FUNCTIONS */ 
#include "addons/RTDBHelper.h"

/* WIFI CREDENTIALS */
#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

/* FIREBASE PROJECT CONFIG */
#define API_KEY "YOUR_API_KEY"
#define USER_EMAIL "YOUR_EMAIL"
#define USER_PASSWORD "YOUR_PASSWORD"
#define DATABASE_URL "YOUR_DATABASE_URL"

/* FIREBASE OBJECTS */
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

/* USER UID */
String uid;

/* DATABASE PATHS */
String databasePath;
String tempPath;
String humPath;
String ledPath;

/* DHT11 CONFIG */
#define DHTPIN 4         /* GPIO WHERE DHT11 IS CONNECTED */ 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

float temperature;
float humidity;
String ledState = "OFF";   /* TRACK LED STATE */ 
const int led = 13;        /* PIN LED */ 

/* TIMER VARIABLES */
unsigned long sendDataPrevMillis = 0;
unsigned long timerDelay = 2000; /* 2 SECONDS */ 

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

/* WRITE FLOAT VALUES TO FIREBASE */
void sendFloat(String path, float value) {
  if (Firebase.RTDB.setFloat(&fbdo, path.c_str(), value)) {
    /* SUCCESSFULLY SENT */ 
  } else {
    Serial.println("FAILED: " + fbdo.errorReason());
  }
}

/* READ LED STATE FROM FIREBASE */
void readData(String path) {
  String readIncoming = "";
  if (Firebase.RTDB.getString(&fbdo, path.c_str())) {
    if (fbdo.dataType() == "string") {
      readIncoming = fbdo.stringData();
      if (readIncoming == "ON") {
        digitalWrite(led, HIGH);
        ledState = "ON";
      } else {
        digitalWrite(led, LOW);
        ledState = "OFF";
      }
    }
  } else {
    Serial.println("FAILED: " + fbdo.errorReason());
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);

  initWiFi();
  dht.begin(); /* START DHT-11 SENSOR */

  /* FIREBASE SETUP */
  config.api_key = API_KEY;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.database_url = DATABASE_URL;

  Firebase.reconnectWiFi(true);
  fbdo.setResponseSize(4096);
  config.token_status_callback = tokenStatusCallback;
  config.max_token_generation_retry = 5;

  Firebase.begin(&config, &auth);

  /* GET USER UID */
  Serial.println("Getting User UID");
  while ((auth.token.uid) == "") {
    Serial.print('.');
    delay(1000);
  }
  uid = auth.token.uid.c_str();
  Serial.println("User UID: " + uid);

  /* DATABASE PATHS */
  databasePath = "/UsersData/" + uid;
  tempPath = databasePath + "/temperature";
  humPath  = databasePath + "/humidity";
  ledPath  = databasePath + "/led";
}

void loop() {
  if (Firebase.ready() && (millis() - sendDataPrevMillis > timerDelay || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();

    /* READ DHT11 VALUES */
    humidity = dht.readHumidity();
    temperature = dht.readTemperature(); // Celsius
    if (isnan(humidity) || isnan(temperature)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    /* SEND TO FIREBASE AND WEB DASHBOARD */
    sendFloat(tempPath, temperature);
    sendFloat(humPath, humidity);

    /* READ LED STATE FROM FIREBASE */
    readData(ledPath);

    /* PRINT FORMATTED SERIAL OUTPUT */

    Serial.print("TEMPERATURE: ");
    Serial.print(temperature);
    Serial.println(" °C");
    Serial.print("HUMIDITY: ");
    Serial.print(humidity);
    Serial.println(" %");
    Serial.print("LED: ");
    Serial.println(ledState);
    Serial.println();
  }
}
