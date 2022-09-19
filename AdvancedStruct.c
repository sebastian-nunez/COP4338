#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
  int x;
  int y;
  void (*add)(struct Point* this, int x, int y);
  void (*sub)(struct Point* this, int x, int y);
  void (*print)(const struct Point* this);
} Point;

void add(Point* this, int x, int y) {
  this->x += x;
  this->y += y;
}

void sub(Point* this, int x, int y) {
  this->x -= x;
  this->y -= y;
}

void print(const Point* this) {
  printf("(%d, %d)\n", this->x, this->y);
}

int main(void) {
  Point p1 = {0, 0, add, sub, print};
  p1.print(&p1);
  p1.add(&p1, 1, 2);
  p1.print(&p1);

  p1.sub(&p1, 12, 6);
  p1.print(&p1);
  p1.print(&p1);

  return 0;
}
