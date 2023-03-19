#pragma once

#include <unistd.h>

#include "../../../20-declarations/Iterators/Forwards/Iterator.hpp"
#include "../../../20-declarations/MyArray.hpp"

namespace SAO::MyArray::Iterators::Forwards {

  template <size_t Size>
  Iterator<Size>::Iterator(const MyArray<Size> &iterable) : SAO::Iterator::Iterator<MyArray<Size>, State, Result>(iterable) {
    this->state.position = 0;
  }

  template <size_t Size>
  Result Iterator<Size>::operator*() {
    Result ret;
    ret.c = this->iterable.contents[this->state.position];
    return ret;
  }

  template <size_t Size>
  bool Iterator<Size>::operator!=(const ssize_t &i) {
    return this->state.position != Size;
  }

  template <size_t Size>
  void Iterator<Size>::operator++() {
    this->state.position++;
  }

}
