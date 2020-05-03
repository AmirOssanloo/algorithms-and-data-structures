#include <stdio.h>

int factorial(int n) {
  if (n == 0) {
    return 1;
  }

  return factorial(n - 1) * n;
}

int main() {
  int a = 5;
  int result = factorial(a);

  printf("Result: %d\n", result);

  return 0;
}

/*
Can also be written with loops:
int factorial(int n) {
  int total = 1;

  for (int i = 1; i <= n; i++) {
    total *= i;
  }

  return total;
}
*/
