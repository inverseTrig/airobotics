/***************************************************
 * HeeChan Kang
 * CSC 431 - AI Robotics
 * Assignment Zero - Arm Localization
 ***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main() {
    double alpha, beta, x, y;
    double base = 1.0, l1 = 0.8, l2 = 0.8;

    /* Take user input for alpha and beta in radians. */
    printf("Enter angle alpha in radians: ");
    scanf("%lf", &alpha);
    printf("Enter angle beta  in radians: ");
    scanf("%lf", &beta);

    /* Forward Kinematics equation derived in class */
    x = -l2*sin(alpha + beta) - l1*sin(alpha);
    y =  l2*cos(alpha + beta) + l1*cos(alpha) + base;

    printf("Current x, y position is: (%6.4lf, %6.4lf).\n", x, y);

}