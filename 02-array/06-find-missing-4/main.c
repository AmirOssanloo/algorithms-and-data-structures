#include <stdio.h>
#include <stdlib.h>

struct Array {
  int a[20];
  int size;
  int length;
};

// Find multiple missing elements in an unsorted array
int main() {
  struct Array arr = {{3, 7, 4, 9, 12, 6, 1, 11, 2, 10}, 20, 10};
  struct Array aux = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 20, 10};

  int i;
  int j;

  for (i = 0; i < arr.length; i++) {
    aux.a[arr.a[i]]++;
  }

  for (j = 1; j < aux.length; j++) {
    if (aux.a[j] == 0) {
      printf("The missing number is %d\n", j);
    }
  }

  return 0;
};
