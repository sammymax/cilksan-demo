#include <iostream>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>

void increment(int* x) {
  *x ^= 3 - 2 * (*x);
}

int main() {
  int *x = (int*)malloc(sizeof(int));
  *x = 0;

  std::cout << *x << '\n';
  increment(x);
  increment(x);
  std::cout << *x << '\n';
}
