# libSAOCPPIterator

Some templates for C++ STL-style iterators.

I don't care about being able to reverse through an iterator therefore `end()` returns `ssize_t -1`, and the logic in the constructor, `!=`, and `++` operators work out when the iterator has finished. We just want simple forward iterators like Python has.

## IteratorFactory

Template struct which only needs its template arguments supplying

```cpp
template <typename TIterable, typename TIterator>
struct IteratorFactory {
  const TIterable &iterable;

  IteratorFactory(const TIterable &iterable);

  TIterator begin();

  ssize_t end();
};
```

returned by a method of a struct we want to be iterable iterable, eg

```cpp
template <size_t Size>
SAO::Iterator::IteratorFactory<MyArray<Size>, Iterators::Forwards::Iterator<Size>> MyArray<Size>::iter_forwards() {
  return SAO::Iterator::IteratorFactory<MyArray<Size>, Iterators::Forwards::Iterator<Size>>(*this);
}
```

and used in code like

```cpp
for (auto result : arr.iter_forwards()) {
  std::putchar(result.c);
}
```

## Iterator

Abstract struct containing methods for an iterator to implement

```cpp
template <typename TIterable, typename TState, typename TResult>
struct Iterator {
  const TIterable &iterable;
  TState state;

  Iterator(const TIterable &iterable);

  virtual ~Iterator() = default;

  virtual TResult operator*() = 0;

  virtual bool operator!=(const ssize_t &i) = 0;

  virtual void operator++() = 0;
};
```

eg a user-made array's iterator may look like

```cpp
template <size_t Size>
struct Iterator : SAO::Iterator::Iterator<MyArray<Size>, State, Result> {
  Iterator(const MyArray<Size> &iterable);

  Result operator*();

  bool operator!=(const ssize_t &i);

  void operator++();
};
```

with implementation

```cpp
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
```

See `./test/hello-world/MyArray` for more
