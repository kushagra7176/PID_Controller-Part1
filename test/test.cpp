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
 * @brief Test for GainValues() method of the PidController class.
 * It checks whether the gain values set by the user are being correctly returned by the method or not.
 */

TEST(CheckGainValues, should_pass) {
  PID::PidController PidTest;
  std::vector<double> values;
  values = PidTest.GainValues(1, 2, 3);
  std::vector<double> CheckValues = { 1.0, 2.0, 3.0 };
  int i = 0;
  /** This range based loop iterates over the values returned by
   * GainValues() method and they should match the CheckValues.
   */
  for (auto &value : values) {
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
  PidTest.GainValues(1, 2, 3);
  double ErrorCheck = PidTest.ComputeError(4, 6, 1);
  // Expect a return value of 10.0 for the given input values.
  ASSERT_EQ(10.0, ErrorCheck);
}

