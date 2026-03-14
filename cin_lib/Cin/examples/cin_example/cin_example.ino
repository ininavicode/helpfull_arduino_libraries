#include "Cin.h"

int int_var;
bool bool_var;
float float_var;

void setup() {
  Serial.begin(9600);
}

void loop() {
  char c = Serial.read();

  while (!Serial.available()) {
    // your main program will be here
  }

  // we read the value entered by the Serial port whit "char c", so when equals the char we have at the if(condition), the function is called
  if (c == 'i') cin("my int var", 0, 100, int_var);
  if (c == 'f') cin("my float var", 0, 100, float_var);
  if (c == 'b') cin("my bool var", bool_var);
  if (c == 'b') cin("my bool var", bool_var, callback_example);
}

void callback_example(){
  Serial.println("callback_test");
}
