#include <stdexcept>
#include <iostream>
#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() : prev_cte(0) {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    this->initialized = true;
}

void PID::UpdateError(double cte) {
    if (!initialized)
        throw std::runtime_error("PID Controller not initialized!");

    p_error = cte;

    // initialize previous cte for d term
    if (prev_cte == 0) {
        prev_cte = cte;
        std::cout << "Initialized prev CTE\n";
    }
    d_error = cte - prev_cte; // divided by dt
    prev_cte = cte;

    i_error += cte;
}

double PID::TotalError() {
    if (!initialized)
        throw std::runtime_error("PID Controller not initialized!");

    std::cout << "ERRORS: " << p_error  << " * " << Kp << " (p), "
              << d_error << " * " << Kd<< " (d), "
              << i_error << " * " << Ki << " (i) ";
    double steer = -Kp * p_error - Kd * d_error - Ki * i_error;
    std::cout << " = " << steer << "\n";

    return steer;
}

