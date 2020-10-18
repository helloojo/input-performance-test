#include "OutputMaker.h"
#include <random>

OutputMaker::OutputMaker() = default;

/**
 * 10-32 길이의 random string 생성해서 파일에 계속 출력한다.
 * @param output_file_name 출력 파일 이름
 * @param sample_size 출력 파일의 줄 개수
 */
void OutputMaker::make_output_file(const std::string &output_file_name, int sample_size) {
  out.open(output_file_name, std::ios::out);
  for (int i = 0; i < sample_size; i++) {
    out << generate_random_string(generate_random_string_length()) << '\n';
  }
  out.close();
}

/**
 * string_length 만큼 A-Z로 구성된 random string을 반환한다.
 * @param string_length 생성 문자열 길이
 * @return 생성된 random string
 */
std::string OutputMaker::generate_random_string(int string_length) {
  std::string random_string;
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> range('A', 'Z');
  for (int i = 0; i < string_length; ++i) {
    random_string.push_back(range(mt));
  }
  return random_string;
}

/**
 * 10-32 범위의 난수를 반환한다.
 * @return 10-32 범위의 난수
 */
int OutputMaker::generate_random_string_length() {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> range(10, 32);
  return range(mt);
}
