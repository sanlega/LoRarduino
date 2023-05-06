#include <ESP8266WiFi.h>
//#include <ESP8266HTTPClient.h>
//#include <WiFiClient.h>
#include <SPI.h>
#include <LoRa.h>

const int csPin = 10;
const int resetPin = 9;
const int irqPin = 2;

// Replace with your network details
//const char* ssid = "your_SSID";
//const char* password = "your_PASSWORD";

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Receiver");

  LoRa.setPins(csPin, resetPin, irqPin);

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  // Connect to WiFi network
  //WiFi.begin(ssid, password);

  //while (WiFi.status() != WL_CONNECTED) {
  //  delay(1000);
  //  Serial.println("Connecting to WiFi...");
  //}

  //Serial.println("Connected to WiFi");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String msg = "";
    Serial.print("Received packet '");
    while (LoRa.available()) {
      char c = (char)LoRa.read();
      msg += c;
      Serial.print(c);
    }
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());

    //if(WiFi.status() == WL_CONNECTED) {
    //  WiFiClient client;
    //  HTTPClient http;
      
      // Specify the URL and content type for the POST request
    //  http.begin(client, "http://your-server.com/your-endpoint"); 
    //  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

      // Send the POST request and get the response
    //  int httpResponseCode = http.POST("message=" + msg);

    //  if(httpResponseCode>0) {
    //    String response = http.getString();
    //    Serial.println(httpResponseCode);
    //    Serial.println(response);
    //  }
    //  else {
    //    Serial.print("Error on sending POST: ");
    //    Serial.println(httpResponseCode);
    //  }

    //  http.end();
    //}
  }
}
