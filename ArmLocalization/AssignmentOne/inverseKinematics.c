/***************************************************
 * HeeChan Kang
 * CSC 431 - AI Robotics
 * Assignment One - Inverse Kinematics
 ***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checkAngle(double alpha, double beta, double x, double y, double l1, double l2, double base);

void main() {
    double x, y, temp_x, temp_y, alphaA, alphaB, betaA, betaB, radius;
    double base = 100.0, l1 = 80.0, l2 = 80.0;
    double limit = 7*M_PI/8;
    int a, b, c, d, e, f, g, h;

    /* Take user input for x and y coordinates. */
    printf("Enter x-coordinate (cm): ");
    scanf("%lf", &x);
    printf("Enter y-coordinate (cm): ");
    scanf("%lf", &y);

    /* Check if the distance of input is out of reach or not */
    y = y - base;
    radius = sqrt(pow(x,2) + pow(y,2));
    
    if (radius <= (l1 + l2)) {
        temp_x = x;
        temp_y = y;

        x = temp_y;
        y = -temp_x;
        
        /* Inverse Kinematics equation derived from class for beta and use beta to find alpha */
        betaA  = acos( (pow(x,2) + pow(y,2) - pow(l1,2) - pow(l2,2)) / (2 * l1 * l2) );
        betaB = - betaA;
        alphaA = atan(y / x) - atan( (l2 * sin(betaA)) / (l1 + (l2 * cos(betaA))));
        alphaB = atan(y / x) - atan( (l2 * sin(betaB)) / (l1 + (l2 * cos(betaB))));

        a = checkAngle( alphaA,  betaA, temp_x, temp_y, l1, l2, base);
        b = checkAngle(-alphaA,  betaA, temp_x, temp_y, l1, l2, base);
        c = checkAngle( alphaB,  betaA, temp_x, temp_y, l1, l2, base);
        d = checkAngle(-alphaB,  betaA, temp_x, temp_y, l1, l2, base);
        e = checkAngle( alphaA,  betaB, temp_x, temp_y, l1, l2, base);
        f = checkAngle(-alphaA,  betaB, temp_x, temp_y, l1, l2, base);
        g = checkAngle( alphaB,  betaB, temp_x, temp_y, l1, l2, base);
        h = checkAngle(-alphaB,  betaB, temp_x, temp_y, l1, l2, base);

        if (a == 1 || b == 1 || c == 1 || d == 1 || e == 1 || d == 1 || e == 1 || f == 1 || g == 1 || h == 1) { fprintf(fp, "1"); }
        else { fprintf(fp, "0"); }

        // if (a == 1) { printf("(%4.2lf, %4.2lf)\n",  alphaA,  betaA); }
        // if (b == 1) { printf("(%4.2lf, %4.2lf)\n", -alphaA,  betaA); }
        // if (c == 1) { printf("(%4.2lf, %4.2lf)\n",  alphaB,  betaA); }
        // if (d == 1) { printf("(%4.2lf, %4.2lf)\n", -alphaB,  betaA); }
        // if (e == 1) { printf("(%4.2lf, %4.2lf)\n",  alphaA,  betaB); }
        // if (f == 1) { printf("(%4.2lf, %4.2lf)\n", -alphaA,  betaB); }
        // if (g == 1) { printf("(%4.2lf, %4.2lf)\n",  alphaB,  betaB); }
        // if (h == 1) { printf("(%4.2lf, %4.2lf)\n", -alphaB,  betaB); }
        
    }
    else {
        printf("Invalid input! Either the coordinate is out of reach or the coordinate is below the ground.\n");
    }

}

int checkAngle(double alpha, double beta, double x, double y, double l1, double l2, double base) {
    double temp_x, temp_y;
    y = y + base;
    
    temp_x = -l2*sin(alpha + beta) - l1*sin(alpha);
    temp_y =  l2*cos(alpha + beta) + l1*cos(alpha) + base;

    if (temp_x > (x - 1.0) && temp_x < (x + 1.0) && temp_y > (y - 1.0) && temp_y < (y + 1.0)) { return 1; }
    else { return 0; }
}