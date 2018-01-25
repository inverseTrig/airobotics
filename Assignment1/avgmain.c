#include <stdio.h>
#include <stdlib.h>

double myavg(double db1, double db2, double db3, double db4)
{
  double avg;
  avg = (db1 + db2 + db3 + db4)/4;
  return avg;
}

void main(void)
{
  double avg, w, x, y, z;
  printf("Please input a double (w): ");
  scanf("%lf", &w);
  printf("Please input second double (x): ");
  scanf("%lf", &x);
  printf("Please input third double (y): ");
  scanf("%lf", &y);
  printf("Please input fourth double (z): ");
  scanf("%lf", &z);

  avg = myavg(w,x,y,z);

  printf("The average of %6.2lf, %6.2lf, %6.2lf, and %6.2lf is %6.2lf\n", w, x, y, z, avg);
}


