/*******************************************************
 * Name: HeeChan Kang
 * Class: CSC 431 - Introduction to AI Robotics
 * Assignment: Assignment Three Part 1: Robot Arm
 * Date: 5/April/18
 * Description: Moving the Robot Arm
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**************************************************
 *  A point structure for two dimensional space.  *
 **************************************************/
typedef
struct point { int x; int y; } Point;

typedef
struct angles { double one; double two; } Angles;

/********************************************
 *           Function Headers               *
 ********************************************/
/* Calculates a destination point of a gripper */
void calculateLocation(int baseLink, int link1, int link2, double angleAlpha, double angleBeta, Point* destination);

/* Calculates the actuator angles needed for a gripper position */
double calculateAngleTwo(int baseLink, int link1, int link2, Point* gripper);
double calculateAngleOne(int baseLink, int link1, int link2, double angle2, Point* gripper);

/* Calculates if the angles are reachable */
int checkAngle (double alpha, double beta);

/********************************************
 *                 MAIN                     *
 ********************************************/
int main( int argc, char* argv[]) {
    double angle1 = 0.0, angle2 = 0.0, limit = 7*M_PI/8, alpha, beta;
    int link1 = 80, link2 = 80, baseLink = 100, row = 80, column = 80, i, j, isReachable;
    Point gripper;
    
    FILE *fp;
    fp = fopen("/home/heechan/Desktop/HeeChan_XYMap.txt", "w");
    fprintf(fp, "*********************************************************************************\n"
                "This code is HeeChan's code to print out the x-y map for the arm program code for\n"
                "AI Robotics.\n"
                "*********************************************************************************\n\n");
    /* i is used to calculate y-value. */
    for (i = 0; i <= 65; i++) {
        gripper.y = (baseLink + link1 + link2) - i*(baseLink + link1 + link2)/65;
        /* j is used to calculate x-value. */
        for (j = 0; j <= 80; j++) {
            gripper.x = -(link1 + link2) + j*(2*(link1 + link2) / 80);
            angle2 = calculateAngleTwo(baseLink, link1, link2, &gripper);
            /* If there is error calculating value. */
            if (angle2 == 724.0) { fprintf(fp, "0"); }
            else {
                angle1 = calculateAngleOne(baseLink, link1, link2, angle2, &gripper);
                /* If it's possible for the arm to reach those angles. */
                if (angle2 >= -limit && angle2 <= limit && angle1 >= -limit && angle1 <= limit) { fprintf(fp, "1"); }
                else { fprintf(fp, "0"); } 
                }
            }
        fprintf(fp, "\n");
        }
    fclose(fp);

    fp = fopen("/home/heechan/Desktop/HeeChan_ABMap.txt", "w");
    fprintf(fp, "*******************************************************************************\n"
                "This code is HeeChan's code to print out the alpha-beta map for the arm program\n"
                "code for AI Robotics.\n"
                "*******************************************************************************\n\n");
    /* Calculate beta with i. */
    for (i = 0; i < row; i++) {
        beta = limit - i*(2*limit)/row;
        /* Calculate alpha with j. */
        for (j = 0; j < column; j++) {
            alpha = -limit + j*(2*limit)/column;
            /* Calculate if angle is reachable. */
            isReachable = checkAngle(alpha, beta);
            /* If reachable, write 1. */
            if (isReachable == 1) { fprintf(fp, "1"); }
            else { fprintf(fp, "0"); }
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

/*********************************************
 *             FUNCTIONS                     *
 ********************************************/

/* Forward Kinematics Equations */
void calculateLocation(int baseLink, int link1, int link2, double angle1, double angle2, Point* destination)
{
    double x, y;
    
    x = -link2*sin(angle1 + angle2) - link1*sin(angle1);
    y = link2*cos(angle1 + angle2) + link1*cos(angle1) + baseLink;
    
    (*destination).x = round(x);
    (*destination).y = round(y);
}

/* Calculate Angle Two (Beta) */
double calculateAngleTwo(int baseLink, int link1, int link2, Point* gripper)
{
    double angleNum = 0.0, angleDen = 0.0, angle = 0.0, ratio = 0.0;
    int gx = (*gripper).x, gy = (*gripper).y;
    
    angleNum = gx*gx + gy*gy - 2*baseLink*gy + baseLink*baseLink - link1*link1 - link2*link2;
    angleDen = 2*link1*link2;
    ratio = angleNum/angleDen;
    
    if (ratio>1.00) {
        if (ratio > 1.00 && ratio < 1.01) { ratio = 1.00; }
        else { return -724.0; }
    }
    angle = acos(ratio);
    return(angle);
}

/* Calculate Angle One (Alpha) */
double calculateAngleOne(int baseLink, int link1, int link2, double angle2, Point* gripper)
{
    double angleNum1 = 0.0, angleDen1 = 0.0, angleNum2 = 0.0, angleDen2 = 0.0, angle = 0.0;
    int gx = (*gripper).x, gy = (*gripper).y;
    
    angleNum1 = -gx;
    angleDen1 = link1*link1 + link2*link2 + 2*link1*link2*cos(angle2) - gx*gx;
    angleDen1 = sqrt(angleDen1);
    
    angleNum2 = link2*sin(angle2);
    angleDen2 = link1 + link2*cos(angle2);
    
    angle = atan(angleNum1/angleDen1) - atan(angleNum2/angleDen2);
    
    return(angle);
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