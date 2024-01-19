//PRACTICAL NO 4
//Write algorithm to obtain solution of given algebraic equation using RegulaFalsi method

#include <stdio.h>
#include <math.h>

#define e 0.001
#define f(x) x *x *x - 4 * x + 1

int main()
{
    float x0, x1, x2;
    float f0, f1, f2;
    float i = 0;

    printf("Enter the Values of X0 and X1 :");
    scanf("%f %f", &x0, &x1);

    do
    {
        f0 = f(x0);
        f1 = f(x1);
        x2 = ((x0*f1) - (x1*f0))/(f1 - f0);
        f2 = f(x2);

        if ((f0 * f2) < 0)
        {
            x1 = x2;
            f1 = f2;
        }
        else
        {
            x0 = x2;
            f0 = f2;
        }
        i++;
        printf("\nNo of Iterations are :%.1f\t\t", i);
        printf("Roots are :%f\t\t", x2);
        printf("Value of Function = %5f\t\t\n", f2);

    } while (fabs(f2) > e);

    return 0;
}
