//PPRACTICAL NO 5
/*Write a C program to sp;ve the given equation using Newton Raphson method*/

#include <stdio.h>
#include <math.h>

#define e 0.001
#define f(x) x *x *x - 3 * x + 1
#define df(x) 3 * x *x - 3

int main()
{

    float x0, x1;
    float f0, f1, df0;

    float i = 0;

    printf("Enter the Values of X0 :");
    scanf("%f", &x0);

    do
    {
        f0 = f(x0);
        df0 = df(x0);
        x1 = x0 - (f0 / df0);
        f1 = f(x1);
        x0 = x1;

        i++;
        printf("\nNo of Iterations are :%.1f\t\t", i);
        printf("Roots are :%f\t\t", x1);
        printf("Value of Function = %5f\t\t\n", f1);

    } while (fabs(f1) > e);

    return 0;
}
