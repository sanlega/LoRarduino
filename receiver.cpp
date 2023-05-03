#include <SPI.h>
#include <LoRa.h>

const int csPin = 10;
const int resetPin = 9;
const int irqPin = 2;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Receiver");

  LoRa.setPins(csPin, resetPin, irqPin);

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("Received packet '");
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}

