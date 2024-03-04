#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXDIM 100
#define MAXDATA 3
#define MAXSTRLEN 100

char people[MAXDIM][MAXDATA][MAXSTRLEN];
int personCount = 0;

void loadPeople();
void savePeople();
void listPeople();
void addPerson();
void listPeopleByCity();
void deletePersonByCedula(char cedula[]);

int main()
{
    int choice;

    do
    {
        system("clear");

        printf("\nMenu de Gestion de Personas\n");
        printf("=============================\n");
        printf("1. Agregar Persona\n");
        printf("2. Listar Personas\n");
        printf("3. Guardar Personas en Archivo\n");
        printf("4. Cargar Personas desde Archivo\n");
        printf("5. Listar Personas por Ciudad\n");
        printf("6. Eliminar Persona\n");
        printf("7. Salir\n");
        printf("=============================\n");
        printf("Seleccione una opcion: ");

        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            system("clear"); // system("cls"); en windows
            addPerson();
            system("read -n 1 -s -p \"Presione cualquier tecla para continuar...\""); // system("pause"); en windows
            break;
        case 2:
            system("clear");
            listPeople();
            system("read -n 1 -s -p \"Presione cualquier tecla para continuar...\"");
            break;
        case 3:
            system("clear");
            savePeople();
            system("read -n 1 -s -p \"Presione cualquier tecla para continuar...\"");
            break;
        case 4:
            system("clear");
            loadPeople();
            system("read -n 1 -s -p \"Presione cualquier tecla para continuar...\"");
            break;
        case 5:
            system("clear");
            listPeopleByCity();
            system("read -n 1 -s -p \"Presione cualquier tecla para continuar...\"");
            break;
        case 6:
            system("clear");
            char cedula[11];
            printf("Cédula: ");
            fgets(cedula, 11, stdin);
            cedula[strcspn(cedula, "\n")] = 0;
            deletePersonByCedula(cedula);
            system("read -n 1 -s -p \"Presione cualquier tecla para continuar...\"");
            break;
        case 7:
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("Opcion no valida. Por favor intente de nuevo.\n");
            system("read -n 1 -s -p \"Presione cualquier tecla para continuar...\"");
        }
    } while (choice != 7);

    return 0;
}

void addPerson()
{
    if (personCount >= MAXDIM)
    {
        printf("Almacenamiento de personas lleno.\n");
        return;
    }

    printf("Cédula: ");
    fgets(people[personCount][0], MAXSTRLEN, stdin);
    people[personCount][0][strcspn(people[personCount][0], "\n")] = 0;

    printf("Nombre y Apellido: ");
    fgets(people[personCount][1], MAXSTRLEN, stdin);
    people[personCount][1][strcspn(people[personCount][1], "\n")] = 0;

    printf("Ciudad: ");
    fgets(people[personCount][2], MAXSTRLEN, stdin);
    people[personCount][2][strcspn(people[personCount][2], "\n")] = 0;

    personCount++;
}

void swapRecords(int i, int j)
{
    char temp[MAXDATA][MAXSTRLEN];

    for (int k = 0; k < MAXDATA; k++)
    {
        strcpy(temp[k], people[i][k]);
        strcpy(people[i][k], people[j][k]);
        strcpy(people[j][k], temp[k]);
    }
}

void listPeople()
{
    if (personCount == 0)
    {
        printf("No hay personas para mostrar.\n");
        return;
    }

    // Ordenando por nombre usando Bubble Sort
    for (int i = 0; i < personCount - 1; i++)
    {
        for (int j = 0; j < personCount - i - 1; j++)
        {
            if (strcmp(people[j][1], people[j + 1][1]) > 0)
            {
                swapRecords(j, j + 1);
            }
        }
    }

    printf("Personas:\n\n");
    printf("---------------------------------------------------------\n");
    printf("|Num|    Cédula    | Nombre y Apellido |     Ciudad     |\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < personCount; i++)
    {
        printf("|%3.3d|%14.14s|%19.19s|%16.16s|\n", i + 1, people[i][0], people[i][1], people[i][2]);
    }
    printf("---------------------------------------------------------\n");
}

void listPeopleByCity()
{
    if (personCount == 0)
    {
        printf("No hay personas para mostrar.\n");
        return;
    }

    char cities[MAXDIM][MAXSTRLEN];
    int cityCount = 0;

    // Encontrar todas las ciudades únicas
    for (int i = 0; i < personCount; i++)
    {
        int cityFound = 0;
        for (int j = 0; j < cityCount; j++)
        {
            if (strcmp(people[i][2], cities[j]) == 0)
            {
                cityFound = 1;
                break;
            }
        }
        if (!cityFound)
        {
            strcpy(cities[cityCount], people[i][2]);
            cityCount++;
        }
    }

    // Listar personas por ciudad
    for (int i = 0; i < cityCount; i++)
    {
        printf("\nCiudad: %s\n", cities[i]);
        printf("---------------------------------------------------------\n");
        printf("|Num|    Cédula    | Nombre y Apellido |     Ciudad     |\n");
        printf("---------------------------------------------------------\n");
        for (int j = 0; j < personCount; j++)
        {
            if (strcmp(people[j][2], cities[i]) == 0)
            {
                printf("|%3.3d|%14.14s|%19.19s|%16.16s|\n", j + 1, people[j][0], people[j][1], people[j][2]);
            }
        }
        printf("---------------------------------------------------------n");
    }
}

void deletePersonByCedula(char cedula[]) {
    int found = 0;

    for (int i = 0; i < personCount; i++) {
        if (strcmp(people[i][0], cedula) == 0) {
            found = 1;

            // Desplazar los registros siguientes una posición hacia arriba
            for (int j = i; j < personCount - 1; j++) {
                for (int k = 0; k < MAXDATA; k++) {
                    strcpy(people[j][k], people[j + 1][k]);
                }
            }

            personCount--;
            printf("Persona con cédula %s eliminada.\n", cedula);
            break;
        }
    }

    if (!found) {
        printf("No se encontró persona con cédula %s.\n", cedula);
    }
}

void savePeople()
{
    FILE *file = fopen("data.dat", "w");
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo para escribir.\n");
        return;
    }

    for (int i = 0; i < personCount; i++)
    {
        fprintf(file, "%s;%s;%s\n", people[i][0], people[i][1], people[i][2]);
    }

    fclose(file);
}

void loadPeople()
{
    FILE *file = fopen("data.dat", "r");
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo para leer.\n");
        return;
    }

    personCount = 0;

    while (personCount < MAXDIM &&
           fscanf(file, "%[^;];%[^;];%[^\n]\n", people[personCount][0], people[personCount][1], people[personCount][2]) == 3)
    {
        personCount++;
    }

    fclose(file);
}
