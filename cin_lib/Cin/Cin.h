#ifndef Cin_h
#define Cin_h

#include "Arduino.h"
#include <string.h>

//A simple method to simulate the c++ cin function
void cin(String name, bool& p_var);
void cin(String name, int min_val, int max_val, int& p_var);
void cin(String name, float min_val, float max_val, float& p_var);
void cin(String name, double min_val, double max_val, double& p_var);

// optional arguments
void cin(String name, bool& p_var, void (*p_void)());
void cin(String name, int min_val, int max_val, int& p_var, void (*p_void)());
void cin(String name, float min_val, float max_val, float& p_var, void (*p_void)());
void cin(String name, double min_val, double max_val, double& p_var, void (*p_void)());




#endif
