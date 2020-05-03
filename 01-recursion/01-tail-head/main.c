#include <stdio.h>

void tail(int n) {
  if (n > 0) {
    printf("%d ", n);
    tail(n - 1);
  }
}

void head(int n) {
  if (n > 0) {
    head(n - 1);
    printf("%d ", n);
  }
}

int main() {
  int x = 3;

  printf("Tail: \n");
  tail(x);
  printf("\n\n");

  printf("Head: \n");
  head(x);
  printf("\n");

  return 0;
}
