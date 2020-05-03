#include <stdio.h>

int fn(int n) {
  static int x = 0;

  if (n > 0) {
    x++;

    return fn(n - 1) + x;
  }

  return 0;
}

int main() {
  int a = 5;
  printf("Result: %d\n", fn(a));
  return 0;
}
