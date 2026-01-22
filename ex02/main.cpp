#include <exception>
#include <iostream>

#include "Array.hpp"

int main() {
  Array<int> int_arr;
  std::cout << "Empty array size: " << int_arr.size() << "\n";

  Array<double> double_arr(10);
  for (int i = 0; i < 10; i++) {
    double_arr[i] = i;
  }
  for (int i = 0; i < 10; i++) {
    std::cout << double_arr[i] << " ";
  }
  std::cout << "\n";
  for (int i = 0; i < 10; i++) {
    double_arr[i] = 42.0;
  }
  for (int i = 0; i < 10; i++) {
    std::cout << double_arr[i] << " ";
  }
  std::cout << "\n";

  Array<double> double_arr2 = double_arr;
  std::cout << "Copied array size: " << double_arr2.size() << "\n";

  try {
    double_arr[-1] = 0;
  } catch (const std::exception& e) {
    std::cerr << "Caught: " << e.what() << "\n";
  }
  try {
    double_arr[100] = 0;
  } catch (const std::exception& e) {
    std::cerr << "Caught: " << e.what() << "\n";
  }
}
