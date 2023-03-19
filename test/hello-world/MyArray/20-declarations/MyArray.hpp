#pragma once

#include <unistd.h>

#include "20-declarations/IteratorFactory.hpp"
#include "../10-forward-declarations/Iterators/Backwards/Iterator.hpp"
#include "../10-forward-declarations/Iterators/Forwards/Iterator.hpp"
#include "../10-forward-declarations/MyArray.hpp"

namespace SAO::MyArray {

  template <size_t Size>
  struct MyArray {
    char *contents;

    MyArray();

    MyArray(const MyArray<Size> &other);

    MyArray<Size> &operator=(const MyArray<Size> &other);

    ~MyArray();

    SAO::Iterator::IteratorFactory<MyArray<Size>, Iterators::Backwards::Iterator<Size>> iter_backwards();

    SAO::Iterator::IteratorFactory<MyArray<Size>, Iterators::Forwards::Iterator<Size>> iter_forwards();

    operator const char *();
  };

}
