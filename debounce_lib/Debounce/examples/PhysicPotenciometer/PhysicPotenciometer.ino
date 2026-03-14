#include <Debounce.h>

void setup() {
  Serial.begin(9600);  // Initialize the serial to see the results
}

void loop() {
  //creating a PhysicPotenciometer at the pin A0, minimal change value = 25, minimal time passed = 10
  static PhysicPotenciometer my_potenciometer(0, 25, 10);

  if (my_potenciometer.getFiltered() > 512) Serial.println("Above 512");
  if (my_potenciometer.getFiltered() < 512) Serial.println("Below 512");
}
