#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct array {
  int *array;
  int len;
  int space;
};

void createArray(struct array * a, int size) {
  a->array = malloc(sizeof(int) * size);
  a->len = 0;
  a->space = size;
};

void addElement(struct array * a, int element) {
  if (a->len == a->space) {
    printf("Add more memory please my dear computer!");
    a->space *= 2;
    a->array = realloc(a->array, sizeof(int) * a->space);
  } 
  a->len = a->len + 1;
  a->array[a->len] = element;
  printf(" %d", a->array[a->len]);
}

void freeArray(struct array * a) {
  free(a->array);
  a->array = NULL;
  a->len = 0;
  a->space = 0;
}

int main() {
  struct array newArr;
  createArray(&newArr, 1);

  for (int i = 0; i <= 20; i++) {
   addElement(&newArr, i);
  } 

  freeArray(&newArr);

  return 0;
}
