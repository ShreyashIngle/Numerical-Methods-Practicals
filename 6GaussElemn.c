// PRACTICAL NO 6
//  Write algorithm to find solution of given Simultaneous Equations using Gauss Elimination method

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 10

int main()
{
    float a[SIZE][SIZE], x[SIZE], ratio;
    int i, j, k, n;

    system("cls");
    /* Inputs */
    /* 1. Reading number of unknowns */
    printf("Enter number of unknowns: ");
    scanf("%d", &n);
    /* 2. Reading Augmented Matrix */
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    /* Applying Gauss Elimination */
    for (i = 1; i <= n - 1; i++)
    {
        if (a[i][i] == 0.0)
        {
            printf("Mathematical Error!");
            exit(0);
        }
        for (j = i + 1; j <= n; j++)
        {
            ratio = a[j][i] / a[i][i];

            for (k = 1; k <= n + 1; k++)
            {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
        printf("\n");
        printf("For j=%d and i=%d", j, i);
        printf("\n\n");
        for (int u = 1; u <= n; u++)
        {
            for (int y = 1; y <= (n + 1); y++)
            {
                printf("%f\t", a[u][y]);
            }
            printf("\n");
        }
    }

    /* Obtaining Solution by Back Subsitution */
    x[n] = a[n][n + 1] / a[n][n];

    for (i = n - 1; i >= 1; i--)
    {
        x[i] = a[i][n + 1];
        for (j = i + 1; j <= n; j++)
        {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }
    /* Displaying Solution */
    printf("\nSolution:\n");
    for (i = 1; i <= n; i++)
    {
        printf("x[%d] = %0.3f\n", i, x[i]);
    }

    return (0);
}
