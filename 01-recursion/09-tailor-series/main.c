 #include <stdio.h>

double tailor(int x, int n) {
  static double p = 1;
  static double f = 1;
  double r;

  if (n == 0) {
    return 1;
  }

  r = tailor(x, n - 1);
  p = p * x;
  f = f * n;

  return r + (p / f);
}

int main() {
  double result = tailor(1, 10);

  printf("Result: %lf\n", result);

  return 0;
}
