#include "Joystick.h"

Joystick::Joystick(byte x_pin, byte y_pin, byte sw_pin, int sw_mode, byte axis_num) {
  x_pin_ = x_pin;
  y_pin_ = y_pin;
  sw_pin_ = sw_pin;
  sw_mode_ = sw_mode;
  axis_num_ = axis_num;
  joystick_x = new PhysicPotenciometer(x_pin, 3, 10);
  joystick_y = new PhysicPotenciometer(y_pin, 3, 10);
  if (sw_pin != NULL and sw_mode != NULL) button = new PhysicButton(sw_pin, sw_mode);
}
Joystick::~Joystick() {
  delete joystick_x;
  delete joystick_y;
  delete button;
}

unsigned short Joystick::get_x() {
  return joystick_x->getFiltered();
}
unsigned short Joystick::get_y() {
	if (axis_num_ == 2){
		return joystick_y->getFiltered();
	} else if (axis_num_ == 3){
		if ((button->getTimeOn() > button->debounce_time)) {
    		return 520;
		} else return joystick_y->getFiltered();
	}
  
}
unsigned short Joystick::get_z() {
	if (axis_num_ == 2){
		return 520;
	} else if (axis_num_ == 3){
		if (!(button->getTimeOn() > button->debounce_time)) {
	    	return 520;
		} else return joystick_y->getFiltered();	
	}
  
}
int Joystick::get_sw() {
  return button->Read();
}
