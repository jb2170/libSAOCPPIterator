#pragma once

#include <unistd.h>

namespace SAO::Iterator {

  template <typename TIterable, typename TIterator>
  struct IteratorFactory {
    TIterable &iterable;

    IteratorFactory(TIterable &iterable);

    TIterator begin();

    ssize_t end();
  };

}
