/***************************************************
 * HeeChan Kang
 * CSC 431 - AI Robotics
 * Assignment Zero - Arm Localization
 ***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checkAngle (double alpha, double beta);

void main() {
    double alpha, beta, x, y, x_temp;
    double base = 100.0, l1 = 80.0, l2 = 80.0, limit = 7*M_PI/8;
    int i, j;
    int row = 80, column = 80;

    for (i = 0; i < row; i++) {
        beta = limit - i*(2*limit)/row;
        for (j = 0; j < column; j++) {
            alpha = -limit + j*(2*limit)/column;
            printf("%d", checkAngle(alpha, beta));
        }
        printf("\n");
    }
}

/* Method that returns 0 if unreachable and 1 if reachable. */
int checkAngle (double alpha, double beta) {
    double base = 100.0, l1 = 80.0, l2 = 80.0;
    double x, y, x_temp;
    x = -l2*sin(alpha + beta) - l1*sin(alpha);
    y =  l2*cos(alpha + beta) + l1*cos(alpha) + base;

    if (y < 0) { return 0; }
    if (y < base) {
        x_temp = l1*cos(alpha + M_PI/2);
        if (x * x_temp < 0) { return 0; }
    }
    return 1;
}