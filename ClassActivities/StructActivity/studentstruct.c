#include <stdio.h>
#include <string.h>

enum StudentStanding { FRESHMAN = 1, SOPHMORE, JUNIOR, SENIOR };

typedef struct {
  char firstName[30];
  char lastName[30];
  char id[10];
  int standing;
  double gpa;
} Student;

void printStudent(Student* student);

int main(void) {
  Student student1 = {};
  strcpy(student1.firstName, "Jim");
  strcpy(student1.lastName, "Johns");
  strcpy(student1.id, "1234567");
  student1.standing = SOPHMORE;
  student1.gpa = 3.74;

  printStudent(&student1);
  return 0;
}

void printStudent(Student* student) {
  if (student == NULL) {
    printf("Unable to print student! NULL pointer!\n");
    return;
  }

  printf("Name: %s %s\n", student->firstName, student->lastName);
  printf("Student ID: %s\n", student->id);

  switch (student->standing) {
    case FRESHMAN:
      printf("Student standing: Freshman\n");
      break;
    case SOPHMORE:
      printf("Student standing: Sophmore\n");
      break;
    case JUNIOR:
      printf("Student standing: Junior\n");
      break;
    case SENIOR:
      printf("Student standing: Senior\n");
      break;
    default:
      printf("Invalid student standing!");
  }

  printf("Current GPA: %.2lf\n", student->gpa);
}
