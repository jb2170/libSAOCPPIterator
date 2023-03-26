#pragma once

namespace SAO::Iterator {

  template <typename TIterable, typename TState, typename TResult>
  struct Iterator {
    TIterable &iterable;
    TState state;

    Iterator(TIterable &iterable);

    virtual ~Iterator() = default;

    virtual TResult operator*() = 0;

    virtual bool operator!=(const ssize_t &i) = 0;

    virtual void operator++() = 0;
  };

}
