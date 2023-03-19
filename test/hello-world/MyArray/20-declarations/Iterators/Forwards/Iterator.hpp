#pragma once

#include <unistd.h>

#include "../../../../../../include/20-declarations/Iterator.hpp"
#include "../../../10-forward-declarations/Iterators/Forwards/Iterator.hpp"
#include "../../../10-forward-declarations/Iterators/Forwards/Result.hpp"
#include "../../../10-forward-declarations/Iterators/Forwards/State.hpp"
#include "../../../10-forward-declarations/MyArray.hpp"

namespace SAO::MyArray::Iterators::Forwards {

  template <size_t Size>
  struct Iterator : SAO::Iterator::Iterator<MyArray<Size>, State, Result> {
    Iterator(const MyArray<Size> &iterable);

    Result operator*();

    bool operator!=(const ssize_t &i);

    void operator++();
  };

}
