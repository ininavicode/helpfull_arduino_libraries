// #include <DF-Print.h>
#include "Math_aux.h"

// solving equations functions

double EquationSolver::solve_equation(double (*f_)(double), double a_, double b_, double point_to_reach_) {
  a = a_;
  b = b_;
  f = f_;
  point_to_reach = point_to_reach_;

  // DEBUG_PRINT("\nIntervalo(x) ({}, {})", a, b);
  // DEBUG_PRINT("\nIntervalo(y) ({}, {})", f(a), f(b));

  pendiente = (f(b) - f(a)) / (b - a);

  // DEBUG_PRINT("\nPendiente = ({})\n", pendiente);

  if (pendiente < 0) return N_aprox();
  if (pendiente > 0) return P_aprox();
}


double EquationSolver::N_aprox() {
  // Serial.println("\nAproximation N started...");

  for (int i = 0; i <= aproximations; i++) {

    if (f(a) <= point_to_reach) a -= (b - a) / step_aproximation;
    if (f(b) >= point_to_reach) b += (b - a) / step_aproximation;

    if (f(a) > point_to_reach and f(b) < point_to_reach) {
      a += (b - a) / step_aproximation;
      b -= (b - a) / step_aproximation;
    }

    //cout<<"Round " << i << endl << "a = " << a << endl << "b = " << b << endl;
    //cout<< "f(a) = " << f(a) << endl << "f(b) = " << f(b) << endl;

    if (abs_2((f(a) + f(b) / 2) - point_to_reach) > tolerance and i > aproximations*0.75) {
      // DEBUG_PRINT("\nAB: Reached in x = {}, with {} aproximations", round_2((a + b) / 2, 2), i);
      return round((a + b) / 2);
    } else if (f(a) == point_to_reach) {
      // DEBUG_PRINT("\nA: Reached in x = {}, with {} aproximations", round_2(a, 2), aproximations);
      return a;
    } else if (f(b) == point_to_reach) {
      // DEBUG_PRINT("\nB: Reached in x = {}, with {} aproximations", round_2(b, 2), aproximations);
      return b;
    }
    if (i > aproximations - 10) {
      Serial.print("COULD NOT REACH f(x) = ");
      Serial.println(point_to_reach);
      return sqrt(-1);
    }
  }
  // DEBUG_PRINT("\na = {} \n b = {} \n", a, b);
  // DEBUG_PRINT("\nf(a) = {} \n f(b) = {} \n", f(a), f(b));
}

double EquationSolver::P_aprox() {

  // Serial.println("\nAproximation P started...");

  for (int i = 0; i <= aproximations; i++) {

    if (f(a) >= point_to_reach) a -= (b - a) / step_aproximation;
    if (f(b) <= point_to_reach) b += (b - a) / step_aproximation;

    if (f(a) < point_to_reach and f(b) > point_to_reach) {
      a += (b - a) / step_aproximation;
      b -= (b - a) / step_aproximation;
    }

    //cout<<"Round " << i << endl << "a = " << a << endl << "b = " << b << endl;
    //cout<< "f(a) = " << f(a) << endl << "f(b) = " << f(b) << endl;

    if (abs_2((f(a) + f(b) / 2) - point_to_reach) > tolerance and i > aproximations*0.75) {
      // DEBUG_PRINT("\nAB: Reached in x = {}, with {} aproximations", round_2((a + b) / 2, 2), i);
      return round((a + b) / 2);
    } else if (f(a) == point_to_reach) {
      // DEBUG_PRINT("\nA: Reached in x = {}, with {} aproximations", round_2(a, 2), aproximations);
      return a;
    } else if (f(b) == point_to_reach) {
      // DEBUG_PRINT("\nB: Reached in x = {}, with {} aproximations", round_2(b, 2), aproximations);
      return b;
    }

    if (i > aproximations - 10) {
      Serial.print("COULD NOT REACH f(x) = ");
      Serial.println(point_to_reach);
      return sqrt(-1);
    }
  }
  // DEBUG_PRINT("\na = {} \n b = {} \n", a, b);
  // DEBUG_PRINT("\nf(a) = {} \n f(b) = {} \n", f(a), f(b));
}
// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

//Math Auxiliar
double abs_2(double in) {
  if (in < 0) return (-in);
  else return in;
}
double map_double(short unsigned x, int in_min, int in_max, int out_min, int out_max) {
  return double(x - in_min) * double(out_max - out_min) / double(in_max - in_min) + out_min;
}
double map_double(int x, int in_min, int in_max, int out_min, int out_max) {
  return double(x - in_min) * double(out_max - out_min) / double(in_max - in_min) + out_min;
}
double map_double(double x, int in_min, int in_max, int out_min, int out_max) {
  return double(x - in_min) * double(out_max - out_min) / double(in_max - in_min) + out_min;
}

double round_2(double in, short unsigned decimals) {
  unsigned converter = pow(10, decimals);
  int int_num = in * converter;
  return (double)int_num / converter;
}

Smooth::Smooth(float percent_value_, unsigned cycle_time_, double first_value) {
  percent_value = percent_value_;
  cycle_time = cycle_time_;
  smoothed_value = last_value = first_value;
}

double Smooth::getSmoothed(double in_value) {
  double value = in_value;

  if (millis() - rest > cycle_time) {
    if (smoothed_value != value) {
      smoothed_value = (value * (1 - percent_value) + (last_value * percent_value));
      last_value = smoothed_value;
    }
    rest = millis();
  }
  return smoothed_value;
}

double Smooth::getSmoothed(float in_value) {
  float value = in_value;

  if (millis() - rest > cycle_time) {
    if (smoothed_value != value) {
      smoothed_value = (value * (1 - percent_value) + (last_value * percent_value));
      last_value = smoothed_value;
    }
    rest = millis();
  }
  return smoothed_value;
}

double Smooth::getSmoothed(int in_value) {
  float value = (float)in_value;

  if (millis() - rest > cycle_time) {
    if (smoothed_value != value) {
      smoothed_value = (value * (1 - percent_value) + (last_value * percent_value));
      last_value = smoothed_value;
    }
    rest = millis();
  }
  return smoothed_value;
}
