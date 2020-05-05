#include <stdio.h>

int ncr(int n, int r) {
  if (n == r || r == 0) {
    return 1;
  }

  return ncr(n - 1, r-1) + ncr(n - 1, r);
}

int main() {
  int result = ncr(5, 3);

  printf("Result: %d\n", result);

  return 0;
}
