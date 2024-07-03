/*
  TITLE
  By V205
*/

#include <BTstackLib.h>



const uint8_t adv_data[] = {
  0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07, 0x02, 0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200); // begin serial comunication.
  delay(1000);
  Serial.println(F("STARTING " __FILE__ " from " __DATE__ __TIME__));
  BTstack.setup();

  BTstack.setAdvData(sizeof(adv_data), adv_data);
  BTstack.startAdvertising();

}

void loop() 
{
  // put your main code here, to run repeatedly:
   BTstack.loop();
}

