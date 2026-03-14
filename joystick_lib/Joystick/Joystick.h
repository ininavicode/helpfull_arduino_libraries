#ifndef Joystick_h
#define Joystick_h

// libraries
#include "Arduino.h"
#include "Debounce.h"

// class definition
class Joystick {
private:
  int sw_mode_;
  byte axis_num_ = 2;
  byte x_pin_, y_pin_, sw_pin_;
  PhysicPotenciometer *joystick_y;
  PhysicPotenciometer *joystick_x;
  PhysicButton *button;
public:

  Joystick(byte x_pin, byte y_pin, byte sw_pin, int sw_mode, byte axis_num);
  ~Joystick();
  unsigned short get_x();
  unsigned short get_y();
  unsigned short get_z();
  int get_sw();
};

#endif
