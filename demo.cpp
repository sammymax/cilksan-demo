#include <iostream>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>

int x = 0;

void increment(int amt) {
  cilk_for (int i = 0; i < 1000; i++)
    for (int j = 0; j < 1000000; j++)
      x ^= 3 - 2 * x;
}

int main() {
  std::cout << x << '\n';
  cilk_spawn increment(10);
  increment(10);
  std::cout << x << '\n';
}
