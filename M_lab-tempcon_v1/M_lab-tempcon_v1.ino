#include "config.h"

int sp_val = 0;
bool force_update_flag = false;


void setup()   {

  Serial.begin(115200);
  display_init();
  thermoCouple.setSPIspeed(5000);
  thermoCouple.begin(thermocouple_ss_pin);  // HW SPI
  pinMode(RELAY_PIN, OUTPUT);

  MsTimer2::set(5, encoder_update); // 10ms period
  MsTimer2::start();

}

void loop() {
  static unsigned long update_sensor_timer = 0;
  static unsigned long conversion_timer = 0;
  static unsigned long update_display_timer = 0;
  static  int pv_val = round(thermoCouple.getTemperature());
  if (millis() - update_sensor_timer >= 250 ) {
    update_sensor_timer = millis();
    conversion_timer = millis();
    int status = thermoCouple.read();
    pv_val = round(thermoCouple.getTemperature());

    if (pv_val < sp_val)digitalWrite(RELAY_PIN, HIGH);
    else  digitalWrite(RELAY_PIN, LOW);

  }
  if (millis() - update_display_timer >= 50 ) {
    update_display_timer = millis();

    update_display(sp_val, pv_val);

  }
  //encoder_update();

}
