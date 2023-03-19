#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "Iterator.hpp"

#include "MyArray/MyArray.hpp"

using namespace SAO::MyArray;

int main() {
  const size_t arr_size = 32;
  MyArray<arr_size> arr;
  std::strncpy(arr.contents, "Hello, World!", arr_size);

  std::printf((const char *)arr);
  std::putchar('\n');

  for (auto result : arr.iter_forwards()) {
    std::putchar(result.c);
  }
  std::putchar('\n');

  for (auto result : arr.iter_backwards()) {
    std::putchar(result.c);
  }
  std::putchar('\n');

  return EXIT_SUCCESS;
}
