/*
  TITLE
  By V205
*/

#include <BTstackLib.h>



const uint8_t adv_data[] = {
  0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07, 0x02, 0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const uint8_t adv_data2[] = {
  0x16, 0xff, 0x4c, 0x00, 0x04, 0x04, 0x2a, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xc1, 0x06, 0x60, 0x4c, 0x95, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00
};
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200); // begin serial comunication.
  delay(1000);
  Serial.println(F("STARTING " __FILE__ " from " __DATE__ __TIME__));
  BTstack.setup();

  //BTstack.setAdvData(sizeof(adv_data), adv_data);
  //BTstack.startAdvertising();

}

void loop() 
{
  BTstack.stopAdvertising()
  delay(1000);
  BTstack.setAdvData(sizeof(adv_data2), adv_data2);
  BTstack.startAdvertising();
  // put your main code here, to run repeatedly:
  BTstack.loop();
  delay(1000);

  BTstack.stopAdvertising()
  delay(1000);
  BTstack.setAdvData(sizeof(adv_data), adv_data);
  BTstack.startAdvertising();
  // put your main code here, to run repeatedly:
   BTstack.loop();
   delay(1000);
  

}

