#include <stdio.h>
#include <stdlib.h>

double exchange(double dollars, double exrate);

void main(void)
{
  double dollars, exrate, yen;

  dollars = 2345.67;
  exrate = 100.0;

  yen = exchange(dollars, exrate);

  printf("$ %8.2lf at an exchange rate of %6.2lf equals %12.2lf yen\n", dollars, exrate, yen);
}

