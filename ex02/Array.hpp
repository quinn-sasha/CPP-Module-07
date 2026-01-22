#ifndef EX02_ARRAY_HPP_
#define EX02_ARRAY_HPP_

#include <cstddef>

template <typename T>
class Array {
  std::size_t num_elmes_;
  T* array_;

 public:
  Array() : num_elmes_(0), array_(0) {}
  Array(unsigned int n) : num_elmes_(n) { array_ = new T[n]; }
};

#endif  // EX02_ARRAY_HPP_
