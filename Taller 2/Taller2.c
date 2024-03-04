#include <stdio.h>

int main()
{
    int numero, i, j;

    // Solicitar número al usuario
    do
    {
        printf("Ingrese un numero entero positivo entre 2 y 20: ");
        scanf("%d", &numero);
    } while (numero < 2 || numero > 20);

    // Imprimir triángulo
    printf("\nTriangulo:\n");
    for (i = 1; i <= numero; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // Imprimir cuadrado
    printf("\nCuadrado:\n");
    for (i = 1; i <= numero; i++)
    {
        for (j = 1; j <= numero; j++)
        {
            // Condicion para imprimir bordes y relleno
            if (i == 1 || i == numero || j == 1 || j == numero)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
