#include <stdio.h>
#include <stdlib.h>

struct Array {
  int a[20];
  int size;
  int length;
};

// Find single missing element in a sorted sequenced array (starting at 1)
int main() {
  struct Array arr = {{1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12}, 20, 11};

  int sum = 0;
  int last = arr.a[arr.length - 1];
  int missing;
  int i;

  for (i = 0; i < arr.length; i++) {
    sum += arr.a[i];
  }

  missing = (last * (last + 1) / 2) - sum;
  printf("The missing number is %d\n", missing);

  return 0;
};
