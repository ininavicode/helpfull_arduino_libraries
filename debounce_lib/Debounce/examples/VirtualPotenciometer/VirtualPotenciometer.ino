#include <Debounce.h>

void setup() {
  Serial.begin(9600);  // Initialize the serial to see the results
}

void loop() {
  int long value_to_compute = 500;
  //creating a VirtualPotenciometer at the pin A0, minimal change value = 25, minimal time passed = 10
  static VirtualPotenciometer my_potenciometer(25, 10);

  if (my_potenciometer.getFiltered(value_to_compute) > 512) Serial.println("Above 512");
  if (my_potenciometer.getFiltered(value_to_compute) < 512) Serial.println("Below 512");
}
