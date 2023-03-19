#pragma once

#include <unistd.h>
#include <cstdlib>

#include "../20-declarations/Iterators/Backwards/Iterator.hpp"
#include "../20-declarations/Iterators/Forwards/Iterator.hpp"
#include "../20-declarations/MyArray.hpp"

namespace SAO::MyArray {

  template <size_t Size>
  MyArray<Size>::MyArray() : contents(nullptr) {
    contents = (char *)std::calloc(Size, 1);
  }

  template <size_t Size>
  MyArray<Size>::MyArray(const MyArray<Size> &other) : contents(nullptr) {
    contents = (char *)std::malloc(Size);
    std::memcpy(contents, other.contents, Size);
  }

  template <size_t Size>
  MyArray<Size> &MyArray<Size>::operator=(const MyArray<Size> &other) {
    std::memcpy(contents, other.contents, Size);
    return *this;
  }

  template <size_t Size>
  MyArray<Size>::~MyArray() {
    std::free(contents);
  }

  template <size_t Size>
  SAO::Iterator::IteratorFactory<MyArray<Size>, Iterators::Backwards::Iterator<Size>> MyArray<Size>::iter_backwards() {
    return SAO::Iterator::IteratorFactory<MyArray<Size>, Iterators::Backwards::Iterator<Size>>(*this);
  }

  template <size_t Size>
  SAO::Iterator::IteratorFactory<MyArray<Size>, Iterators::Forwards::Iterator<Size>> MyArray<Size>::iter_forwards() {
    return SAO::Iterator::IteratorFactory<MyArray<Size>, Iterators::Forwards::Iterator<Size>>(*this);
  }

  template <size_t Size>
  MyArray<Size>::operator const char *() {
    return contents;
  }

}
