// PRACTICAL NO 8
//  Write C program to Find solution of given Simultaneous
// Equations Using Gauss-seidel iterative method.
#include <stdio.h>
#include <math.h>

int main()
{
    float x[10][10], a[10], ae, max, t, s, e;
    int i, j, n, r, mxit;
    for (i = 0; i < n; i++)
        a[i] = 0;
    printf("\nEnter the value of n : \n");
    scanf("%d", &n);
    printf("Enter the elements of augmented matrix rowwise\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            scanf("%f", &x[i][j]);
        }
    }
    printf(" Enter the allowed error and maximum number of iteration:\n ");
    scanf("%f%d", &ae, &mxit);
    printf("Iteration  x[1]\t    x[2]\t     x[3]\n");
    for (r = 1; r <= mxit; r++)
    {
        max = 0;
        for (i = 0; i < n; i++)
        {
            s = 0;
            for (j = 0; j < n; j++)
                if (j != i)
                    s += x[i][j] * a[j];
            t = (x[i][n] - s) / x[i][i];
            e = fabs(a[i] - t);
            a[i] = t;
        }
        printf("%4d  ", r);
        for (i = 0; i < n; i++)
            printf(" %8.4f\t ", a[i]);
        printf("\n");
        if (max < ae)
        {
            printf("\nConverses in %3d iteration\n", r);
            for (i = 0; i < n; i++)
                printf("a[%d]=%7.4f\n", i + 1, a[i]);
            return 0;
        }
    }
}