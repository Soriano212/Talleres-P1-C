#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 100
#define MAX_MAT 10

// Función para contar palabras en una cadena
int contarPalabras(char *cadena)
{
    int palabras = 0;
    int enPalabra = 0;
    while (*cadena)
    {
        if (*cadena == ' ' || *cadena == '\n' || *cadena == '\t')
        {
            enPalabra = 0;
        }
        else if (enPalabra == 0)
        {
            enPalabra = 1;
            palabras++;
        }
        cadena++;
    }
    return palabras;
}

// Función para convertir una cadena a mayúsculas
void convertirAMayusculas(char *cadena)
{
    while (*cadena)
    {
        *cadena = toupper((unsigned char)*cadena);
        cadena++;
    }
}

// Función para leer una matriz de tamaño n x m
void leerMatriz(int matriz[MAX_MAT][MAX_MAT], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("Ingrese elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Función para imprimir la matriz transpuesta
void imprimirTranspuesta(int matriz[MAX_MAT][MAX_MAT], int n, int m)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", matriz[j][i]);
        }
        printf("\n");
    }
}

int main()
{
    int opcion;
    char cadena[MAX_STR];
    int matriz[MAX_MAT][MAX_MAT];
    int n, m;

    do
    {
        printf("\nMenu de Opciones\n");
        printf("1. Contador de Palabras en una Cadena\n");
        printf("2. Crear y Mostrar una Matriz Transpuesta\n");
        printf("3. Convertir Cadenas a Mayusculas\n");
        printf("4. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer de entrada

        switch (opcion)
        {
        case 1:
            printf("Ingrese una cadena de texto: ");
            fgets(cadena, MAX_STR, stdin);
            cadena[strcspn(cadena, "\n")] = 0; // Eliminar el salto de línea
            printf("La cadena contiene %d palabras.\n", contarPalabras(cadena));
            break;
        case 2:
            printf("Ingrese las dimensiones de la matriz (n m): ");
            scanf("%d %d", &n, &m);
            leerMatriz(matriz, n, m);
            printf("Matriz Transpuesta:\n");
            imprimirTranspuesta(matriz, n, m);
            break;
        case 3:
            printf("Ingrese una cadena de texto: ");
            fgets(cadena, MAX_STR, stdin);
            cadena[strcspn(cadena, "\n")] = 0; // Eliminar el salto de línea
            convertirAMayusculas(cadena);
            printf("Cadena en mayusculas: %s\n", cadena);
            break;
        case 4:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 4);

    return 0;
}
