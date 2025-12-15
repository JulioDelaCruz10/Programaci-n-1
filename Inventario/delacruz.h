#ifndef DELACRUZ_H
#define MAX_PRODUCTOS 5

struct Producto{
    char nombre[50];
    float precio;
    int cantidad;
};
void ingresarProducto(struct Producto[], int n);
void mostrarProducto(struct Producto[], int n);
float totalInventario(struct Producto[], int n);

#endif