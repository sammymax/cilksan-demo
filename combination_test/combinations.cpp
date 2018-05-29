#include <iostream>
#include <cilk/cilk.h>

__attribute__((noinline))
void read(int *x) {
  std::cout << *x << '\n';
}

__attribute__((noinline))
void write(int *x, int val = 13) {
  *x = val;
}

int main(int argc, char** argv) {
  // if you want just 1 of the 8 combinations, specify as bitmask
  int targ = (argc == 2) ? atoi(argv[1]) : -1;

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++) {
        if (targ != -1 && (4*i + 2*j + k) != targ) continue;

        int x = 9;
        std::string output = "\n\n\n\nTesting ";
        output += (i ? "r" : "_");
        output += (j ? "w" : "_");
        output += (k ? "w" : "r");
        std::cerr << output << ", reads in parallel\n";
        std::cerr << &x << ", addr x\n";

        // cilk_spawn read must be after write
        if (j) write(&x);
        if (i) cilk_spawn read(&x);
        if (k) {
          cilk_spawn write(&x);
        } else {
          cilk_spawn read(&x);
        }
        cilk_sync;

        int y = 10;
        std::cerr << output << ", writes in parallel\n";
        std::cerr << &y << ", addr y\n";
        if (i) read(&y);
        if (j) cilk_spawn write(&y, rand());
        if (k) {
          cilk_spawn write(&y, rand());
        } else {
          cilk_spawn read(&y);
        }
        cilk_sync;
      }
}
