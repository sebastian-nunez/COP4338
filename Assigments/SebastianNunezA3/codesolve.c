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

/**
 * Object representation of a Node:
 * - letter: held within
 * - next: pointer to the next node
 * - prev: pointer to the prev node
 */
typedef struct Node {
  char letter;
  struct Node* next;
  struct Node* prev;
} Node;

// node methods
Node* createNode(char letter);

/**
 * LinkedList has the following properties:
 * - Head: Dummy node. Used to insert at the front
 * - Tail: Dummy node. Used to insert at the back
 * - Size: Keeps track of the number of elements
 */
typedef struct LinkedList {
  Node* head;
  Node* tail;
  int size;
} LinkedList;

// linked list methods
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

/**
 * This is where most the logic takes place. Given input (and possibly output) filenames.
 * This functions reads through each character of the input file and adds it to a Doubly Linked List.
 * In the end, we print the list.
 *
 * Note:
 * - Elements are inserted and kept in alphatical order (items near the front are lower in the alphabet)
 * - All letters are stored in uppercase to avoid ASCII conflicts
 * - No duplicate elements are allowed in the list
 */
void solve(char inputFileName[], char outFileName[]) {
  // "IF" we are given a outfile, write to it. Otherwise, print to stdout
  bool shouldPrintToFile = (strlen(outFileName) > 0);

  // open input file
  FILE* inFile = fopen(inputFileName, "r");
  if (inFile == NULL) {
    printf("Unable to open file named: %s", inputFileName);
    exit(100);
  }

  // open output file (or assign it to stdout if no output file given)
  FILE* outFile = shouldPrintToFile ? fopen(outFileName, "w") : stdout;
  if (outFile == NULL) {
    printf("Unable to open file named: %s", outFileName);
    exit(100);
  }

  LinkedList* list = createLinkedList();  // doubly linked list

  char inputChar;
  while (!feof(inFile)) {  // read through the entire file and add the letters to the list
    fscanf(inFile, " %c", &inputChar);

    if (!isalpha(inputChar)) {  // only alphabetic characters are allowed!
      continue;
    }

    insertLinkedList(list, toupper(inputChar));  // adds the character to the linkedlist (alphabetically)
    // printLinkedList(list);
  }

  // print the list
  Node* current = list->head->next;
  for (int i = 0; i < list->size; i++) {
    fprintf(outFile, "%c", current->letter);  // write to the outfile
    fflush(outFile);
    current = current->next;
  }
  fprintf(outFile, "\n");
  fflush(outFile);

  // clean up
  destroyLinkedList(list);
  fclose(inFile);
  fclose(outFile);

  exit(0);
}

/**
 * Allows for easy creation of a Node object given a letter.
 *
 * Returns: a pointer to a dynamically allocated node with the given letter
 */
Node* createNode(char letter) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Unable to create Node!\n");
    exit(1);
  }

  newNode->letter = letter;
  newNode->next = NULL;
  newNode->prev = NULL;

  return newNode;
}

/**
 * Creates the basic structure of a linked list and returns a pointer to it:
 *
 * - Head and Tail dummy nodes are created.
 * - Size initially is 0
 * - The dummy nodes should point towards each other
 */
LinkedList* createLinkedList() {
  LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));  // create list
  if (list == NULL) {
    printf("Unable to create the LinkedList!\n");
    exit(1);
  }

  // create head and tail 'dummy' nodes (dummy nodes are distingued using ^ for head and $ for tail)
  list->head = createNode('^');
  list->tail = createNode('$');
  list->size = 0;

  // make the head's 'next' point to the tail (and 'prev' to NULL)
  list->head->next = list->tail;
  list->head->prev = NULL;

  // make the tail's 'prev' point to the head (and 'next' to NULL)
  list->tail->next = NULL;
  list->tail->prev = list->head;

  // printf("LinkedList created!\n");
  return list;
}

/**
 * Since we dynamically allocated storage on the heap (using malloc), we have to free up that memory.
 * Method:
 * - we go through each node in the list (starting at the head) and free up the used memory
 * - essentially, we keep a copy of the previous node and delete once we have moved onto its 'next' node
 * at the end, we can free up the space allocated for the linked list itself. then, we simply set its pointer to null
 */
void destroyLinkedList(LinkedList* list) {
  if (list == NULL) {
    printf("List does not exist! Unable to destroy!\n");
    return;
  }

  Node* current = list->head;
  Node* next;
  while (current) {
    next = current->next;
    // printf("Node %c destroyed!\n", current->letter);
    free(current);
    current = next;
  }

  // printf("LinkedList destroyed!\n");
  free(list);
  list = NULL;
}
/**
 * To insert into the list while maintaining alphetical order we have 3 cases:
 * 1. List is empty -> add the element to the head
 * 2. The item to be inserted can be placed on the FIRST location where the element is LESS than the 'next'
 * 3. The inserted item is not less than any of the elements in the list -> add it to the tail
 */
void insertLinkedList(LinkedList* list, char letter) {
  if (list == NULL) {
    printf("List does not exist! Unable to insert!\n");
    return;
  }

  // create newNode and give it the data
  Node* newNode = createNode(letter);

  if (list->size == 0) {             // empty list. insert at the head
    Node* chain = list->head->next;  // keep a link to the rest of the list
    newNode->next = chain;
    newNode->prev = list->head;

    list->head->next = newNode;
    list->tail->prev = newNode;
    list->size++;

    // printf("Head: %c\n", letter);
    return;
  }

  Node* current = list->head->next;  // start with the first valid item (not the head)
  Node* prev = list->head;           // store the previous node (head initially)

  for (int i = 0; i < list->size; i++) {
    if (letter == current->letter) {  // duplicate value. ignore!
      return;
    }

    // position found, where the letter is less than the item at that spot.
    if (letter < current->letter) {
      Node* chain = current;  // save the chain
      newNode->next = chain;
      newNode->prev = prev;

      prev->next = newNode;
      chain->prev = newNode;
      list->size++;

      // printf("%c < %c\n", letter, current->letter);
      return;
    }

    // advance the pointers until a suitable position is HOPEFULLY found
    prev = current;
    current = current->next;
  }

  // if the inserted letter doesn't go before any of the letters in the list, then it must go in the end
  Node* chain = list->tail->prev;  // save the chain
  newNode->next = list->tail;
  newNode->prev = chain;

  chain->next = newNode;
  list->tail->prev = newNode;

  list->size++;
  // printf("Tail: %c\n", letter);
}

/**
 * Prints a representation of a LinkedList to the console.
 */
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
    printf("%c -> ", current->letter);
    current = current->next;
  }

  printf("\n");
}
