#ifndef VECTOR_H
#define VECTOR_H

// struct and typedef declaration for Vector ADT
typedef struct vector_struct {
  int* data;
  unsigned int size;
} vector;

// interface for accessing Vector ADT

// Initialize vector
void vector_create(vector* v, unsigned int vectorSize);

// Destroy vector
void vector_destroy(vector* v);

// Resize the size of the vector
void vector_resize(vector* v, unsigned int vectorSize);

// Return pointer to element at specified index
int* vector_get(vector* v, unsigned int index);

// Insert new value at specified index
void vector_insert(vector* v, unsigned int index, int value);

// Insert new value at end of vector
void vector_push_back(vector* v, int value);

// Remove value at specified index
void vector_remove(vector* v, unsigned int index);

// Remove value at last index
void vector_pop(vector* v);

// Return number of elements within vector
int vector_size(vector* v);

#endif
