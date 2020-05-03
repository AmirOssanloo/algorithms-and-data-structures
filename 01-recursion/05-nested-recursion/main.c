#include <stdio.h>

int fn(int n) {
  if (n > 100) {
    return n - 10;
  }

  return fn(fn(n + 11));
}

int main() {
  int a = 95;
  int result = fn(a);

  printf("Result: %d\n", result);

  return 0;
}
