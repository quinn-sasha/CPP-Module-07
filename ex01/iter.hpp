#ifndef EX01_ITER_HPP_
#define EX01_ITER_HPP_

#include <cstddef>

template <typename T, typename FuncType>
void iter(T* array, const std::size_t num_elems, FuncType func) {
  for (std::size_t i = 0; i < num_elems; i++) {
    func(array[i]);
  }
}

#endif  // EX01_ITER_HPP_
