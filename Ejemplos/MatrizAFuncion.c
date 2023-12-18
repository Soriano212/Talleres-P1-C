#include <stdio.h>

void miFuncion(int matriz[][2][2], int dim1, int dim2, int dim3);

int main()
{
    int miMatriz[2][2][2];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                miMatriz[i][j][k] = i + j + k;
            }
        }
    }

    miFuncion(miMatriz, 2, 2, 2);
    return 0;
}

void miFuncion(int matriz[][2][2], int dim1, int dim2, int dim3)
{
    for (int i = 0; i < dim1; i++)
    {
        for (int j = 0; j < dim2; j++)
        {
            for (int k = 0; k < dim3; k++)
            {
                printf("%d ", matriz[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}