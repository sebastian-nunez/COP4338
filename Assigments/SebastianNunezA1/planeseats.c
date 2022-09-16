/* NAME: Sebastian Nunez
 * STUDENT ID: 6358289
 * CLASS: COP4338 (Assignment 1)
 * DATE: 08/27/22
 *
 * AFFIRMATION OF ORIGINALITY:
 * I affirm that I wrote this program myself
 * without any help from any other people or
 * sources from the internet.
 *
 * PROGRAM DESCRIPTION:
 * Throughout this program, users are able to select
 * their assigned seat on a 12-seat airplane.
 * Importantly, there are 4 first class seats [0-3] and 8 economy seats [4-11].
 * Of course, depending on availability, the users' selection
 * may be restricted. To clarify, firstClass is considered to be indexes 0 to 3
 * of the available seats; naturally, economy is the rest: indexes 4 to 11.
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// global constants
#define MAXSEATS 12          // there are 12 seats on the plane
#define FIRSTCLASS_MAX 3     // seats [0-3] -> First Class
#define ECONOMYCLASS_MAX 11  // seats [4-11] -> Economy Class

// depending on the class of the flyer, their seat will be assigned to the
// corresponding priority class
enum Priority { Priority_FirstClass = 1, Priority_Economy = 2 };

/*
 * Main function: everything within my programs happens in here.
 * In essence, all I have it's a loop which keeps asking the user for a seat
 * choice as long as there are seats available in the plane. Depending on the
 * class and availability, the user will be presented with different choices. 1)
 * to upgrade 2) downgrade 3) forced to wait until the following day.
 */
int main() {
  int selection;
  int seats[MAXSEATS] = {0};  // available seats have a value of 0 (taken seats
                              // will have their corresponding priority)
  int firstClassIndex =
      0;  // keeps track of the first available seat in first class
  int economyClassIndex =
      4;  // keeps track of the first available seat in economy

  // infinite loop, only ends when there is 1) an ERROR 2) Plane is full 3)
  // the user wishes to quit
  while (true) {
    // prompt
    puts("Please type 1 for \"first class\"");
    puts("Please type 2 for \"economy\"");
    puts("Please type 0 to quit");

    // initial seat selection
    printf("Selection :: ");
    scanf("%d", &selection);

    // parse the selection
    switch (selection) {
      case 0:
        puts("Closing the program...");
        exit(0);
      case 1:
        if (firstClassIndex <= FIRSTCLASS_MAX) {  // if there are first class
                                                  // seats, we can assign them
          seats[firstClassIndex++] = Priority_FirstClass;
          printf(
              "\nCongratulations! You have been assigned seat #%d "
              "(FIRST class)\n\n",
              firstClassIndex);
        } else if (economyClassIndex <=
                   ECONOMYCLASS_MAX) {  // no 1st class seats, but economy is
                                        // open
          puts(
              "\nUnfortunately, all FIRST class seats have been taken. "
              "Do you wish to fly in ECONOMY?\n");
          puts("Please type 1 for \"YES\"");
          puts("Please type 2 for \"NO\"");
          printf("Selection :: ");
          scanf("%d", &selection);

          if (selection == 1) {
            seats[economyClassIndex++] = Priority_Economy;
            printf(
                "\nCongratulations! You have been assigned seat #%d "
                "(ECONOMY class)\n\n",
                economyClassIndex);
          } else if (selection == 2) {
            puts("\nNo worries! The next flight will be tomorrow!\n");
            break;
          } else {
            puts("Invalid choice! Your selection has not been saved.");
            exit(1);
          }
        } else {  // the plane is full!
          puts(
              "\nUnfortunately, all FIRST class and ECONOMY class seats "
              "have been taken.");
          puts("The next flights will be tomorrow!");
          exit(0);
        }

        break;
      case 2:
        if (economyClassIndex <=
            ECONOMYCLASS_MAX) {  // if economy seats are open, we can assign
                                 // them
          seats[economyClassIndex++] = Priority_Economy;
          printf(
              "\nCongratulations! You have been assigned seat #%d "
              "(ECONOMY class)\n\n",
              economyClassIndex);
        } else if (firstClassIndex <=
                   FIRSTCLASS_MAX) {  // no economy class seats, but first
                                      // class is open
          puts(
              "\nUnfortunately, all ECONOMY seats have been taken. Do "
              "you wish to upgrade to FIRST class?\n");
          puts("Please type 1 for \"YES\"");
          puts("Please type 2 for \"NO\"");
          printf("Selection :: ");
          scanf("%d", &selection);

          if (selection == 1) {
            seats[firstClassIndex++] = Priority_FirstClass;
            printf(
                "\nCongratulations! You have been assigned seat #%d "
                "(FIRST class)\n\n",
                firstClassIndex);
          } else if (selection == 2) {
            puts("\nNo worries! The next flight will be tomorrow!\n");
            break;
          } else {
            puts("Invalid choice! Your selection has not been saved.");
            exit(1);
          }
        } else {  // the plane is full!
          puts(
              "\nUnfortunately, all FIRST class and ECONOMY class seats "
              "have been taken.");
          puts("The next flights will be tomorrow!");
          exit(0);
        }
        break;
      default:
        puts("Invalid Class selection!");
        exit(1);  // return value 1 -> signifies error
    }
  }

  return 0;  // sucessful execution
}
