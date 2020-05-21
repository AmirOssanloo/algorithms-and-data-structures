#include <stdio.h>
#include <stdlib.h>

struct Array {
  int a[20];
  int size;
  int length;
};

// Find multiple missing elements in a sorted sequenced array (starting at any number)
int main() {
  struct Array arr = {{6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19}, 20, 11};

  int low = arr.a[0];
  int high = arr.a[arr.length - 1];
  int diff = arr.a[0];
  int missing;
  int i;

  for (i = 0; i < arr.length; i++) {
    if (arr.a[i] - i != diff) {
      while (diff < arr.a[i] - i) {
        missing = diff + i;
        printf("The missing number is %d\n", missing);
        diff++;
      }
    }
  }

  return 0;
};
