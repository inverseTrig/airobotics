/***************************************************
 * HeeChan Kang
 * CSC 431 - AI Robotics
 * Assignment Zero - Arm Localization
 ***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main() {
    double alpha, beta, x, y, x_temp, y_temp;
    double base = 100.0, l1 = 80.0, l2 = 80.0;
    double limit = 7*M_PI/8;
    int i, j;
    int row = 80, column = 80;

    FILE *fp;
    fp = fopen("/home/heechan/Desktop/test.txt", "w");

    for (i = 0; i < row; i++) {
        beta = limit - i*(2*limit)/row;
        for (j = 0; j < column; j++) {
            alpha = -limit + i*(2*limit)/column;

            x = -l2*sin(alpha + beta) - l1*sin(alpha);
            y =  l2*cos(alpha + beta) + l1*cos(alpha) + base;

            if (y < 0) { fprintf(fp, "0"); }
            else if (y < base) {
                x_temp = l1*sin(alpha);
                if (x * x_temp < 0) {
                    fprintf(fp, "0");
                } else {
                    fprintf(fp, "1");
                }
            } else {
                fprintf(fp, "1");
            }
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}