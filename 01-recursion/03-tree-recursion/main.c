#include <stdio.h>

int fn(int n) {
  if (n > 0) {
    printf("Result: %d\n", n);

    fn(n - 1);
    fn(n - 1);
  }

  return 0;
}

int main() {
  int a = 3;
  fn(a);

  return 0;
}
