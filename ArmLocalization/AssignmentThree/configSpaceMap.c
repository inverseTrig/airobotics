/*******************************************************
 * Name: HeeChan Kang
 * Class: CSC 431 - Introduction to AI Robotics
 * Assignment: Assignment Two: Robot Arm
 * Date: 29/March/18
 * Description: Configuration Space Mapping
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checkAngle (double alpha, double beta);

void main() {
    int isReachable;
    
    FILE *fp;
    fp = fopen("/home/heechan/Desktop/testOne.txt", "w");

    double alpha, beta, x, y, x_temp;
    double base = 100.0, l1 = 80.0, l2 = 80.0, limit = 7*M_PI/8;
    int i, j, row = 80, column = 80;

    fprintf(fp, "*******************************************************************************\n"
                "This code is HeeChan's code to print out the alpha-beta map for the arm program\n"
                "code for AI Robotics.\n"
                "*******************************************************************************\n\n");

    for (i = 0; i < row; i++) {
        beta = limit - i*(2*limit)/row;
        for (j = 0; j < column; j++) {
            alpha = -limit + j*(2*limit)/column;
            isReachable = checkAngle(alpha, beta);
            if (isReachable == 1) {
                fprintf(fp, "1");
            } else {
                fprintf(fp, "0");
            }
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

/* Method that returns 0 if unreachable and 1 if reachable. */
int checkAngle (double alpha, double beta) {
    double base = 100.0, l1 = 80.0, l2 = 80.0;
    double x, y, x_temp;
    x = -l2*sin(alpha + beta) - l1*sin(alpha);
    y =  l2*cos(alpha + beta) + l1*cos(alpha) + base;

    /* Check if arm goes underground. */
    if (y < 0) { return 0; }
    /* Check if arm crosses its base. */
    if (y < base) {
		/* Compute location of "elbow". */
        x_temp = l1*cos(alpha + M_PI/2);
        /* Value is negative if "elbow" and "wrist" is on the opposite side. */
        if (x * x_temp < 0) { return 0; }
    }
    /* Otherwise, we are good to go. */
    return 1;
}
