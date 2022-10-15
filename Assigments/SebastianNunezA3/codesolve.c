/* NAME: Sebastian Nunez
 * STUDENT ID: 6358289
 * CLASS: COP4338 (Assignment 3)
 * DATE: 10/10/22
 *
 * AFFIRMATION OF ORIGINALITY:
 * I affirm that I wrote this program myself
 * without any help from any other people or
 * sources from the internet.
 *
 * PROGRAM DESCRIPTION:
 * This assignment asks you to sort the letters in an input file
 * and print the sorted letters to an output file (or standard output).
 * - Note: input letters will be stored in a doubly linked list
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Node {
  char letter;
  struct Node* prev;
  struct Node* next;
} Node;

Node* createNode(void);

typedef struct LinkedList {
  Node* head;
  Node* tail;
  int size;
} LinkedList;

LinkedList* createLinkedList(void);
void destroyLinkedList(LinkedList* list);
void insertLinkedList(LinkedList* list, char letter);
void printLinkedList(LinkedList* list);

void solve(char inputFileName[], char outFileName[]);

int main(int argc, char* argv[]) {
  extern char* optarg;
  extern int optind;
  int c, err = 0;

  int oflag = 0;
  char* outFileName = "";
  char* inputFileName = "";
  static char usage[] = "usage: %s [-o output_file_name] input_file_name\n";

  //"o:?" are the allowed flags. : -> previous flag takes an argument
  while ((c = getopt(argc, argv, "o:?")) != -1) {
    switch (c) {
      case 'o':
        oflag = 1;
        outFileName = optarg;
        break;
      case '?':
        err = 1;
        break;
    }
  }
  if ((optind + 1) != argc) {
    // need at one argument for the input file
    printf("optind = %d, argc=%d\n", optind, argc);
    fprintf(stderr, "%s: missing inputFileName\n", argv[0]);
    fprintf(stderr, usage, argv[0]);
    exit(1);
  } else if (err) {
    fprintf(stderr, usage, argv[0]);
    exit(1);
  }

  inputFileName = argv[optind++];

  solve(inputFileName, outFileName);

  exit(0);
}

void solve(char inputFileName[], char outFileName[]) {
  bool shouldPrintToFile = (strlen(outFileName) > 0);

  FILE* inFile = fopen(inputFileName, "r");
  if (inFile == NULL) {
    printf("Unable to open file named: %s", inputFileName);
    exit(100);
  }

  FILE* outFile = shouldPrintToFile ? fopen(outFileName, "w") : stdout;
  if (outFile == NULL) {
    printf("Unable to open file named: %s", outFileName);
    exit(100);
  }

  LinkedList* list = createLinkedList();

  char inputChar;
  while (!feof(inFile)) {
    fscanf(inFile, " %c", &inputChar);
    inputChar = toupper(inputChar);
    insertLinkedList(list, inputChar);
  }

  Node* current = list->head->next;
  for (int i = 0; i < list->size; ++i) {
    fprintf(outFile, "%c", current->letter);
    current = current->next;
  }

  destroyLinkedList(list);
  fclose(inFile);
  fclose(outFile);
}

Node* createNode() {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->letter = -1;
  newNode->next = NULL;
  newNode->prev = NULL;

  return newNode;
}

LinkedList* createLinkedList() {
  LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));  // create list

  // create head and tail 'dummy' nodes
  Node* head = createNode();
  head->letter = '*';
  Node* tail = createNode();
  tail->letter = '*';

  // place our dummy nodes in the list
  list->head = head;
  list->tail = tail;
  list->size = 0;

  // make the head's next point to the tail (and prev to NULL)
  list->head->next = tail;
  list->head->prev = NULL;

  // make the tail's prev point to the head (and next to NULL)
  list->tail->next = NULL;
  list->tail->prev = head;

  printf("LinkedList created!\n");
  return list;
}

void destroyLinkedList(LinkedList* list) {
  if (list == NULL) {
    printf("List does not exist! Unable to destroy!\n");
    return;
  }

  Node* current = list->head;
  Node* next;
  while (current) {
    next = current->next;
    printf("Node %c destroyed!\n", current->letter);
    free(current);
    current = next;
  }

  printf("LinkedList destroyed!\n");
  free(list);
  list = NULL;
}

// void insertLinkedList(LinkedList* list, char letter) {
//   if (list == NULL) {
//     printf("List does not exist! Unable to insert!\n");
//     return;
//   }

//   // create newNode and give it the data
//   Node* newNode = createNode();
//   newNode->letter = letter;

//   Node* chain = list->head->next;  // save the chain of nodes

//   // fix newNode pointers
//   newNode->next = chain;
//   newNode->prev = list->head;

//   // fix head pointers
//   list->head->next = newNode;
//   chain->prev = newNode;

//   list->size++;
//   printf("Added %c to the list!\n", letter);
// }

void insertLinkedList(LinkedList* list, char letter) {
  if (list == NULL) {
    printf("List does not exist! Unable to insert!\n");
    return;
  }

  // create newNode and give it the data
  Node* newNode = createNode();
  newNode->letter = letter;

  if (list->size == 0) {  // empty list. insert at the head
    Node* chain = list->head->next;
    newNode->next = chain;
    newNode->prev = list->head;

    list->head->next = newNode;
    list->tail->prev = newNode;
    list->size++;
    return;
  }

  Node* current = list->head->next;  // save the chain of nodes
  Node* prev = current->prev;        // store the previous node

  for (int i = 0; i < list->size; ++i) {
    if (letter == current->letter) {  // duplicate value. ignore!
      return;
    }

    // position found, insert
    if (letter < current->letter) {
      Node* chain = current->next;  // save the chain
      newNode->next = chain;
      newNode->prev = prev;

      prev->next = newNode;
      chain->prev = newNode;

      list->size++;
      printf("Added %c to the list!\n", letter);
      return;
    }

    prev = current;
    current = current->next;
  }
}

void printLinkedList(LinkedList* list) {
  if (list == NULL) {
    printf("List does not exist! Unable to print!\n");
    return;
  }

  if (list->size == 0) {
    printf("Empty list!\n");
    return;
  }

  Node* current = list->head->next;
  for (int i = 0; i < list->size; ++i) {
    printf("%c ", current->letter);
    current = current->next;
  }

  printf("\n");
}
