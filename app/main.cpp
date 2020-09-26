/**
 * @file main.h
 * @brief This file contains the main function.
 * @Created on: Sep 23, 2020
 * @cpoyright 2020
 * @copyright owner : Kushagra Agrawal, Sneha Nayak
 */
#include<iostream>
#include<string>
#include<vector>

#include "../include/PidController.h"

/**
 * @fn main
 * @brief Main function
 * @detail Compute the Control error and the current velocity.
 * @return Program execution status
 */
int main() {
  PID::PidController Pid;
  Pid.SetGainValues(1, 2, 3);
  std::cout << Pid.ComputeError(1, 2, 3) << std::endl;
  return 0;
}

