#include "Debounce.h"
#include "string.h"
#include "joystick.h"

// PhysicPotenciometer joystick_y(15, 4, 10);
// PhysicPotenciometer joystick_x(14, 4, 10);

// PhysicButton joystick_b(22, INPUT_PULLUP);

Joystick joystick(15, 14, 22, INPUT_PULLUP);

void setup() {
  Serial.begin(9600);
}

void loop() {
  static unsigned short last_value_y, last_value_x, last_value_z;
  unsigned short value_x = joystick.get_x();
  unsigned short value_y = joystick.get_y();
  unsigned short value_z = joystick.get_z();

  if (joystick.get_sw() == RISING) Serial.println("Sw");
  
  // if (joystick.get_sw() == HIGH) {
  //   value_z = joystick.get_y();
  //   value_y = 520;
  // } else {
  //   value_z = 520;
  //   value_y = joystick.get_y();
  // }


  if (last_value_y != value_y or last_value_x != value_x or last_value_z != value_z) {
    last_value_y = value_y;
    last_value_x = value_x;
    last_value_z = value_z;

    String str_print = "{joystick: {x:" + String(value_x) + "}, {y:" + String(value_y) + "}, {z:" + String(value_z) + "}}";
    Serial.println(str_print);
  }
}
