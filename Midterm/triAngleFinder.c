/***************************************************
 * HeeChan Kang
 * CSC 431 - AI Robotics
 * Midterm Exam - Triangle Angle Finder
 ***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double angleFinder(double l1, double l2, double l3);

void main() {
    double a, b, c;                    /* Side lengths */
    double radians[3], degrees[3];     /* Array to store angles */

    /* Take user input for side lengths. */
    printf("Enter sidelength of A: ");
    scanf("%lf", &a);
    printf("Enter sidelength of B: ");
    scanf("%lf", &b);
    printf("Enter sidelength of C: ");
    scanf("%lf", &c);

    /* Calculate angle in radians */
    radians[0] = angleFinder(a, b, c);
    radians[1] = angleFinder(b, c, a);
    radians[2] = angleFinder(c, a, b);

    /* Calculate angle in degrees */
    degrees[0] = radians[0]*180/M_PI;
    degrees[1] = radians[1]*180/M_PI;
    degrees[2] = radians[2]*180/M_PI;

    printf("The angles in radians are: %6.4lf, %6.4lf, and %6.4lf.\n", radians[0], radians[1], radians[2]);
    printf("The angles in degrees are: %6.4lf, %6.4lf, and %6.4lf.\n", degrees[0], degrees[1], degrees[2]);
}

double angleFinder(double l1, double l2, double l3) {
    return acos((pow(l1, 2) + pow(l2, 2) - pow(l3, 2)) / (2 * l1 * l2));
}