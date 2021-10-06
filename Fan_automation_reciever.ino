#include <printf.h>
#include <nRF24L01.h>
#include <RF24_config.h>
#include <RF24.h>

RF24 radio(7, 8);

const byte address[6] = "JAMES";

void setup() {
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  delay(1000);
}

void loop() {
  if (radio.available()) {
    int value = 0;
    radio.read(&value, sizeof(value));
    Serial.println(value);
    
    if (value == 1) {
      digitalWrite(4, LOW);
     }
     else if (value == 0) {
      digitalWrite(4, HIGH);
     }
  }

}
