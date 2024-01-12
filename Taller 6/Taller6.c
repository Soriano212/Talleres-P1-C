#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXDIM 100
#define MAXDATA 4
#define MAXSTRLEN 100

char songs[MAXDIM][MAXDATA][MAXSTRLEN];
int songCount = 0;

void loadSongs();
void saveSongs();
void listSongs();
void addSong();

int main()
{
    int choice;

    do
    {
        system("clear");

        printf("\nMenu de Gestion de Canciones\n");
        printf("=============================\n");
        printf("1. Agregar Cancion\n");
        printf("2. Listar Canciones\n");
        printf("3. Guardar Canciones en Archivo\n");
        printf("4. Cargar Canciones desde Archivo\n");
        printf("5. Salir\n");
        printf("=============================\n");
        printf("Seleccione una opcion: ");

        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            system("clear"); // system("cls"); en windows
            addSong();
            system("read -n 1 -s -p \"Presione cualquier tecla para continuar...\""); // system("pause"); en windows
            break;
        case 2:
            system("clear");
            listSongs();
            system("read -n 1 -s -p \"Presione cualquier tecla para continuar...\"");
            break;
        case 3:
            system("clear");
            saveSongs();
            system("read -n 1 -s -p \"Presione cualquier tecla para continuar...\"");
            break;
        case 4:
            system("clear");
            loadSongs();
            system("read -n 1 -s -p \"Presione cualquier tecla para continuar...\"");
            break;
        case 5:
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("Opcion no valida. Por favor intente de nuevo.\n");
            system("pause");
        }
    } while (choice != 5);

    return 0;
}

void addSong()
{
    if (songCount >= MAXDIM)
    {
        printf("Almacenamiento de canciones lleno.\n");
        return;
    }

    printf("Título: ");
    fgets(songs[songCount][0], MAXSTRLEN, stdin);
    songs[songCount][0][strcspn(songs[songCount][0], "\n")] = 0;

    printf("Autor: ");
    fgets(songs[songCount][1], MAXSTRLEN, stdin);
    songs[songCount][1][strcspn(songs[songCount][1], "\n")] = 0;

    printf("Álbum: ");
    fgets(songs[songCount][2], MAXSTRLEN, stdin);
    songs[songCount][2][strcspn(songs[songCount][2], "\n")] = 0;

    printf("Duración: ");
    fgets(songs[songCount][3], MAXSTRLEN, stdin);
    songs[songCount][3][strcspn(songs[songCount][3], "\n")] = 0;
    songCount++;
}

void listSongs()
{
    if (songCount == 0)
    {
        printf("No hay canciones para mostrar.\n");
        return;
    }

    printf("Canciones:\n\n");

    printf("-----------------------------------------------------------------------------\n");
    printf("|Num|        Título        |        Autor        |        Álbum        |    |\n");
    printf("-----------------------------------------------------------------------------\n");
    for (int i = 0; i < songCount; i++)
    {
        printf("|%3.3d|%22.22s|%21.21s|%21.21s|%4.4s|\n", i + 1, songs[i][0], songs[i][1], songs[i][2], songs[i][3]);
    }
    printf("-----------------------------------------------------------------------------\n");
}

void saveSongs()
{
    FILE *file = fopen("data.dat", "w");
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo para escribir.\n");
        return;
    }

    for (int i = 0; i < songCount; i++)
    {
        fprintf(file, "%s;%s;%s;%s\n", songs[i][0], songs[i][1], songs[i][2], songs[i][3]);
    }

    fclose(file);
}

void loadSongs()
{
    FILE *file = fopen("data.dat", "r");
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo para leer.\n");
        return;
    }

    songCount = 0;

    while (songCount < MAXDIM &&
           fscanf(file, "%[^;];%[^;];%[^;];%[^\n]\n", songs[songCount][0], songs[songCount][1], songs[songCount][2], songs[songCount][3]) == 4)
    {
        songCount++;
    }

    fclose(file);
}
