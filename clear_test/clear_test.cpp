#include <iostream>
#include <cilk/cilk.h>

__attribute__((noinline))
int test_func(const int n) {
  const int SZ = 320;

  int arr[SZ];
  int res = n;
  arr[0] = 1;
  // do random calculations throughout the entire array
  // goal: make sure every element is accessed, both read and write
  for (int i = 1; i < SZ; i++) {
    arr[i] = arr[i - 1] * res / 2 - 5;
    res += arr[i];
  }
  return res;
}

int main(int argc, char** argv) {
  int n = 1312;
  if (argc == 2) {
    n = atoi(argv[1]);
  }

  int a = cilk_spawn test_func(n);
  int b = cilk_spawn test_func(n + 10);

  std::cout << a << ' ' << b << '\n';
}
