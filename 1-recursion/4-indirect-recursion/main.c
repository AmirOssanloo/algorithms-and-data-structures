#include <stdio.h>

void fnA(int n);
void fnB(int n);

void fnA(int n) {
  if (n > 0) {
    printf("fnA: %d\n", n);

    fnB(n - 1);
  }
}

void fnB(int n) {
  if (n > 1) {
    printf("fnB: %d\n", n);

    fnA(n /2);
  }
}

int main() {
  int a = 20;
  fnA(a);

  return 0;
}
