#include "Blink.h"

CyclePulse::CyclePulse(unsigned pulses_, unsigned pulse_time_, unsigned cycle_time_) {
  // pulses: the number of pulses by cycle
  // pulse_time: how long is each pulse
  // cycle_time: how much time is between each cycle of pulses
  pulses = pulses_;
  pulse_time = pulse_time_;
  cycle_time = cycle_time_;
}

bool CyclePulse::getState() {
  if (millis() - rest0 > cycle_time) {
    if (millis() - rest1 > pulse_time / 2) {
      state = !state;
      count++;
      rest1 = millis();
      return state;
    }
    if (count >= pulses * 2) {
      count = 0;
      rest0 = millis();
    }
  }
}

Blink::Blink(unsigned cycle_time_) {
  cycle_time = cycle_time_;
}

bool Blink::getState() {
  if (millis() - rest > cycle_time) {
    state = !state;
    rest = millis();
  }
  return state;
}

//Automat utilities
// TON
unsigned long TON::getTimeOn(bool state) {
  if (state) time_on = (millis() - rest);
  else {
    rest = millis();
    time_on = 0;
  }
  return (unsigned long)(time_on);
}

void TON::compute(bool IN, unsigned long PT) {
	ET = getTimeOn(IN);
  if (ET > PT) Q = true;
  else Q = false;
}

bool TON::get_Q(){
	return Q;
}

unsigned long TON::get_ET(){
	return ET;
}

// TP
void TP::compute(bool IN, unsigned long pulse_time) {
  ED_R_IN.compute(IN);
  if (ED_R_IN.get_Q() and (millis() - last_time > pulse_time)) last_time = millis();
  Q = (millis() - last_time < pulse_time);
}

bool TP::get_Q() {
  return Q;
}

