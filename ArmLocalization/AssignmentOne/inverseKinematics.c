/***************************************************
 * HeeChan Kang
 * CSC 431 - AI Robotics
 * Assignment One - Inverse Kinematics
 ***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main() {
    double x, y, alpha, beta, radius;
    double base = 100.0, l1 = 80.0, l2 = 80.0;
    double limit = 7*M_PI/8;

    /* Take user input for x and y coordinates. */
    printf("Enter x-coordinate (cm): ");
    scanf("%lf", &x);
    printf("Enter y-coordinate (cm): ");
    scanf("%lf", &y);

    /* Check if the distance of input is out of reach or not */
    radius = sqrt(pow(x,2) + pow((y-base),2));
    
    if (y > 0 && radius <= (l1 + l2)) {
        /* Inverse Kinematics equation derived from class for beta and use beta to find alpha */
        beta  = acos( (pow(x,2) + pow(y,2) - (2 * base * y) + pow(base,2) - pow(l1,2) - pow(l2,2)) / (2 * l1 * l2) );
        if (x < 0) { beta = -beta; }
        alpha = atan( -x / sqrt(pow(l1,2) + pow(l2,2) + (2 * l1 * l2 * cos(beta) - pow(x,2))) ) - atan( (l2 * sin(beta)) / (l1 + (l2 * cos(beta))));
        if (y < base) {
            alpha = -alpha;
        }
        

        printf("Alpha is: %6.4lf radians or %6.4lf degrees.\n", alpha, alpha * 180/M_PI);
        printf( "Beta is: %6.4lf radians or %6.4lf degrees.\n", beta,  beta  * 180/M_PI);
        
        /* Make sure arm doesn’t crossover itself */
        // if (alpha > -limit && alpha < limit && beta > -limit && beta < limit) {
        //     printf("Alpha is: %6.4lf radians or %6.4lf degrees.\n", alpha, alpha * 180/M_PI);
        //     printf( "Beta is: %6.4lf radians or %6.4lf degrees.\n", beta,  beta  * 180/M_PI);
        // }
        // else {
        //     printf("The coordinates entered are unreachable due to the arm's physical limitations.\n");
        // }
    }
    else {
        printf("Invalid input! Either the coordinate is out of reach or the coordinate is below the ground.\n");
    }
}