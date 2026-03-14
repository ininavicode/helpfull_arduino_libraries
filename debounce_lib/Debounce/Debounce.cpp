#include "Debounce.h"
#include "Arduino.h"


// R_TRIG Class
void R_TRIG::compute(bool IN) {
  if (!last_state and IN){
	Q = true;
  } 
  else Q = false;
  	last_state = IN;
}

bool R_TRIG::get_Q(){
	return Q;
}

// F_TRIG Class
void F_TRIG::compute(bool IN) {
  if (last_state and !IN){
	Q = true;
  } 
  else Q = false;
  last_state = IN;
}

bool F_TRIG::get_Q(){
	return Q;
}


// PhysicButton Class
PhysicButton::PhysicButton(int _pin, int _mode, unsigned debounce_time_ = 100, unsigned debounce_time_off_ = NULL) {
  pin = _pin;
  mode = _mode;
  debounce_time = debounce_time_;
  if (debounce_time_off_ == NULL) debounce_time_off = debounce_time_;
  else debounce_time_off = debounce_time_off_;

  pinMode(pin, mode);
}

void PhysicButton::setMode(int _mode) {
  mode = _mode;
  pinMode(pin, mode);
}

int PhysicButton::Read() {
  if (getTimeOn() > debounce_time) actual_state = true;
  if (getTimeOff() > debounce_time_off) actual_state = false;
  int output;

  if (!last_state and actual_state) output = RISING;

  else if (last_state and !actual_state) output = FALLING;

  else if (actual_state) output = HIGH;

  else if (!actual_state) output = LOW;

  last_state = actual_state;

  return output;
}

unsigned long PhysicButton::getTimeOn() {
  bool state;
  if (!invert_input) state = digitalRead(pin);
  else state = !digitalRead(pin);

  if (state) time_on = (millis() - rest);
  else {
    rest = millis();
    time_on = 0;
  }
  return (unsigned long)(time_on);
}

unsigned long PhysicButton::getTimeOff() {
  bool state;
  if (!invert_input) state = digitalRead(pin);
  else state = !digitalRead(pin);

  if (!state) time_off = millis() - rest2;
  else {
    rest2 = millis();
    time_off = 0;
  }
  return (unsigned long)(time_off);
}
// End of PhysicButton Class

// Virtual Button Class
VirtualButton::VirtualButton(unsigned debounce_time_ = 100, unsigned debounce_time_off_ = NULL) {
  debounce_time = debounce_time_;
  if (debounce_time_off_ == NULL) debounce_time_off = debounce_time_;
  else debounce_time_off = debounce_time_off_;
}

int VirtualButton::Read(bool state) {
  if (getTimeOn(state) > debounce_time) actual_state = true;
  if (getTimeOff(state) > debounce_time_off) actual_state = false;
  int output;

  if (!last_state and actual_state) output = RISING;

  else if (last_state and !actual_state) output = FALLING;

  else if (actual_state) output = HIGH;

  else if (!actual_state) output = LOW;

  last_state = actual_state;

  return output;
}

unsigned long VirtualButton::getTimeOn(bool state) {
  if (state) time_on = (millis() - rest);
  else {
    rest = millis();
    time_on = 0;
  }
  return (unsigned long)(time_on);
}

unsigned long VirtualButton::getTimeOff(bool state) {
  if (!state) time_off = millis() - rest2;
  else {
    rest2 = millis();
    time_off = 0;
  }
  return (unsigned long)(time_off);
}

//Physici Potenciometer Class
PhysicPotenciometer::PhysicPotenciometer(byte AI_pin_, int short value_tolerance_, unsigned short time_tolerance_) {
  AI_pin = AI_pin_;
  value_tolerance = value_tolerance_;
  time_tolerance = time_tolerance_;
}

unsigned short PhysicPotenciometer::getFiltered() {
  unsigned short value = analogRead(AI_pin);

  if (millis() - rest > time_tolerance and (abs(value - last_value) > value_tolerance)) {
    last_value = value;
    rest = millis();
  }
  return last_value;
}

//Virutal Potenciometer Class
VirtualPotenciometer::VirtualPotenciometer(int value_tolerance_, unsigned short time_tolerance_) {
  value_tolerance = value_tolerance_;
  time_tolerance = time_tolerance_;
}

int long VirtualPotenciometer::getFiltered(int long value) {
  if (millis() - rest > time_tolerance and (abs(value - last_value) > value_tolerance)) {
    last_value = value;
    rest = millis();
  }
  return last_value;
}
