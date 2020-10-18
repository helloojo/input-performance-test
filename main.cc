#include <iostream>
#include <string>
#include "OutputMaker.h"

enum {
  ERROR = -1, INPUT_TEST, OUTPUT_MAKE
};

enum TestMode {
  SCANF,
  CIN_SYNC_WITH_STDIO_TRUE,
  CIN_SYNC_WITH_STDIO_FALSE
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
    case INPUT_TEST:
      break;
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
      case 'm':
        test_mode = static_cast<TestMode>(atoi(argv[i++]));
        break;
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
                                        "\t-f filename\tInput/Output File Name\n"
                                        "\t-m MODE\t\tTest Mode(0:scanf, 1:cin(sync_with_stdio(true)), 2:cin(sync_with_stdio(false), Only Input Mode)\n";
}
