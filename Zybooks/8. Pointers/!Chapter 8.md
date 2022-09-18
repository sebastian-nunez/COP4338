# Chapter 8: Pointers

- [Chapter 8: Pointers](#chapter-8-pointers)
  - [Why Pointers](#why-pointers)
  - [Pointer Basics](#pointer-basics)
  - [Dereferencing a Pointer](#dereferencing-a-pointer)
  - [Null Pointer](#null-pointer)
  - [Common Pointer Mistakes](#common-pointer-mistakes)
  - [Malloc Function](#malloc-function)
  - [Free Function](#free-function)
  - [Pointers with Structs](#pointers-with-structs)
  - [String Functions with Pointers](#string-functions-with-pointers)
  - [String Searching Methods (Table)](#string-searching-methods-table)
  - [Malloc for Arrays and Strings](#malloc-for-arrays-and-strings)
  - [Dynamic Copy of a String](#dynamic-copy-of-a-string)
  - [Realloc Function](#realloc-function)
    - [Dynamically Reallocating Size of an Array (Code)](#dynamically-reallocating-size-of-an-array-code)
  - [**Vector ADT**](#vector-adt)
    - [vector.h](#vectorh)
    - [Vector Implementation](#vector-implementation)
    - [**Vector Functions (Table)**](#vector-functions-table)
    - [Segmentation Fault](#segmentation-fault)
  - [LinkedList vs. Vector](#linkedlist-vs-vector)
    - [LinkedList (Code)](#linkedlist-code)
  - [**Memory Regions - Heap and Stack (Table)**](#memory-regions---heap-and-stack-table)
  - [Memory Leaks](#memory-leaks)

## Why Pointers

![Why pointers](8.1%20Pointers.png)

## Pointer Basics

![Pointer Basics](8.2%20Pointer%20Basics.png)

## Dereferencing a Pointer

![Dereferencing a Pointer](8.2%20Derefencing%20a%20Pointer.png)

## Null Pointer

![Null Pointer](8.2%20Null%20Pointer.png)

## Common Pointer Mistakes

![Common Pointer Mistakes](8.2%20Common%20Pointer%20Mistakes.png)

## Malloc Function

![Mallot and Free Functions](8.3%20Mallot%20and%20Free.png)

## Free Function

![Free Function](8.3%20Free%20Function.png)

## Pointers with Structs

![Pointers with Structs](8.4%20Pointers%20with%20Structs.png)

## String Functions with Pointers

![String Functions with Pointers](8.5%20String%20functions%20with%20Pointers.png)

## String Searching Methods (Table)

![String Searching Methods (Table)](<8.5%20String%20Searching%20(Table).png>)

## Malloc for Arrays and Strings

![Malloc for Arrays and Strings](8.6%20Malloc%20for%20Arrays%20and%20Strings.png)

## Dynamic Copy of a String

![Dynamic Copy of a String](8.6%20Dynamic%20Copy%20of%20a%20String.png)

- Make sure to account of the NULL character terminator in the String Length

## Realloc Function

![Realloc Function](8.7%20Realloc%20Function.png)

### Dynamically Reallocating Size of an Array (Code)

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int* userVals = NULL; // No array yet
   int numVals;
   int i;
   char userInput;
   int userValsSum;
   double userValsAvg;

   userInput = 'c';

   while (userInput == 'c') {

      printf("Enter number of integer values: ");
      scanf(" %d", &numVals);

      if (userVals == NULL) {
         userVals = (int*)malloc(numVals * sizeof(int));
      }
      else {
         userVals = (int*)realloc(userVals, numVals * sizeof(int));
      }

      printf("Enter %d integer values...\n", numVals);
      for (i = 0; i < numVals; ++i) {
         printf("Value: ");
         scanf("%d", &(userVals[i]));
      }

      // Calculate average
      userValsSum = 0;
      for (i = 0; i < numVals; ++i) {
         userValsSum = userValsSum + userVals[i];
      }
      userValsAvg = (double)userValsSum / (double)numVals;

      printf("Average = %lf\n", userValsAvg);

      printf("\nEnter 'c' to compute another average (any other key to quit): ");
      scanf(" %c", &userInput);
   }

   free(userVals);

   return 0;
}
```

## **Vector ADT**

![Vector ADT](8.8%20Vector%20ADT.png)

### vector.h

```c
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

// Erase (remove) value at specified index
void vector_remove(vector* v, unsigned int index);

// Return number of elements within vector
int vector_size(vector* v);

#endif

```

### Vector Implementation

```c
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
```

### **Vector Functions (Table)**

![Vector Functions (Table)](<8.8%20Vector%20Functions%20(Table).png>)

### Segmentation Fault

![Segmentation Fault](8.8%20Segmentation%20Fault.png)

## LinkedList vs. Vector

![LinkedList vs. Vector](8.9%20LinkedList%20vs.%20Vector.png)

### LinkedList (Code)

```c

#include <stdio.h>
#include <stdlib.h>

typedef struct IntNode_struct {
  int dataVal;
  struct IntNode_struct* nextNodePtr;
} IntNode;

// Constructor
void IntNode_Create(IntNode* thisNode, int dataInit, IntNode* nextLoc) {
  thisNode->dataVal = dataInit;
  thisNode->nextNodePtr = nextLoc;
}

/* Insert newNode after node.
 Before: thisNode -- next
 After:  thisNode -- newNode -- next
 */
void IntNode_InsertAfter(IntNode* thisNode, IntNode* newNode) {
  IntNode* tmpNext = NULL;

  tmpNext = thisNode->nextNodePtr;  // Remember next
  thisNode->nextNodePtr = newNode;  // this -- new -- ?
  newNode->nextNodePtr = tmpNext;   // this -- new -- next
}

// Print dataVal
void IntNode_PrintNodeData(IntNode* thisNode) {
  printf("%d\n", thisNode->dataVal);
}

// Grab location pointed by nextNodePtr
IntNode* IntNode_GetNext(IntNode* thisNode) {
  return thisNode->nextNodePtr;
}

int main(void) {
  IntNode* headObj = NULL;  // Create IntNode objects
  IntNode* nodeObj1 = NULL;
  IntNode* nodeObj2 = NULL;
  IntNode* nodeObj3 = NULL;
  IntNode* currObj = NULL;

  // Front of nodes list
  headObj = (IntNode*)malloc(sizeof(IntNode));
  IntNode_Create(headObj, -1, NULL);

  // Insert nodes
  nodeObj1 = (IntNode*)malloc(sizeof(IntNode));
  IntNode_Create(nodeObj1, 555, NULL);
  IntNode_InsertAfter(headObj, nodeObj1);

  nodeObj2 = (IntNode*)malloc(sizeof(IntNode));
  IntNode_Create(nodeObj2, 999, NULL);
  IntNode_InsertAfter(nodeObj1, nodeObj2);

  nodeObj3 = (IntNode*)malloc(sizeof(IntNode));
  IntNode_Create(nodeObj3, 777, NULL);
  IntNode_InsertAfter(nodeObj1, nodeObj3);

  // Print linked list
  currObj = headObj;
  while (currObj != NULL) {
    IntNode_PrintNodeData(currObj);
    currObj = IntNode_GetNext(currObj);
  }

  return 0;
}
```

## **Memory Regions - Heap and Stack (Table)**

![Memory Regions - Heap and Stack (Table)](<8.10%20Memory%20Regions%20-%20Heap%20and%20Stack%20(Table).png>)

## Memory Leaks

![Memory Leaks](8.12%20Memory%20Leaks.png)
