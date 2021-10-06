#include <printf.h>
#include <nRF24L01.h>
#include <RF24_config.h>
#include <RF24.h>

RF24 radio(7, 8);
const byte address[6] = "JAMES";
int sensorVal = 0;
float voltage = 0.0;
float tempCels = 0.0;
float tempFar = 0.0;

int on = 1;
int off = 0;
int oOrOff = 0;
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
}

void loop() {
  sensorVal = analogRead(A7);
  voltage = (sensorVal/1024.0) * 5.0;
  tempCels = (voltage - .5) * 100;
  tempFar = (tempCels * 1.8) + 32;
  if (tempFar <= 79.0) {
    radio.write(&off, sizeof(off));
  } else if (tempFar >= 82.0) {
    radio.write(&on, sizeof(on));
  }
  delay(10000);
}
