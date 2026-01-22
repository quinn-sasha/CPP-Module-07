#include <cstddef>
#include <iostream>
#include <string>

#include "iter.hpp"

void display_integer(int x) { std::cout << x << ", "; }

void display_uppercase_string(std::string str) {
  int size = str.size();
  for (int i = 0; i < size; i++) {
    str[i] = std::toupper(str[i]);
  }
  std::cout << str << " ";
}

int main() {
  int int_arr[10];
  for (int i = 0; i < 10; i++) {
    int_arr[i] = (i + 1) * 2;
  }
  typedef void FuncType1(int);
  iter<int, FuncType1>(int_arr, 10, display_integer);
  std::cout << "\n";

  std::string string_array[5] = {"Hello", "world", "I", "love", "computer"};
  typedef void FuncType2(std::string);
  iter<std::string, FuncType2>(string_array, 5, display_uppercase_string);
  std::cout << "\n";

  const int c_int_array[3] = {42, 42, 42};
  typedef void FuncType3(const int);
  iter<const int, FuncType3>(c_int_array, 3, display_integer);
}
