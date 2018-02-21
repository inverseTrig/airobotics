/***************************************************
 * HeeChan Kang
 * CSC 431 - AI Robotics
 * Assignment Zero - Arm Localization
 ***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main() {
    double x, y, alpha;
    double base = 1.0, l1 = 0.8;

    /* Take user input for x and y coordinates. */
    printf("Enter x-coordinate: ");
    scanf("%lf", &x);
    printf("Enter y-coordinate: ");
    scanf("%lf", &y);

    /* Inverse Kinematics equation derived in class */
    alpha = M_PI - acos((pow(x,2) + pow(y,2) - pow(l1,2) - pow(base,2))/(-2*l1*base));

    if (x > 0.0)
        alpha = -alpha;
    

    printf("Current angle alpha is: %6.4lf.\n", alpha);

}