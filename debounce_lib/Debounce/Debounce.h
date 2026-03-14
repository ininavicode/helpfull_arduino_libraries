#ifndef Debounce_h
#define Debounce_h

#include "Arduino.h"

  

class R_TRIG {
private:
  bool last_state = 0;
  bool Q = false;

public:
  //Public Funtions
  void compute(bool IN);
  bool get_Q();
};

class F_TRIG {
private:
  bool last_state = 0;
  bool Q = false;

public:
  //Public Funtions
  void compute(bool IN);
  bool get_Q();
};

class PhysicButton {
private:
  bool last_state = 0, actual_state = 0;

  unsigned long rest = 0, rest2 = 0;
  unsigned long time_on = 0, time_off = 0;

  byte pin;
  int mode;
  
public:
  unsigned debounce_time, debounce_time_off;
	bool invert_input = false;


  //Public Funtions
#ifdef ESP32
	PhysicButton(int _pin, int _mode, unsigned debounce_time_, unsigned debounce_time_off_); //default parameters must be declared, only in the declaration of the function, not in the implementation
#else
	PhysicButton(int _pin, int _mode, unsigned debounce_time_ = 100, unsigned debounce_time_off_ = NULL); //default parameters must be declared, only in the declaration of the function, not in the implementation
#endif

  
  void setMode(int _mode);
  int Read();
  unsigned long getTimeOn();
  unsigned long getTimeOff();
};

class VirtualButton {
private:
  bool last_state = 0, actual_state = 0;

  unsigned long rest = 0, rest2 = 0;
  unsigned long time_on = 0, time_off = 0;

public:
  unsigned debounce_time, debounce_time_off;

  //Public Funtions
#ifdef ESP32
  VirtualButton(unsigned debounce_time_, unsigned debounce_time_off_);
#else
  VirtualButton(unsigned debounce_time_ = 100, unsigned debounce_time_off_ = NULL);
#endif
  int Read(bool state);
  unsigned long getTimeOn(bool state);
  unsigned long getTimeOff(bool state);
};

class PhysicPotenciometer {
private:
  int long last_value = 0;
  unsigned long rest = 0;

  int long filtered_value;

  byte AI_pin;
public:
  int value_tolerance;
  int time_tolerance;

  //Public Funtions

  PhysicPotenciometer(byte AI_pin_, int short value_tolerance_, unsigned short time_tolerance_);
  unsigned short getFiltered();
};


class VirtualPotenciometer {
private:
  int long last_value = 0;
  unsigned long rest = 0;

  int long filtered_value;

public:
  int value_tolerance;
  int time_tolerance;

  //Public Funtions

  VirtualPotenciometer(int value_tolerance_, unsigned short time_tolerance_);
  int long getFiltered(int long value);
};

#endif
