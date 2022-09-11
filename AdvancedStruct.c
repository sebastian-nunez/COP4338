#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x;
    int y;
    void (*add)(struct Point *, int x, int y);
    void (*sub)(struct Point *, int x, int y);
    void (*print)(const struct Point *);
} Point;

void add(struct Point *point, int x, int y) {
    point->x += x;
    point->y += y;
}

void sub(struct Point *point, int x, int y) {
    point->x -= x;
    point->y -= y;
}

void print(const Point *point) { printf("(%d, %d)\n", point->x, point->y); }

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
