#pragma once

#include <unistd.h>

namespace SAO::Iterator {

  template <typename TIterable, typename TIterator>
  struct IteratorFactory {
    const TIterable &iterable;

    IteratorFactory(const TIterable &iterable);

    TIterator begin();

    ssize_t end();
  };

}
