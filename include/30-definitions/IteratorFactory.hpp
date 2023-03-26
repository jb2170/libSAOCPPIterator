#pragma once

#include "../20-declarations/IteratorFactory.hpp"

namespace SAO::Iterator {

  template <typename TIterable, typename TIterator>
  IteratorFactory<TIterable, TIterator>::IteratorFactory(TIterable &iterable) : iterable(iterable) {}

  template <typename TIterable, typename TIterator>
  TIterator IteratorFactory<TIterable, TIterator>::begin() {
    return TIterator(this->iterable);
  }

  template <typename TIterable, typename TIterator>
  ssize_t IteratorFactory<TIterable, TIterator>::end() {
    return -1; /* can be anything really; unused */
  }

}
