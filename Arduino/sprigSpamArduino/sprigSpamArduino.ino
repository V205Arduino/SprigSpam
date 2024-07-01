/*
  sprigSpamArduino.ino
  By V205
*/

#include <BTstackLib.h>
#include <Arduino_GFX_Library.h>





/*
pin stuff, can ignore
GPIO  16 Pin 21 MISO
GPIO 17 pin 22 LITE
GPIO18 pin 24 SCK
GPIO19 pin 25 MOSI
GPIO22 pin 29 D/C
chip select pin, it's gp21/pin27
RESET = gP26
USE THE GP ONE

Arduino_HWSPI(int8_t dc, int8_t cs = GFX_NOT_DEFINED, SPIClass *spi = &SPI, bool is_shared_interface = true); // Constructor thingy
TODO: get
*/

//Arduino_DataBus *bus = new Arduino_HWSPI(16 /* DC */, 5 /* CS */);

Arduino_DataBus *bus = new Arduino_HWSPI(22, 21);
//Arduino_GFX *gfx = new Arduino_ILI9341(bus, 17 /* RST */);
Arduino_GFX *gfx = new Arduino_ST7735(bus, 26, 3);
/*

Arduino_ST7735::Arduino_ST7735(
    Arduino_DataBus *bus, int8_t rst, uint8_t r,
    bool ips, int16_t w, int16_t h,
    uint8_t col_offset1, uint8_t row_offset1, uint8_t col_offset2, uint8_t row_offset2,
*/

const uint8_t adv_data[] = {
  0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07, 0x02, 0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const uint8_t adv_data2[] = {
  0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07, 0x13, 0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


// Define pin numbers for the buttons
const int wButtonPin = 5;
const int aButtonPin = 6;
const int sButtonPin = 7;
const int dButtonPin = 8;
const int iButtonPin = 12;
const int jButtonPin = 13;
const int kButtonPin = 14;
const int lButtonPin = 15;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);  // begin serial comunication.
  delay(1000);
  Serial.println(F("STARTING " __FILE__ " FROM " __DATE__ __TIME__));
  BTstack.setup();

  //BTstack.setAdvData(sizeof(adv_data), adv_data);
  //BTstack.startAdvertising();

  pinMode(wButtonPin, INPUT_PULLUP);
  pinMode(aButtonPin, INPUT_PULLUP);
  pinMode(sButtonPin, INPUT_PULLUP);
  pinMode(dButtonPin, INPUT_PULLUP);
  pinMode(iButtonPin, INPUT_PULLUP);
  pinMode(jButtonPin, INPUT_PULLUP);
  pinMode(kButtonPin, INPUT_PULLUP);
  pinMode(lButtonPin, INPUT_PULLUP);
  pinMode(17, OUTPUT);
  digitalWrite(17, HIGH);
  delay(1000);
  gfx->begin();
  gfx->fillScreen(BLACK);
  gfx->setCursor(10, 10);
  gfx->setTextColor(GREEN);

  gfx->println("Press S to start");
  gfx->println("Press S to start");
  const unsigned long previousTime = 0;
  const long interval = 1000;
  int dotCounter = 0;
  while (digitalRead(sButtonPin) == LOW) {

    unsigned long currentTime = millis();
    if (currentTime - previousTime >= interval) {
      // save the last time you blinked the LED
      previousMillis = currentMillis;

      if (1) {

      } else {
      }
    }
    gfx->fillScreen(BLACK);
  }
}

void loop() {

  /*
  BTstack.stopAdvertising();
  delay(1000);
  BTstack.setAdvData(sizeof(adv_data2), adv_data2);
  BTstack.startAdvertising();
  // put your main code here, to run repeatedly:
  BTstack.loop();
  delay(1000);

  BTstack.stopAdvertising();
  delay(1000);
  BTstack.setAdvData(sizeof(adv_data), adv_data);
  BTstack.startAdvertising();
  // put your main code here, to run repeatedly:
   BTstack.loop();
   */
  delay(1000);
}
