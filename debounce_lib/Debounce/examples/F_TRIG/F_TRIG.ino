#include <Debounce.h>

void setup() {
  Serial.begin(9600);  // Initialize the serial to see the results
}

void loop() {
  bool variable_to_read = false;
  static F_TRIG my_f_trig;  // create an static R_TRIG object

  my_f_trig.compute(variable_to_read); // computing
  if (my_f_trig.get_Q()) Serial.println("Falling edge"); // print "Falling edge" if there is a rising edge of "variable_to_read"
}
