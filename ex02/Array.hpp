#ifndef EX02_ARRAY_HPP_
#define EX02_ARRAY_HPP_

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array {
  int num_elmes_;
  T* array_;

 public:
  Array() : num_elmes_(0), array_(0) {}
  explicit Array(unsigned int n) : num_elmes_(n) { array_ = new T[n]; }
  Array(const Array& other);
  Array& operator=(const Array& other);
  ~Array() { delete[] array_; }

  T& operator[](int index);
  std::size_t size() const;
};

// Implementaion

template <typename T>
Array<T>::Array(const Array& other) : num_elmes_(other.num_elmes_) {
  array_ = new T[num_elmes_];
  for (int i = 0; i < num_elmes_; i++) {
    this->array_[i] = other.array_[i];
  }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
  if (this == &other) {
    return *this;
  }
  delete array_;
  num_elmes_ = other.num_elmes_;
  array_ = new T[num_elmes_];
  for (int i = 0; i < num_elmes_; i++) {
    array_[i] = other.array_[i];
  }
  return *this;
}

template <typename T>
T& Array<T>::operator[](int index) {
  if (index < 0) {
    throw std::out_of_range("Index cannot be negative");
  }
  if (index >= num_elmes_) {
    throw std::out_of_range("Index out of range");
  }
  return array_[index];
}

template <typename T>
std::size_t Array<T>::size() const {
  return static_cast<std::size_t>(num_elmes_);
}

#endif  // EX02_ARRAY_HPP_
