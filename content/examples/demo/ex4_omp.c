#include <stdio.h>
int main(void)
{
int x = 0;

#pragma omp target data map(tofrom:x)
{
   /* check point 1 */
   printf("x is: %i \n", x);
   x = 10;
   /* check point 2 */
   printf("x is: %i \n", x);
#pragma omp target update to(x)
   /* check point 3 */
   printf("x is: %i \n", x);
}

return 0;
}
