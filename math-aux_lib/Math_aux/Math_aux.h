#ifndef Math_aux_h
#define Math_aux_h

#include "Arduino.h"

// solving equations functions
class EquationSolver {
private:
  double (*f)(double);
  double a = 0, b = 0;
  double pendiente = 0;
  double point_to_reach = 0;

  double N_aprox();
  double P_aprox();

public:
  double tolerance = 0.00001, step_aproximation = 5;  //max aprox 0.000000000000001
  unsigned long aproximations = 3000;
  double solve_equation(double (*f_)(double), double a_, double b_, double point_to_reach_);
};


//Math Auxiliar
double abs_2(double in);
double map_double(short unsigned x, int in_min, int in_max, int out_min, int out_max);
double map_double(int x, int in_min, int in_max, int out_min, int out_max);
double map_double(double x, int in_min, int in_max, int out_min, int out_max);
double round_2(double in, short unsigned decimals);


//Smoothing Variables
class Smooth {
private:

  long unsigned rest = 0;
  double last_value;


public:

  double smoothed_value;

  //adjustement parameters
  float percent_value;
  unsigned cycle_time;

  Smooth(float percent_value_, unsigned cycle_time_, double first_value);

  double getSmoothed(double in_value);
  double getSmoothed(float in_value);
  double getSmoothed(int in_value);
};



#endif
