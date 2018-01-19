#include <stdio.h>
#include <stdlib.h>

void sub1(int a);
void sub2(int a);

void main(void)
{
  int a = 5;
  sub1(a);
  printf("Now in main, value of a is %d \n", a);
}

void sub1(int a)
{
  a = a + 1;
  printf("Now in sub1, value of a is %d \n", a);
  sub2(a);
  printf("Returned to sub1 (after sub2), value of a is %d \n", a);
}

void sub2(int a)
{
  a = a * 2;
  printf("Now in sub2, value of a is %d \n", a);
}