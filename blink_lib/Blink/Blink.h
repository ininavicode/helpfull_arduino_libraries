#ifndef Blink_h
#define Blink_h

#include "Arduino.h"
#include "Debounce.h"

class CyclePulse {
private:
  unsigned long rest0 = 0, rest1 = 0;
  byte count = 0;
  bool state = 0;

public:
  unsigned pulses = 0, pulse_time = 0, cycle_time = 0;

  //Public Functions
  CyclePulse(unsigned pulses_, unsigned pulse_time_, unsigned cycle_time_);
  bool getState();
};



//NEW CLASS ------------------------------
class Blink {
private:
  unsigned long rest = 0;
  bool state = false;

public:
  unsigned cycle_time = 0;

  //Public Functions
  Blink(unsigned cycle_time_);
  bool getState();
};

//Automat Utilities
// TON
class TON {
private:
  unsigned long time_on = 0, rest = 0;
  unsigned long getTimeOn(bool state);
  unsigned long ET = 0;
  bool Q = false;

public:
   void compute(bool IN, unsigned long PT);
   bool get_Q();
   unsigned long get_ET();

};

// TP
class TP {
private:
  bool Q = false;
  unsigned long last_time = 0;
  R_TRIG ED_R_IN;
public:
  void compute(bool IN, unsigned long pulse_time);
  bool get_Q();
};

#endif
