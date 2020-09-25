/**
 * @file test.cpp
 * @brief This file contains the tests for the PidController Class.
 * @Created on: Sep 23, 2020
 * @cpoyright 2020
 * @copyright owner : Kushagra Agrawal, Sneha Nayak
 */
#include <gtest/gtest.h>

#include "../include/PidController.h"

/**
 * @brief Test for GetGainValues() method of the PidController class.
 * It checks whether the gain values set by the user are being correctly returned by the method or not.
 */

TEST(CheckGainValues, should_pass) {
  PID::PidController PidTest;
  PidTest.SetGainValues(1, 2, 3);
  std::vector<double> CheckValues = { 1.0, 2.0, 3.0 };
  int i = 0;
  /** This range based loop iterates over the values returned by
   * GetGainValues() method and they should match the CheckValues.
   */
  for (auto &value : PidTest.GetGainValues()) {
    ASSERT_EQ(value, CheckValues[i]);
    i++;
  }
}

/**
 * @ brief This is a test for the Compute Error method.
 * This checks whether the computed error is equal to the expected value or not.
 */

TEST(FormulaCheck, should_pass) {
  PID::PidController PidTest;
  PidTest.SetGainValues(1, 2, 3);
  double ErrorCheck = PidTest.ComputeError(6, 4, 1);
  // Expect a return value of 9.0 for the given input values.
  ASSERT_EQ(9.0, ErrorCheck);
}
