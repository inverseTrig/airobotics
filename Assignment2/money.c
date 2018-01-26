/*
 * HeeChan Kang
 * CSC 431 - AI Robotics
 * Assignment 2
 */

#include <stdio.h>
#include <stdlib.h>

double exchange(double dollars, double exrate) {
  return dollars * exrate;
}

void main(void)
{
  double dollars, exrate, yen;

  printf("Please input dollar spent: ");
  scanf("%lf", &dollars);
  printf("Please input exchange rate: ");
  scanf("%lf", &exrate);

  yen = exchange(dollars, exrate);

  printf("$ %8.2lf at an exchange rate of %6.2lf equals %12.2lf yen\n", dollars, exrate, yen);
}


