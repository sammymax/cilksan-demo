#include <iostream>
#include <cilk/cilk.h>
//#include <cilk/cilk_api.h>

void increment(int *x, int n) {
  for (int i = 0; i < n; i++)
    x[i]++;
}

int main(int argc, char** argv) {
  int n = 1;
  if (argc == 2) n = atoi(argv[1]);

  int *x = (int*)malloc(n * sizeof(int));

  cilk_for (int i = 0; i < 1000; i++)
    increment(x, n);

  std::cout << x[0] << '\n';
}
