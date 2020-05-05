# Recursion

### Question 1:
Consider the following  C function

```C
int fn(int n) {
  static int i = 1

  if (n >= 5) return n;

  n = n + i;

  i++;

  return fn(n);
}
```

Which is the value returned by fn(1): 

* 5
* 6
* 7
* 8

---

### Question 2:
Consider the following  C function

```C
void fn(int n, int sum) {
  int k = 0;
  int j = 0;

  if (n == 0) return;

  k = n % 10;
  j = n/10;
  sum = sum + k;

  fn(j, sum);

  printf(“%d”, k)
}

int main () {
  int a = 2048, sum = 0;

  fn (a, sum);

  printf(“%d\n”, sum);
}
```

Which sequence does the above program print?

* 8, 4, 0, 2, 14
* 8, 4, 0, 2, 0
* 2, 0, 4, 8, 14
* 2, 0, 4, 8, 0
