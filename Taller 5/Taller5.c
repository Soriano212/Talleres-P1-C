#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 100

int agregarCliente(char [][MAXCHAR][MAXCHAR], int nClientes);
void mostrarClientes(char [][MAXCHAR][MAXCHAR], int nClientes);

int main(void) {
    system("cls");
    char data[3][MAXCHAR][MAXCHAR];
    int nClientes = 0;
    int opcion = 0;

    do{
        printf("Bienvenido al sistema de registro de clientes\n");
        printf("1. Agregar cliente\n");
        printf("2. Buscar cliente\n");
        printf("3. Mostrar clientes\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        system("cls");

        switch(opcion){
            case 1:
                nClientes = agregarCliente(data, nClientes);
                break;
            case 2:
                break;
            case 3:
                mostrarClientes(data, nClientes);
                break;
        }

        system("cls");
    }
    while(opcion != 0);
    
    return 0;
}



int agregarCliente(char data[][MAXCHAR][MAXCHAR], int nClientes){
    int cantidad;
    printf("Ingrese la cantidad de clientes a agregar: ");
    scanf("%d", &cantidad);

    system("cls");

    for(int i = 0; i < cantidad; i++){
        printf("Cliente %d\n\n", i+1);

        printf("Ingrese el nombre del cliente: ");
        scanf("%s", data[0][nClientes]);
        printf("Ingrese el apellido del cliente: ");
        scanf("%s", data[1][nClientes]);
        printf("Ingrese la edad del cliente: ");
        scanf("%s", data[2][nClientes]);
        nClientes++;

        printf("\nCliente agregado con exito\n");
        system("pause");
        system("cls");
    }

    return nClientes;
}

void mostrarClientes(char data[][MAXCHAR][MAXCHAR], int nClientes){
    printf("--------------------------------------\n");
    printf("|Num|    Nombre    |  Apellido  |Edad|\n");
    printf("--------------------------------------\n");

    for(int i = 0; i < nClientes; i++){
        printf("|%3d|%14s|%12s|%4s|\n", i, data[0][i], data[1][i], data[2][i]);
    }

    printf("--------------------------------------\n\n");

    system("pause");
}