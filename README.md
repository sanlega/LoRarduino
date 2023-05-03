# 📡 ARDUINO LoRa Test: 🤖

To send messages between two Arduino Nanos using LoRa-02 SX1278 modules, you'll need to connect the modules to the Arduinos and set up the necessary software libraries. Here's a step-by-step guide with some interesting info and emojis to make it look better:

1. 📦 Gather the required components:
   - 2x Arduino Nano 🧠
   - 2x LoRa-02 SX1278 module 📡
   - Jumper wires 🌈
   - Breadboards (optional, but helpful for prototyping) 🍞

2. 🔌 Connect the modules to the Arduino Nanos:
   Wire the modules to the corresponding Arduino pins, following the connections below:

   LoRa-02 SX1278 | Arduino Nano
   ---------------|--------------
   VCC            | 3.3V 🔋
   GND            | GND ⚡
   MISO           | D12 🔄
   MOSI           | D11 ➡️
   SCK            | D13 ⏱️
   NSS            | D10 📚
   DIO0           | D2 🚪
   RESET          | D9 🔄

   Repeat the connections for the second Arduino Nano and LoRa module. 🔄

3. 📚 Install the necessary Arduino libraries:
   You'll need to install the "LoRa" library by Sandeep Mistry. Open the Arduino IDE, go to Sketch > Include Library > Manage Libraries, search for "LoRa" and install the library by Sandeep Mistry. 🔍

4. 📤 Set up the transmitter (Arduino Nano 1):
   Upload the transmitter.cpp code to the first Arduino. 🚀
   
5. 📥 Set up the receiver (Arduino Nano 2):
   Upload the receiver.cpp code to the second Arduino. 🛰️
   
6. 📞 Test the communication:
   Power both Arduino Nanos 🔌 and open their respective Serial Monitors. 🖥️ The transmitter should display "Sending packet: Hello world!" every 5 seconds ⏱️, while the receiver should display the received message 📨 and the RSSI (Received Signal Strength Indicator) value. 📶

You should now have a basic communication setup between two Arduino Nanos using LoRa-02 SX1278 modules. 🎉 You can further customize the code to send and receive different types of data or implement additional features, such as error correction or encryption. 🔐
