#include <ezTime.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ESP8266WebServer.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

// DHT Sensor setup
uint8_t DHTPin = 13;        // on Pin 13 of the Huzzah
DHT dht(DHTPin, DHTTYPE);

// Button setup
uint8_t buttonPin = 2;
int buttonState = 0;

// Microphone setup
const int MIC = A0; // Use A0 for analog input
int value;

// Wifi and MQTT
#include "arduino_secrets.h"

const char* ssid     = SECRET_SSID;
const char* password = SECRET_PASS;
const char* mqttuser = SECRET_MQTTUSER;
const char* mqttpass = SECRET_MQTTPASS;

ESP8266WebServer server(80);
const char* mqtt_server = "mqtt.cetools.org";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
//int value = 0;
//float dB; // Declare dB as a global variable

// Date & Time
Timezone GB;

unsigned long lastMQTTSendTime = 0;  // Last time the MQTT message was sent
const long interval = 3000;  // Interval at which to send message (1 second)

void startWifi();
void startWebserver();
void syncDate();
void sendMQTT();
void callback(char* topic, byte* payload, unsigned int length);

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(DHTPin, INPUT);
  pinMode(MIC, INPUT); // Corrected to INPUT

  // Start DHT sensor
  dht.begin();

  Serial.begin(115200);
  delay(100); // to give time for the serial connection to open

  // Initiate the connecting to wifi routine
  startWifi();
  startWebserver();
  syncDate();

  // Once connected to wifi establish connection to mqtt broker
  client.setServer(mqtt_server, 1884);
  client.setCallback(callback);
}

void loop() {
  // Handler for receiving requests to webserver
  server.handleClient();

  unsigned long currentMillis = millis();

  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    Serial.println("Button Pressed");
  } else {
    Serial.println("Button Released");
  }

  // Read the microphone value
  value = analogRead(MIC); 
  Serial.print("Sound Level: ");
  Serial.println(value);
  //delay(1000);


  Serial.print("Temp:");
  Serial.println(dht.readTemperature());
  Serial.print("Hum:");
  Serial.println(dht.readHumidity());

  if (currentMillis - lastMQTTSendTime >= interval) {
    lastMQTTSendTime = currentMillis;  // Save the last time you sent the data
    sendMQTT();
  }

  client.loop();
  delay(1000);
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    
    // Attempt to connect
    if (client.connect(clientId.c_str(), mqttuser, mqttpass)) {
      Serial.println("connected");
      // ... and subscribe to messages on broker
      client.subscribe("student/ucfninf/Diorama");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void startWifi(){
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  // Check to see if connected and wait until you are
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void startWebserver() {
  // Add your webserver setup code here
}

void syncDate() {
  waitForSync();
  Serial.println("UTC: " + UTC.dateTime());
  GB.setLocation("Europe/London");
  Serial.println("London time: " + GB.dateTime());  
}

void sendMQTT() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  
  float Temperature = dht.readTemperature(); // Gets the values of the temperature
  snprintf(msg, 50, "%.1f", Temperature);
  Serial.print("Publish message for temperature: ");
  Serial.println(msg);
  client.publish("student/ucfninf/Diorama/temperature", msg);

  float Humidity = dht.readHumidity(); // Gets the values of the humidity
  snprintf(msg, 50, "%.0f", Humidity);
  Serial.print("Publish message for humidity: ");
  Serial.println(msg);
  client.publish("student/ucfninf/Diorama/humidity", msg);

  // For noise level
  snprintf(msg, 50, "%d", value); // Use the global value variable
  Serial.print("Publish message for noise ");
  Serial.println(msg);
  client.publish("student/ucfninf/Diorama/noise", msg);

  // For button state
  snprintf(msg, 50, "%d", buttonState); // Publish the button state
  Serial.print("Publish message for Button ");
  Serial.println(msg);
  client.publish("student/ucfninf/Diorama/button", msg);
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (unsigned int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}
