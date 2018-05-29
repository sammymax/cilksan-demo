#include <iostream>
#include <stdexcept>
#include <cilk/cilk.h>

__attribute__((noinline))
void process(int *x) {
  (*x)++;
  if ((*x) % 101 == 0 && rand() > 4)
    throw std::invalid_argument("input divisible by 101!");
}

void increment(int *x, int n) {
  int counter = 0;
  for (int i = 0; i < n; i++) {
    process(x + i);
  }
  x[counter % n] -= counter;
}

int main(int argc, char** argv) {
  int n = 1;
  if (argc == 2) n = atoi(argv[1]);

  int *x = (int*)malloc(n * sizeof(int));

  cilk_for (int i = 0; i < 1000; i++) {
    try {
      increment(x, n);
    } catch (const std::invalid_argument& e) {
      x[rand() % n] += rand();
    }
  }

  std::cout << x[0] << '\n';
}
