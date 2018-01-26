/*
 * HeeChan Kang
 * CSC 431 - AI Robotics
 * Assignment 2
 */

#include <stdio.h>
#include <stdlib.h>
#include "checkwriter.h"

/*
*  writeHundreds takes an integer between zero and a thousand and prints out,
*      with appropriate spaces, the English word for that number.         
*/
void writeHundreds(int number) {
    int hundreds, tens;

    if (number < 100 && number > 0) {
        writeTens(number);
        return;
    }
    else if (number > 100 && number < 1000) {
        hundreds = number/100;
        writeOnes(hundreds);
        printf(" hundred and ");
        tens = number % 100;
        writeTens(tens);
    }
    else {
        printf("Invalid input.\n");
        return;
    }
}

void writeCheck(int number) {
    printf("\n----------------------------------------------------------------------\n\n");
    printf("HeeChan Kang\t\t\t\t\t\tCheck #123456\n");
    printf("Minneapolis\t\t\t\t\t\n");
    printf("Minnesota\t\tAugsburg Bank Visa\t     January 30, 2018\n");
    printf("Pay to the order of: \t\t\t\t\t     $ %d.00\n", number);
    writeHundreds(number);
    printf(" and 00/100 dollars\n\n");
    printf("CSC Department\n");
    printf("Hagfors Center\t\t\t\tSignature:___________\n");

    printf("\n----------------------------------------------------------------------\n\n");
}

void main(void) {
    int input;

    printf("Enter integer between 0 and 1000: ");
    scanf("%d", &input);

    writeCheck(input);
}