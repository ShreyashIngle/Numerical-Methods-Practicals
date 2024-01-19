// PRACTICAL NO 10
//  Write C program to implement lagrange's interpolation method for finding x.
#include <stdio.h>
void main()
{
    float x[100], y[100], input, numerator_product, denominator_product, L, output = 0;
    int n, i, j, d = 1;
    printf("\nEnter the number of the terms in the table: ");
    scanf("%d", &n);
    printf("\nEnter the respective values for x: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("\nEnter the respective values for y: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &y[i]);
    }
    printf("\nThe table you entered is as follows:\n");
    printf("X\t");
    for (i = 0; i < n; i++)
    {
        printf("%.0f\t", x[i]);
    }
    printf("\n\n");
    printf("Y\t");
    for (i = 0; i < n; i++)
    {
        printf("%.0f\t", y[i]);
    }
    while (d == 1)
    {
        printf("\n\nEnter the value of X : ");
        scanf("%f", &input);
        for (i = 0; i < n; i++)
        {
            numerator_product = 1;
            denominator_product = 1;
            for (j = 0; j < n; j++)
            {
                if (j != i)
                {
                    numerator_product = numerator_product * (input - x[j]);
                    denominator_product = denominator_product * (x[i] - x[j]);
                }
            }
            L = numerator_product / denominator_product;
            output = output + L * y[i];
        }
        printf("\nThe respective value of the variable x is: %f", output);
        printf("\n\nDo you want to continue?\nPress 1 to continue and any other key to exit \n");
        scanf("%d", &d);
    }
}
