/***************************************************
 * HeeChan Kang
 * CSC 431 - AI Robotics
 * Assignment One - Inverse Kinematics
 ***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main() {
    double x, y, alpha, beta;
    double base = 1.0, l1 = 0.8, l2 = 0.8;

    /* Take user input for x and y coordinates. */
    printf("Enter x-coordinate: ");
    scanf("%lf", &x);
    printf("Enter y-coordinate: ");
    scanf("%lf", &y);

    /* Inverse Kinematics equation derived from class for beta and use beta to find alpha */
    beta  = acos( (pow(x,2) + pow(y,2) - (2 * base * y) + pow(base,2) - pow(l1,2) - pow(l2,2)) / (2 * l1 * l2) );
    alpha = atan( -x / sqrt(pow(l1,2) + pow(l2,2) + (2 * l1 * l2 * cos(beta) - pow(x,2))) ) - atan( (l2 * sin(beta)) / (l1 + (l2 * cos(beta))));
    
    printf("Alpha is: %6.4lf radians or %6.4lf degrees.\n", alpha, alpha * 180/M_PI);
    printf( "Beta is: %6.4lf radians or %6.4lf degrees.\n", beta,  beta  * 180/M_PI);
}