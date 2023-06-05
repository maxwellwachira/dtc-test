#include <Arduino.h>
#include <CAN.h> // the OBD2 library depends on the CAN library
#include <OBD2.h>

#define CAN_RX 17
#define CAN_TX 16

void setup(){

  Serial.begin(115200);
  while (!Serial);

  Serial.println(F("OBD2 DTC TEST"));

  CAN.setPins(CAN_RX, CAN_TX);

  while (true){
    Serial.print(F("Attempting to connect to OBD2 CAN bus ... "));

    if (!OBD2.begin()){
      Serial.println(F("failed!"));
      delay(1000);
    } else {
      Serial.println(F("success"));
      break;
    }
  }
}

void loop() {
  String allDtcs = OBD2.getAllDTCs();
  Serial.print("All DTC: ");
  Serial.println(allDtcs);
  delay(3000);
}
