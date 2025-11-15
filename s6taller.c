#include <stdio.h>
#include <string.h>

// PROTOTIPOS, importante poner aqui las funciones, porque si no el programa no lee
void Ingresarproducto(char nombre [10][50], float precio [10]);
void Verproducto(char nombre[10][50], float precio[10], char buscar[50]);
void Preciototal(char nombre[10][50], float precio[10], float Total);
void MasCaro(char nombre[10][50], float precio[10]);
void MasBarato(char nombre[10][50], float precio[10]);
void PromedioTotal(char nombre[10][50], float precio[10], float Promedio);

int main (){
    // ingresar producto, precio total, mas caro, mas barato, promedio, buscar producto : OPCIONES INVENTARIO 
    float precios [10];
    char nombre [10][50];
    int opcion = 0;
    float Total = 0;
    float Promedio = 0;

    //Menu para todo el sistema 
    do
    {
        printf("BIENVENIDO AL SISTEMA DE INVENTARIO... \n");
        printf("Escoja una opcion \n");
        printf("1. Registrar producto\n");
        printf("2. Precio total del inventario \n");
        printf("3. Producto mas caro \n");
        printf("4. Producto mas barato \n");
        printf("5. Promedio de costo de inventario\n");
        printf("6. Buscar producto por su nombre\n");
        printf("7. Salir del sistema\n");

        scanf("%d", &opcion); 

        switch (opcion)
        {
        case 1:
            Ingresarproducto(nombre, precios);
            break;

        case 2:
            Preciototal(nombre, precios, Total);
            break;

        case 3:
            MasCaro(nombre, precios);
            break;

        case 4:
            MasBarato(nombre, precios);
            break;

        case 5:
            PromedioTotal(nombre, precios, Promedio);
            break;

        case 6:
                printf("Ingrese el nombre del producto que desea buscar\n");
            char buscar[50];         
            scanf("%s", buscar);   
            Verproducto(nombre, precios, buscar);
            break;
            
        default:
            break;
        }

    } while (opcion != 7 );

    return 0;
}


void Ingresarproducto(char nombre [10][50], float precio [10]){ // Funcion para el caso 1
    for (int i = 0; i < 10; i++){
        printf("Ingrese el nombre del articulo No. %d:\n", i + 1);
        scanf("%s", nombre[i]);
        printf("Ingrese el precio del articulo No. %d:\n", i + 1);
        scanf("%f", &precio[i]);  
    }
}


void Verproducto(char nombre[10][50], float precio[10], char buscar[50]) { // Funcion para el caso 6, se hace primero para comprobar que funciona el guardado de producto
    int encontrado = 0;

    for (int i = 0; i < 10; i++) {

        if (strcmp(nombre[i], buscar) == 0) {  
            printf("Producto Encontrado, numero %d: %s / El valor es: %.2f\n",
                   i + 1, nombre[i], precio[i]);
            encontrado = 1;
            break;  
        }
    }

    if (!encontrado) {
        printf("El producto no existe\n");
    }
}

void Preciototal(char nombre[10][50], float precio[10], float Total){ //Funcion caso 2
    for(int i=0; i<10;i++){
        Total += precio[i];
    }
    printf("El precio total del inventario es: %.2f\n", Total);
}

void MasCaro(char nombre[10][50], float precio[10]) { //Funcion caso 3
    float mascaro = precio[0]; 
    int indice = 0;            

    for (int i = 1; i < 10; i++) { // tomo el valor de 1 porque vamos a empezar desde esa posicion la comparacion, ya que mascaro esta en la posicion 0 del arreglo de precio
        if (precio[i] > mascaro) {
            mascaro = precio[i];
            indice = i;
        }
    }

    printf("El producto más caro es: %s con un precio de %.2f\n",
           nombre[indice], mascaro);
}

void MasBarato(char nombre[10][50], float precio[10]) { //Funcion caso 4
    float masbarato = precio[0]; 
    int indice = 0;            

    for (int i = 1; i < 10; i++) { // Lo mismo que mas caro, pero invertido
        if (precio[i] < masbarato) {
            masbarato = precio[i];
            indice = i;
        }
    }

    printf("El producto más barato es: %s con un precio de %.2f\n",
           nombre[indice], masbarato);
}

void PromedioTotal(char nombre[10][50], float precio[10], float Promedio){ //Funcion caso 5
    for(int i=0; i<10;i++){
        Promedio += precio[i] / 10;
    }
    printf("El promedio del inventario es: %.2f\n", Promedio);
}