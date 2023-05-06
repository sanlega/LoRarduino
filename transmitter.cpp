#include <SPI.h>
#include <LoRa.h>

const int csPin = 10;
const int resetPin = 9;
const int irqPin = 2;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Transmitter");

  LoRa.setPins(csPin, resetPin, irqPin);

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println("Hello world!");

  LoRa.beginPacket();
  LoRa.print("Hello world!");
  LoRa.endPacket();

  delay(5000);
}
