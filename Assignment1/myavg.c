#include <stdio.h>
#include <stdlib.h>

double myavg(double db1, double db2, double db3, double db4) {
	return (db1 + db2 + db3 + db4)/4;
}

void main(void)
{
  double avg, w, x, y, z;
  w = 10.0;
  x = 20.0;
  y = 30.0;
  z = 40.0;
  avg = myavg(w,x,y,z);
  printf("The average of %6.2lf, %6.2lf, %6.2lf, and %6.2lf is %6.2lf\n", w, x, y, z, avg);
}


