#include <Debounce.h>

void setup() {
  Serial.begin(9600);  // Initialize the serial to see the results
}

void loop() {
  bool value_to_read = false;
  static VirtualButton my_button; //creating a button at the pin 5 with INPUT_PULLLUP = pinMode(5, INPUT_PULLUP)
  
  int my_button_stored = my_button.Read(value_to_read); 
  // if you want to read the value in multiple lines in the same loop you have to store the value in a variable,
  // this is because and edge is detected when the last value is different than the next, this indirectly means that only lasts one scan cycle

  if (my_button_stored == RISING) Serial.println("button rising"); 
  if (my_button_stored == FALLING) Serial.println("button falling"); 
  if (my_button_stored == HIGH) Serial.println("button high"); 
  if (my_button_stored == LOW) Serial.println("button low"); 

  if (my_button.getTimeOn(value_to_read) > 2000) Serial.println("Pressed more than 2000 millisseconds");
  if (my_button.getTimeOff(value_to_read) > 2000) Serial.println("Unpressed more than 2000 millisseconds");
}
