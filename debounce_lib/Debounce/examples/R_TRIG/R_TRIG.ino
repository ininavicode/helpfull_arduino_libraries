#include <Debounce.h>

void setup() {
  Serial.begin(9600);  // Initialize the serial to see the results
}

void loop() {
  bool variable_to_read = false;
  static R_TRIG my_r_trig;  // create an static R_TRIG object

  my_r_trig.compute(variable_to_read); // computing
  if (my_r_trig.get_Q()) Serial.println("Rising edge"); // print "Rising edge" if there is a rising edge of "variable_to_read"
}
