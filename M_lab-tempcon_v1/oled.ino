void display_init() {
  delay(250); // wait for the OLED to power up
  display.begin(i2c_Address, true); // Address 0x3C default
  display.setRotation(1);
  update_display(1, 12);
}
void update_display (int sp, int pv) {
  char dec_buffer[10];
  display.clearDisplay();

  display.fillRect(0, 0, 64, 18, SH110X_WHITE);

  display.setTextSize(2);
  display.setTextColor(SH110X_BLACK, SH110X_WHITE);

  display.setCursor(2, 2);
  display.print("SP");
  //
  display.setTextSize(3);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(2, 21);
  sprintf(dec_buffer, "%3d", sp);
  display.print( dec_buffer);
  //
  display.fillRect(0, 45, 64, 18, SH110X_WHITE);

  display.setTextSize(2);
  display.setTextColor(SH110X_BLACK, SH110X_WHITE);


  display.fillRect(0, 45, 64, 18, SH110X_WHITE);
  display.setCursor(2, 47);
  display.print("PV");
  display.setCursor(2, 65);
  display.setTextSize(3);
  display.setTextColor(SH110X_WHITE);
  sprintf(dec_buffer, "%3d", pv);
  display.print( dec_buffer);
  display.drawRect(0, 88, 64, 128 - 88, SH110X_WHITE);
  display.display();
}
