#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion.h"

int main() {
    struct Zona ciudades[5];
    int op;

    strcpy(ciudades[0].nombre, "Norte");
    strcpy(ciudades[1].nombre, "Sur");
    strcpy(ciudades[2].nombre, "Centro");
    strcpy(ciudades[3].nombre, "Este");
    strcpy(ciudades[4].nombre, "Oeste");

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 30; j++) {
            ciudades[i].historial[j] = 15.0 + i; 
        }
    }

    do {
        printf("\n======================================");
        printf("\n   SISTEMA DE MONITOREO AMBIENTAL");
        printf("\n======================================");
        printf("\n1. Ingresar datos de hoy");
        printf("\n2. Ver Predicciones y Recomendaciones");
        printf("\n3. Guardar Reporte");
        printf("\n4. Salir");
        printf("\nSeleccione: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                for (int i = 0; i < 5; i++) {
                    printf("\n--- %s ---", ciudades[i].nombre);
                    printf("\nNivel PM2.5: ");
                    scanf("%f", &ciudades[i].pmActual);
                    printf("Vel. Viento: ");
                    scanf("%f", &ciudades[i].climaViento);
                    calcularPrediccionSimple(ciudades, i);
                }
                break;

            case 2:
                printf("\n--- RESULTADOS ---");
                for (int i = 0; i < 5; i++) {
                    printf("\nZona: %s", ciudades[i].nombre);
                    printf("\n  Actual: %.2f", ciudades[i].pmActual);
                    printf("\n  Prediccion: %.2f", ciudades[i].prediccion);
                    darRecomendacion(ciudades[i]);
                }
                break;

            case 3:
                guardarEnArchivo(ciudades);
                break;
        }
    } while (op != 4);

    return 0;
}


// PARA CORRER SI NO VALE USAR 
// cd Programa_Final_DelaCruz
//gcc main.c gestion.c -o programa
//./programa