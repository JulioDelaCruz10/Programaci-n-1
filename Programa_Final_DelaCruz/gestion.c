#include <stdio.h>
#include <string.h>
#include "gestion.h"

void calcularPrediccionSimple(struct Zona zonas[], int i) {
    float hoy = zonas[i].pmActual;
    float ayer = zonas[i].historial[29];
    
    float factorClima = 1.0;
    if (zonas[i].climaViento > 20) {
        factorClima = 0.7; 
    }

    zonas[i].prediccion = ((hoy * 0.7) + (ayer * 0.3)) * factorClima;
}

void darRecomendacion(struct Zona z) {
    // Agregamos un salto de linea al inicio para que no se pegue
    if (z.pmActual > 25.0) {
        printf("\n   ALERTA: Sugiere cerrar industrias y reducir trafico.\n");
    } else {
        printf("\n   INFO: Aire aceptable. No hay restricciones.\n");
    }
}

void guardarEnArchivo(struct Zona zonas[]) {
    FILE *archivo;
    archivo = fopen("reporte_aire.txt", "w");
    
    if (archivo != NULL) {
        fprintf(archivo, "--- REPORTE DE CONTAMINACION ---\n");
        for (int i = 0; i < 5; i++) {
            fprintf(archivo, "Zona: %s | Nivel: %.2f | Prediccion: %.2f\n", 
                    zonas[i].nombre, zonas[i].pmActual, zonas[i].prediccion);
        }
        fclose(archivo);
        printf("\nDatos guardados en reporte_aire.txt\n");
    }
}