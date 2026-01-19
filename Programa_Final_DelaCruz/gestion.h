#ifndef GESTION_H
#define GESTION_H

struct Zona {
    char nombre[50];
    float pmActual;
    float historial[30];
    float climaViento;
    float prediccion;
};

void calcularPrediccionSimple(struct Zona zonas[], int i);
void darRecomendacion(struct Zona z);
void guardarEnArchivo(struct Zona zonas[]);

#endif