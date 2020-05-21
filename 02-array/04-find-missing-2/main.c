#include <stdio.h>
#include <stdlib.h>

struct Array {
  int a[20];
  int size;
  int length;
};

// Find single missing element in a sorted sequenced array (starting at any number)
int main() {
  struct Array arr = {{6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17}, 20, 11};

  int low = arr.a[0];
  int high = arr.a[arr.length - 1];
  int diff = arr.a[0];
  int missing;
  int i;

  for (i = 0; i < arr.length; i++) {
    if (arr.a[i] - i != diff) {
      missing = arr.a[i] - 1;
      printf("The missing number is %d\n", missing);
      break;
    }
  }

  return 0;
};
