

void encoder_update() {
  static int prev_state = 0b11;
  int curr_state = (digitalRead(2) << 1) | digitalRead(3);
  static unsigned long tick_timer = millis();
  if (prev_state != curr_state) {
    if (prev_state == 0b11) {
      if (curr_state == 0b01) {
        //Serial.print("^");
        //Serial.println(millis() - tick_timer);
        if (millis() - tick_timer < 100)sp_val += 10;
        else sp_val ++;
        tick_timer = millis();
        force_update_flag = true; // improve user experiance


      }
      else if (curr_state == 0b10) {
        //Serial.print("v");
        //Serial.println(millis() - tick_timer);
        if (millis() - tick_timer < 100)sp_val -= 10;
        else sp_val --;
        tick_timer = millis();
        force_update_flag = true;// improve user experiance

      }
    }
    prev_state = curr_state;
  }

}
