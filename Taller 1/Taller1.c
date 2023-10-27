#include <stdio.h>

int main() {
    int num;
    char op;

    printf("Ingrese un numero: ");
    scanf("%d", &num);
    printf("Ingrese una opcion: ");
    scanf(" %c", &op); // Note the space before %c to consume any whitespace characters

    switch (op) {
        case 's':
            num += 10;
            break;
        case 'r':
            num -= 10;
            break;
        case 'm':
            num *= 10;
            break;
        case 't':
            num -= 5;
            break;
        default:
            num = 0;
            break;
    }

    printf("El numero es: %d\n", num);

    return 0;
}
