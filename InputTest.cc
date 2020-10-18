#include "InputTest.h"
#include <iostream>
#include <chrono>
#include <functional>

InputTest::InputTest() = default;

double InputTest::input_test(TestMode test_mode) {
  std::function<void()> test_function;
  switch (test_mode) {
    case SCANF:
      test_function = scanf_test;
      break;
    case CIN_SYNC_WITH_STDIO_TRUE:
      std::ios_base::sync_with_stdio(true);
      test_function = cin_test;
      break;
    case CIN_SYNC_WITH_STDIO_FALSE:
      std::ios_base::sync_with_stdio(false);
      test_function = cin_test;
      break;
    default:
      return -1.;
  }

  auto start = std::chrono::system_clock::now();
  test_function();
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> result = end - start;

  return result.count() * 1000;
}

void InputTest::scanf_test() {
  char input[100];
  while (scanf("%s", input) != -1);
}

void InputTest::cin_test() {
  std::string input;
  while (std::cin >> input);
}
