#ifndef INPUT_TEST_OUTPUTMAKER_H
#define INPUT_TEST_OUTPUTMAKER_H

#include <fstream>
#include <iostream>

class OutputMaker {
 public:
  OutputMaker();
  void make_output_file(const std::string &output_file_name, int sample_size);
 private:
  std::ofstream out;
  std::string generate_random_string(int str_length);
  int generate_random_string_length();
};

#endif //INPUT_TEST_OUTPUTMAKER_H
