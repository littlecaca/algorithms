#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);


    int **A = (int**)malloc(sizeof(int *) * n);

    for (int i = 0; i < n; ++i)
    {
        A[i] = (int *)calloc(1, sizeof(int) * n);
    }

    A[n / 2][n / 2] = 123;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    
    for (int i = 0; i < n; ++i)
        free(A[i]);

    free(A);

    return 0;
}
