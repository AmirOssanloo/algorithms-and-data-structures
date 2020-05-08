#include <stdio.h>
#include <stdlib.h>

struct Array {
  int a[20];
  int size;
  int length;
};

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
};

void Display(struct Array arr) {
  int i;

  printf("Elements are: ");

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

int Delete(struct Array *arr, int index) {
  int i;
  int x;

  if (index >= 0 && index <= arr->length) {
    x = arr->a[index];

    for (i = index; i < arr->length - 1; i++) {
      arr->a[i] = arr->a[i + 1];
    }

    arr->length--;

    return x;
  }

  return -1;
};

int LinearSearch(struct Array *arr, int key) {
  int i;

  for (i = 0; i < arr->length; i++) {
    if (arr->a[i] == key) {
      swap(&arr->a[i], &arr->a[i - 1]);

      return i;
    }
  }

  return -1;
}

int BinarySearch(struct Array arr, int key) {
  int low = 0;
  int high = arr.length - 1;
  int mid;

  while (low <= high) {
    mid = (low + high) / 2;

    if (key == arr.a[mid]) {
      return mid;
    }

    if (key < arr.a[mid]) high = mid - 1;
    if (key > arr.a[mid]) low = mid + 1;
  }

  return -1;
}

int Get(struct Array arr, int index) {
  if (index >= 0 && index < arr.length) {
    return arr.a[index];
  }

  return -1;
};

int Set(struct Array *arr, int index, int x) {
  if (index >= 0 && index < arr->length) {
    arr->a[index] = x;
    return arr->a[index];
  }

  return -1;
};

int main() {
  struct Array arr = {{2, 3, 4, 5, 6, 8, 10, 12, 14, 16, 18}, 20, 11};

  Display(arr);
  Append(&arr, 8);
  Display(arr);
  Insert(&arr, 1, 0);
  Display(arr);
  printf("Delete element: %d\n", Delete(&arr, 1));
  Display(arr);
  printf("LinearSearch element: %d\n", LinearSearch(&arr, 5));
  Display(arr);
  printf("BinarySearch element: %d\n", BinarySearch(arr, 14));
  printf("Set element: %d\n", Set(&arr, 4, 71));
  printf("Get element: %d\n", Get(arr, 4));
  Display(arr);

  return 0;
};
