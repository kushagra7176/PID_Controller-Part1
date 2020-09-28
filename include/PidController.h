/**
 * @file PidController.h
 * @brief This file contains declarations for the PidController Class.
 * @Created on: Sep 23, 2020
 * @cpoyright 2020
 * @copyright owner : Kushagra Agrawal, Sneha Nayak
 */

#pragma once

#include<iostream>
#include<string>
#include<vector>

namespace PID {
class PidController {
 private:
  // Variable declaration for proportional, integral and differential gains.
  double Kp, Ki, Kd;
  // Control error for the controller.
  double ControlError;
  // Cumulative error for the controller.
  double CumulativeError;

 public:
  /**
   * @brief default constructor
   */
  PidController();

  /**
   * @brief This function sets the gain values for the PID controller.
   * @param kp This is the proportional controller gain.
   * @param ki This is the integral controller gain.
   * @param kd This is the differential controller gain.
   */
  void SetGainValues(double kp, double ki, double kd);

  /**
   * @brief This function gets the gain values for the PID controller.
   * @return It returns a double vector which has the gain values.
   */
  std::vector<double> GetGainValues();

  /**
   * @brief This function implements the error formula for the PID controller
   * for a given fixed point and the input. This is calculated at a particular
   * time instant. It outputs the new velocity and the control error.
   * @param TargetVelocity This is the target velocity to be tracked by the controller.
   * @param InputVelocity This is the input velocity.
   * @param PreviousError This is the error from the previous instance at which
   *                  PID controller error was calculated.
   * @return Control Error of data type double.
   */
  double ComputeError(double TargetVelocity, double InputVelocity,
                      double PreviousError);

  /**
   * @brief default destructor
   */
  ~PidController();
};
}  // namespace PID
