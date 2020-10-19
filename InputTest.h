#ifndef INPUT_TEST_INPUTTEST_H
#define INPUT_TEST_INPUTTEST_H

#include <fstream>
#include "TestMode.h"

class InputTest {
 public:
  InputTest();
  static double input_test(TestMode test_mode, const std::string& file_name);
 private:
  static void scanf_test();
  static void cin_test();
};

#endif //INPUT_TEST_INPUTTEST_H
