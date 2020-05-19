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

int isSorted(struct Array arr) {
  int i;

  for (i = 0; i < arr.length - 1; i++) {
    if (arr.a[i] > arr.a[i + 1]) {
      return 0;
    }
  }

  return 1;
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

void Reverse(struct Array *arr) {
  int i;
  int j;

  for (i = 0, j = arr->length - 1; i < j; i++, j--) {
    swap(&arr->a[i], &arr->a[j]);
  }
};

void Rearrange(struct Array *arr) {
  int i = 0;
  int j = arr->length - 1;

  while (i < j) {
    while (arr->a[i] < 0) i++;
    while (arr->a[j] >= 0) j--;


    if (i < j) swap(&arr->a[i], &arr->a[j]);
  }
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
};

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
};

void LeftShift(struct Array *arr) {
  int temp;
  int i;

  for (i = 0; i < arr->length; i++) {
    if (i < arr->length - 1) arr->a[i] = arr->a[i + 1];
    else arr->a[i] = 0;
  }
};

void RightShift(struct Array *arr) {
  int temp;
  int i;

  for (i = arr->length - 1; i >= 0; i--) {
    if (i > 0) arr->a[i] = arr->a[i - 1];
    else arr->a[i] = 0;
  }
};

void InsertSort(struct Array *arr, int x) {
  int i = arr->length - 1;

  if (arr->length == arr->size) {
    return;
  }

  while (i >= 0 && arr->a[i] > x) {
    arr->a[i + 1] = arr->a[i];
    i--;
  }

  arr->a[i + 1] = x;
  arr->length++;
};

struct Array* Merge(struct Array *arr1, struct Array *arr2) {
  int i = 0;
  int j = 0;
  int k = 0;

  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

  while (i < arr1->length && j < arr2->length) {
    if (arr1->a[i] < arr2->a[j]) {
      arr3->a[k++] = arr1->a[i++];
    } else {
      arr3->a[k++] = arr2->a[j++];
    }
  }

  for(; i < arr1->length; i++) {
    arr3->a[k++] = arr1->a[i];
  }

  for(; j < arr2->length; j++) {
    arr3->a[k++] = arr2->a[j];
  }

  arr3->length = arr1->length + arr2->length;
  arr3->size = arr3->length;

  return arr3;
};

struct Array* Union(struct Array *arr1, struct Array *arr2) {
  int i = 0;
  int j = 0;
  int k = 0;

  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

  while (i < arr1->length && j < arr2->length) {
    if (arr1->a[i] < arr2->a[j]) {
      arr3->a[k++] = arr1->a[i++];
    } else if (arr2->a[j] < arr1->a[i]) {
      arr3->a[k++] = arr2->a[j++];
    } else {
      arr3->a[k++] = arr1->a[i++];
      j++;
    }
  }

  for(; i < arr1->length; i++) {
    arr3->a[k++] = arr1->a[i];
  }

  for(; j < arr2->length; j++) {
    arr3->a[k++] = arr2->a[j];
  }

  arr3->length = k;
  arr3->size = arr3->length;

  return arr3;
};

struct Array* Intersection(struct Array *arr1, struct Array *arr2) {
  int i = 0;
  int j = 0;
  int k = 0;

  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

  while (i < arr1->length && j < arr2->length) {
    if (arr1->a[i] < arr2->a[j]) {
      i++;
    } else if (arr2->a[j] < arr1->a[i]) {
      j++;
    } else {
      arr3->a[k++] = arr1->a[i++];
      j++;

    }
  }

  arr3->length = k;
  arr3->size = arr3->length;

  return arr3;
};

struct Array* Difference(struct Array *arr1, struct Array *arr2) {
  int i = 0;
  int j = 0;
  int k = 0;

  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

  while (i < arr1->length && j < arr2->length) {
    if (arr1->a[i] < arr2->a[j]) {
      arr3->a[k++] = arr1->a[i++];
    } else if (arr2->a[j] < arr1->a[i]) {
      j++;
    } else {
      i++;
      j++;
    }
  }

  for(; i < arr1->length; i++) {
    arr3->a[k++] = arr1->a[i];
  }

  arr3->length = k;
  arr3->size = arr3->length;

  return arr3;
};


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

int Min(struct Array arr) {
  int min = arr.a[0];
  int i;

  for (i = 1; i < arr.length; i++) {
    if (arr.a[i] < min) {
      min = arr.a[i];
    }
  }

  return min;
};

int Max(struct Array arr) {
  int max = arr.a[0];
  int i;

  for (i = 1; i < arr.length; i++) {
    if (arr.a[i] > max) {
      max = arr.a[i];
    }
  }

  return max;
};

int Sum(struct Array arr) {
  int sum = 0;
  int i;

  for (i = 0; i < arr.length; i++) {
    sum += arr.a[i];
  }

  return sum;
};

float Avg(struct Array arr) {
  return (float)Sum(arr) / arr.length;
};

int main() {
  struct Array arr1 = {{2, 3, 4, 6, 7, 8, 12, 14}, 20, 8};
  struct Array arr2 = {{1, 3, 7, 10, 12, 14}, 20, 6};
  struct Array *arr3;

  Display(*arr3);

  return 0;
};
