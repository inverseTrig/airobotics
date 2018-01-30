/*
 * HeeChan Kang
 * CSC 431 - AI Robotics
 * Assignment Zero - Arm Localization
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void main() {
    double alpha, beta, x, y;
    double l1 = 0.8, l2 = 0.8;

    /* Take user input for alpha and beta in radians. */
    printf("Enter angle alpha in radians: ");
    scanf("%lf", &alpha);
    printf("Enter angle beta in radians: ");
    scanf("%lf", &beta);

    /* Equation 3.25 and 3.26 page 48 of textbook.
     * The + 1 for y comes from the fixed arm of length 1. */
    x = l2*cos(alpha + beta) + l1*cos(alpha);
    y = l2*sin(alpha + beta) + l1*sin(alpha) + 1;
    printf("Current x, y position is: (%6.2lf, %6.2lf).\n", x, y);
}
