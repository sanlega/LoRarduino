#include <SPI.h>
#include <LoRa.h>

const int csPin = 10;
const int resetPin = 9;
const int irqPin = 2;

unsigned long lastTransmitTime = 0;
unsigned long transmitInterval = 5000; // Time between transmissions in milliseconds
int nodeID = 1; // Assign a unique ID for each Arduino (e.g., 1 and 2)

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Transceiver");

  LoRa.setPins(csPin, resetPin, irqPin);

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  // Check for received packets
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("Received packet '");
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }

  // Transmit a message after the transmit interval
  unsigned long currentTime = millis();
  if (currentTime - lastTransmitTime > transmitInterval) {
    lastTransmitTime = currentTime;

    String message = "Hello from node " + String(nodeID) + "!";

    Serial.print("Sending packet: ");
    Serial.println(message);

    LoRa.beginPacket();
    LoRa.print(message);
    LoRa.endPacket();
  }
}
