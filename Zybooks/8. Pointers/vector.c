#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  vector v;
  vector_create(&v, 4);

  *vector_get(&v, 0) = 27;
  *vector_get(&v, 1) = 44;
  *vector_get(&v, 2) = 9;
  *vector_get(&v, 3) = 17;

  vector_remove(&v, 1);
  vector_remove(&v, 0);
  vector_insert(&v, 0, 88);

  vector_pop(&v);

  printf("Contents:\n");
  for (int i = 0; i < vector_size(&v); ++i) {
    printf("%d\n", *vector_get(&v, i));
  }

  vector_destroy(&v);

  return 0;
}

// Initialize vector with specified size
void vector_create(vector* v, unsigned int vectorSize) {
  if (v == NULL)
    return;

  v->data = (int*)malloc(vectorSize * sizeof(int));
  v->size = vectorSize;

  for (int i = 0; i < v->size; ++i) {
    v->data[i] = 0;
  }
}

// Destroy vector
void vector_destroy(vector* v) {
  if (v == NULL)
    return;

  free(v->data);
  v->data = NULL;
  v->size = 0;
}

// Resize the size of the vector
void vector_resize(vector* v, unsigned int vectorSize) {
  if (v == NULL)
    return;

  int oldSize = v->size;
  v->data = (int*)realloc(v->data, vectorSize * sizeof(int));
  v->size = vectorSize;

  for (int i = oldSize; i < v->size; ++i) {
    v->data[i] = 0;
  }
}

// Return pointer to element at specified index
int* vector_get(vector* v, unsigned int index) {
  if (v == NULL || index >= v->size)
    return NULL;

  return &(v->data[index]);
}

// Insert new value at specified index
void vector_insert(vector* v, unsigned int index, int value) {
  if (v == NULL || index > v->size)
    return;

  vector_resize(v, v->size + 1);
  for (int i = v->size - 1; i > index; --i) {
    v->data[i] = v->data[i - 1];
  }

  v->data[index] = value;
}

// Insert new value at end of vector
void vector_push_back(vector* v, int value) {
  vector_insert(v, v->size, value);
}
// Remove value at specified index
void vector_remove(vector* v, unsigned int index) {
  if (v == NULL || index >= v->size)
    return;

  for (int i = index; i < v->size - 1; ++i) {
    v->data[i] = v->data[i + 1];
  }

  vector_resize(v, v->size - 1);
}

// Remove value at the last element
void vector_pop(vector* v) {
  if (v == NULL)
    return;

  vector_remove(v, v->size - 1);
}

// Return number of elements within vector
int vector_size(vector* v) {
  if (v == NULL)
    return -1;

  return v->size;
}
