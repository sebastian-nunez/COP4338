# **Chapter 7: Structs**

- [**Chapter 7: Structs**](#chapter-7-structs)
  - [Defining Structs and Typedef](#defining-structs-and-typedef)
  - [Returning Structs from Functions](#returning-structs-from-functions)
  - [Structs and Arrays](#structs-and-arrays)
  - [Structs, Arrays, and Functions (Example)](#structs-arrays-and-functions-example)
  - [Derefencing a Pointer to a Struct (->)](#derefencing-a-pointer-to-a-struct--)
  - [Seperate Files for Structs](#seperate-files-for-structs)

## Defining Structs and Typedef

![Defining Structs and Typedef](7.1%20Defining%20Structs%20and%20Typedef.png)

## Returning Structs from Functions

![Returning Structs from Functions](7.2%20Returning%20Structs%20from%20Functions.png)

## Structs and Arrays

![Structs and Arrays](./7.3%20Structs%20and%20Arrays.png)

## Structs, Arrays, and Functions (Example)

A programmer commonly uses structs, arrays, and functions together. Consider a program that allows a reservations agent to reserve seats for people, useful for a theater, an airplane, etc. The below program defines a Seat struct whose data members are a person's first name, last name, and the amount paid for the seat. The program declares an array of 5 seats to represent the theater, airplane, etc., initializes all seats to being empty (indicated by a first name of "empty"), and then allows a user to enter commands to print all seats, reserve a seat, or quit.

```c
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct Seat_struct {
    char firstName[50];
    char lastName[50];
    int amountPaid;
} Seat;

/*** Functions for Seat ***/

void SeatMakeEmpty(Seat* seat) {
    strcpy((*seat).firstName, "empty");
    strcpy((*seat).lastName, "empty");
    (*seat).amountPaid = 0;
}

bool SeatIsEmpty(Seat seat) {
    return (strcmp(seat.firstName, "empty") == 0);
}

void SeatPrint(Seat seat) {
    printf("%s ", seat.firstName);
    printf("%s, ", seat.lastName);
    printf("Paid: %d\n", seat.amountPaid);
}
/*** End functions for Seat ***/

/*** Functions for array of Seat ***/
void SeatsMakeEmpty(Seat seats[], int numSeats) {
    int i;

    for (i = 0; i < numSeats; ++i) {
        SeatMakeEmpty(&seats[i]);
    }
}

void SeatsPrint(Seat seats[], int numSeats) {
    int i;

    for (i = 0; i < numSeats; ++i) {
        printf("%d: ", i);
        SeatPrint(seats[i]);
    }
}
/*** End functions for array of Seat ***/

int main(void) {
    const int NUM_SEATS = 5;
    char userKey;
    int seatNum;
    Seat allSeats[NUM_SEATS];
    Seat currSeat;

    userKey = '-';

    SeatsMakeEmpty(allSeats, NUM_SEATS);

    while (userKey != 'q') {
        printf("Enter command (p/r/q): ");
        scanf(" %c", &userKey);

        if (userKey == 'p') {  // Print seats
            SeatsPrint(allSeats, NUM_SEATS);
            printf("\n");
        } else if (userKey == 'r') {  // Reserve seat
            printf("Enter seat num: ");
            scanf("%d", &seatNum);

            if (!SeatIsEmpty(allSeats[seatNum])) {
                printf("Seat not empty.\n\n");
            } else {
                printf("Enter first name: ");
                scanf("%s", currSeat.firstName);
                printf("Enter last name: ");
                scanf("%s", currSeat.lastName);
                printf("Enter amount paid: ");
                scanf("%d", &currSeat.amountPaid);

                allSeats[seatNum] = currSeat;

                printf("Completed.\n\n");
            }
        }
        // FIXME: Add option to delete reservations
        else if (userKey == 'q') {  // Quit
            printf("Quitting.\n");
        } else {
            printf("Invalid command.\n\n");
        }
    }

    return 0;
}
```

## Derefencing a Pointer to a Struct (->)

![Derefencing a Pointer to a Struct](7.4%20Deferencing%20a%20Pointer%20to%20a%20Struct.png)

## Seperate Files for Structs

![Seperate Files for Structs](7.5%20Separate%20Files%20for%20Structs.png)
