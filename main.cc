#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "OutputMaker.h"
#include "InputTest.h"
#include "TestMode.h"

enum {
  ERROR = -1, INPUT_TEST, OUTPUT_MAKE
};

static std::string file_name;
static int sample_size;
static TestMode test_mode;

int parse_options(int argc, const char *argv[]);

void print_usage(const char *exe_name);

int main(int argc, const char *argv[]) {
  int mode = parse_options(argc, argv);
  OutputMaker output_maker;

  switch (mode) {
    case INPUT_TEST: {
      double result = InputTest::input_test(test_mode, file_name);
      if (result == -1.) {
        std::cerr << "Test Error\n";
        return -1;
      }
      std::cout << "Test Result: " << result << " ms\n";
      break;
    }
    case OUTPUT_MAKE:
      output_maker.make_output_file(file_name, sample_size);
      break;
    case ERROR:
    default:
      print_usage(argv[0]);
      return -1;
  }
  return 0;
}

int parse_options(int argc, const char *argv[]) {
  int i = 1;
  int result = ERROR;
  while (i < argc) {
    if (argv[i][0] != '-') {
      return ERROR;
    }
    size_t len = strlen(argv[i]);
    if (len != 2) {
      return ERROR;
    }
    switch (argv[i++][1]) {
      case 'i':
        result = INPUT_TEST;
        break;
      case 'o':
        result = OUTPUT_MAKE;
        break;
      case 's':
        sample_size = atoi(argv[i++]);
        break;
      case 'f':
        file_name = argv[i++];
        break;
      case 'm': {
        int parse_int = atoi(argv[i++]);
        if (parse_int < SCANF || parse_int > CIN_SYNC_WITH_STDIO_FALSE_TIE_NULLPTR) {
          return ERROR;
        }
        test_mode = static_cast<TestMode>(parse_int);
        break;
      }
      default:
        return ERROR;
    }
  }
  return result;
}

void print_usage(const char *exe_name) {
  std::cerr << "Usage: " << exe_name << " [OPTION]...\n"
                                        "\t-i\t\tInput Test\n"
                                        "\t-o\t\tOutput File Make\n"
                                        "\t-s sample size\tOutput File Line Size(Only Output Mode)\n"
                                        "\t-f filename\tOutput File Name\n"
                                        "\t-m MODE\t\tTest Mode\n"
                                        "\t\t\t1  scanf\n"
                                        "\t\t\t2  cin, sync_with_stdio(true)\n"
                                        "\t\t\t3  cin, sync_with_stdio(false)\n"
                                        "\t\t\t4  cin, sync_with_stdio(false), cin.tie(nullptr)\n";
}
