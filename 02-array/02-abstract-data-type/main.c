#include <stdio.h>
#include <stdlib.h>

struct Array {
  int a[20];
  int size;
  int length;
};

void Display(struct Array arr) {
  int i;

  printf("Elements are:\n");

  for (i = 0; i < arr.length; i++) {
    printf("%d ", arr.a[i]);
  }

  printf("\n");
};

void Append(struct Array *arr, int x) {
  if (arr->length < arr->size) {
    arr->a[arr->length] = x;
  }

  arr->length++;
};

void Insert(struct Array *arr, int index, int x) {
  int i;

  if (index >= 0 && index <= arr->length) {

    for (i = arr->length; i > index; i--) {
      arr->a[i] = arr->a[i - 1];
    }

    arr->a[index] = x;
    arr->length++;
  }
};

int main() {
  struct Array arr = {{2, 3, 4, 5, 6}, 20, 5};

  Display(arr);
  Append(&arr, 8);
  Display(arr);
  Insert(&arr, 1, 0);
  Display(arr);

  return 0;
};
