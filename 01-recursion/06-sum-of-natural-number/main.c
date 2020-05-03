#include <stdio.h>

int sum(int n) {
  if (n == 0) {
    return 0;
  }

  return sum(n - 1) + n;
}

int main() {
  int a = 5;
  int result = sum(a);

  printf("Result: %d\n", result);

  return 0;
}

/*
Can also be written as:
---------------------------
int sum(int n) {
  return n * (n + 1) / 2;
}

Or with loops:
---------------------------
int sum(int n) {
  int total = 0;

  for (int i = 0; i <= n; i++) {
    total += i;
  }

  return total;
}
*/
