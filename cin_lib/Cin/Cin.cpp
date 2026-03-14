#include "Arduino.h"
#include <string.h>

//A simple method to simulate the c++ cin function
void cin(String name, bool& var) {	
  bool flag;
  int h = NULL;
  String str_out = "Enter the " + name + " value\n";
  Serial.println(str_out);

  while (h == NULL) {
    h = Serial.parseInt();
    if (h == 0 and Serial.available()) break;
  }

  var = h;
  str_out = name + " set in: " + String(var);
  Serial.println(str_out);
}

//A simple method to simulate the c++ cin function
void cin(String name, int min_val, int max_val, int& var) {	
  bool flag;
  int h = NULL;
  String str_out = "Enter the " + name + " (" + min_val + " - " + max_val + ")\n";
  Serial.println(str_out);

  while (h == NULL) {
    h = Serial.parseInt();
    if (h == 0 and Serial.available()) break;
  }
  if (h > max_val) h = max_val;
  if (h < min_val) h = min_val;

  var = h;
  str_out = name + " set in: " + String(var);
  Serial.println(str_out);
}

void cin(String name, float min_val, float max_val, float& var) {	
  bool flag;
  int h = NULL;
  String str_out = "Enter the " + name + " (" + min_val + " - " + max_val + ")\n";
  Serial.println(str_out);

  while (h == NULL) {
    h = Serial.parseFloat();
    if (h == 0 and Serial.available()) break;
  }
  if (h > max_val) h = max_val;
  if (h < min_val) h = min_val;

  var = h;
  str_out = name + " set in: " + String(var);
  Serial.println(str_out);
}

void cin(String name, double min_val, double max_val, double& var) {	
  bool flag;
  int h = NULL;
  String str_out = "Enter the " + name + " (" + min_val + " - " + max_val + ")\n";
  Serial.println(str_out);

  while (h == NULL) {
    h = Serial.parseFloat();
    if (h == 0 and Serial.available()) break;
  }
  if (h > max_val) h = max_val;
  if (h < min_val) h = min_val;

  var = h;
  str_out = name + " set in: " + String(var);
  Serial.println(str_out);
}

//optional arguments---------------------------------------------
//A simple method to simulate the c++ cin function
void cin(String name, bool& var, void (*p_void)()) {	
  bool flag;
  int h = NULL;
  String str_out = "Enter the " + name + " value\n";
  Serial.println(str_out);

  while (h == NULL) {
    h = Serial.parseInt();
    if (h == 0 and Serial.available()) break;
  }

  var = h;
  str_out = name + " set in: " + String(var);
  Serial.println(str_out);
  p_void();
}

//A simple method to simulate the c++ cin function
void cin(String name, int min_val, int max_val, int& var, void (*p_void)()) {	
  bool flag;
  int h = NULL;
  String str_out = "Enter the " + name + " (" + min_val + " - " + max_val + ")\n";
  Serial.println(str_out);

  while (h == NULL) {
    h = Serial.parseInt();
    if (h == 0 and Serial.available()) break;
  }
  if (h > max_val) h = max_val;
  if (h < min_val) h = min_val;

  var = h;
  str_out = name + " set in: " + String(var);
  Serial.println(str_out);
  p_void();
}

void cin(String name, float min_val, float max_val, float& var, void (*p_void)()) {	
  bool flag;
  int h = NULL;
  String str_out = "Enter the " + name + " (" + min_val + " - " + max_val + ")\n";
  Serial.println(str_out);

  while (h == NULL) {
    h = Serial.parseFloat();
    if (h == 0 and Serial.available()) break;
  }
  if (h > max_val) h = max_val;
  if (h < min_val) h = min_val;

  var = h;
  str_out = name + " set in: " + String(var);
  Serial.println(str_out);
  p_void();
}

void cin(String name, double min_val, double max_val, double& var, void (*p_void)()) {	
  bool flag;
  int h = NULL;
  String str_out = "Enter the " + name + " (" + min_val + " - " + max_val + ")\n";
  Serial.println(str_out);

  while (h == NULL) {
    h = Serial.parseFloat();
    if (h == 0 and Serial.available()) break;
  }
  if (h > max_val) h = max_val;
  if (h < min_val) h = min_val;

  var = h;
  str_out = name + " set in: " + String(var);
  Serial.println(str_out);
  p_void();
}
