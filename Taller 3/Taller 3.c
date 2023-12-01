#include <stdio.h>

int main()
{
    char curso[30];
    int cant = 0;
    int valido = 0;
    float notas[100];
    float promedio = 0;

    while (valido == 0)
    {
        printf("Ingrese el nombre del curso: ");
        scanf("%s", curso);

        for (int i = 0; curso[i] != '\0'; i++)
        {
             if (!((curso[i] >= 65 && curso[i] <= 90) ||
                    (curso[i] >= 97 && curso[i] <= 122) ||
                    (curso[i] >= 48 && curso[i] <= 57) ||
                    (curso[i] == 32))) {
                valido = 0;
                break;
            }
            else
            {
                valido = 1;
            }
        }

        if (valido == 0)
        {
            printf("Error nombre invalido, no ingrese caracteres especiales.\n");
        }
    }

    valido = 0;

    while (valido == 0)
    {
        printf("Ingrese la cantidad de alumnos: ");
        scanf("%d", &cant);

        if (cant > 0)
        {
            valido = 1;
        }
        else
        {
            valido = 0;
            printf("Error cantidad invalida, ingrese un numero mayor a 0.\n");
        }
    }

    for(int i = 0; i < cant; i++)
    {
        printf("Ingrese la nota del alumno %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    for(int i = 0; i < cant; i++)
    {
        for(int j = 0; j < cant-1; j++){
            if(notas[j] > notas[j+1]){
                float aux = notas[j];
                notas[j] = notas[j+1];
                notas[j+1] = aux;
            }
        }
    }

    for(int i = 0; i < cant; i++)
    {
        promedio += notas[i];
    }
    
    promedio /= cant;

    printf("El curso %s tiene %d alumnos.\n", curso, cant);
    printf("Las notas de los alumnos son:\n");
    for(int i = 0; i < cant; i++)
    {
        printf("%.2f\n", notas[i]);
    }
    printf("La nota mas baja es: %.2f\n", notas[0]);
    printf("La nota mas alta es: %.2f\n", notas[cant-1]);
    printf("El promedio del curso %s es: %.2f\n", curso, promedio);
}