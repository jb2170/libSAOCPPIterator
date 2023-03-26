#pragma once

#include "../20-declarations/Iterator.hpp"

namespace SAO::Iterator {

  template <typename TIterable, typename TState, typename TResult>
  Iterator<TIterable, TState, TResult>::Iterator(TIterable &iterable) : iterable(iterable), state() {}

}
