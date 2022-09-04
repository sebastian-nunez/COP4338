// Determine the distance between point (x1, y1) and point (x2, y2), and assign the result to pointsDistance. The calculation is:

// Distance = sqrt((x2 - x1)^2 + (y2-y1)^2)

// Ex: For points (1.0, 2.0) and (1.0, 5.0), pointsDistance is 3.0.
#include <math.h>
#include <stdio.h>

int main(void) {
    double x1;
    double y1;
    double x2;
    double y2;
    double xDist;
    double yDist;
    double pointsDistance;

    xDist = 0.0;
    yDist = 0.0;
    pointsDistance = 0.0;

    scanf("%lf", &x1);
    scanf("%lf", &y1);
    scanf("%lf", &x2);
    scanf("%lf", &y2);

    /* Your solution goes here  */
    xDist = pow(x2 - x1, 2);
    yDist = pow(y2 - y1, 2);
    pointsDistance = sqrt(xDist + yDist);

    printf("%lf\n", pointsDistance);

    return 0;
}
