#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 5
#define MAX_NOMBRE 64

// Prototipos
int comparar_insensible(const char *a, const char *b);
int encontrar_producto(char nombres[][MAX_NOMBRE], int total, const char *clave);
void agregar_producto(char nombres[][MAX_NOMBRE], int *total, int cantidades[], float tiempo_unitario[], float recursos_unitarios[]);
void editar_producto(char nombres[][MAX_NOMBRE], int total, int cantidades[], float tiempo_unitario[], float recursos_unitarios[]);
void eliminar_producto(char nombres[][MAX_NOMBRE], int *total, int cantidades[], float tiempo_unitario[], float recursos_unitarios[]);
void listar_productos(char nombres[][MAX_NOMBRE], int total, int cantidades[], float tiempo_unitario[], float recursos_unitarios[]);
void calcular_y_verificar(int total, int cantidades[], float tiempo_unitario[], float recursos_unitarios[]);

int main() {
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    int cantidades[MAX_PRODUCTOS];
    float tiempo_unitario[MAX_PRODUCTOS];
    float recursos_unitarios[MAX_PRODUCTOS];
    int total = 0;
    int opcion;

    while (1) {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1) Agregar producto\n");
        printf("2) Editar producto\n");
        printf("3) Eliminar producto\n");
        printf("4) Listar productos\n");
        printf("5) Calcular totales y verificar\n");
        printf("6) Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: agregar_producto(nombres, &total, cantidades, tiempo_unitario, recursos_unitarios); break;
            case 2: editar_producto(nombres, total, cantidades, tiempo_unitario, recursos_unitarios); break;
            case 3: eliminar_producto(nombres, &total, cantidades, tiempo_unitario, recursos_unitarios); break;
            case 4: listar_productos(nombres, total, cantidades, tiempo_unitario, recursos_unitarios); break;
            case 5: calcular_y_verificar(total, cantidades, tiempo_unitario, recursos_unitarios); break;
            case 6: printf("Saliendo...\n"); return 0;
            default: printf("Opción inválida.\n");
        }
    }
return 0;
}

// FUNCIONES
// Comparación insensible a mayúsculas/minúsculas
int comparar_insensible(const char *a, const char *b) {
    while (*a && *b) {
        char x = (*a >= 'A' && *a <= 'Z') ? *a + 32 : *a;
        char y = (*b >= 'A' && *b <= 'Z') ? *b + 32 : *b;
        if (x != y) return x - y;
        a++; b++;
    }
    return (*a ? *a : 0) - (*b ? *b : 0);
}

// Buscar producto por nombre
int encontrar_producto(char nombres[][MAX_NOMBRE], int total, const char *clave) {
    for (int i = 0; i < total; i++) {
        if (comparar_insensible(nombres[i], clave) == 0) return i;
    }
    return -1;
}

// Agregar producto
void agregar_producto(char nombres[][MAX_NOMBRE], int *total, int cantidades[], float tiempo_unitario[], float recursos_unitarios[]) {
    if (*total >= MAX_PRODUCTOS) {
        printf("No se pueden agregar más productos.\n");
        return;
    }

    char nombre[MAX_NOMBRE];
    printf("Ingrese nombre del producto: ");
    scanf("%s", nombre);

    if (encontrar_producto(nombres, *total, nombre) != -1) {
        printf("Ese producto ya existe.\n");
        return;
    }

    strcpy(nombres[*total], nombre);

    printf("Ingrese cantidad demandada: ");
    scanf("%d", &cantidades[*total]);

    printf("Ingrese tiempo por unidad: ");
    scanf("%f", &tiempo_unitario[*total]);

    printf("Ingrese recursos por unidad: ");
    scanf("%f", &recursos_unitarios[*total]);

    (*total)++;
    printf("Producto agregado exitosamente.\n");
}

// Editar producto
void editar_producto(char nombres[][MAX_NOMBRE], int total, int cantidades[], float tiempo_unitario[], float recursos_unitarios[]) {
    if (total == 0) {
        printf("No hay productos.\n");
        return;
    }

    char nombre[MAX_NOMBRE];
    printf("Ingrese nombre del producto a editar: ");
    scanf("%s", nombre);

    int i = encontrar_producto(nombres, total, nombre);
    if (i == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    printf("Nuevo nombre (escriba '-' para mantener): ");
    scanf("%s", nombre);
    if (strcmp(nombre, "-") != 0) strcpy(nombres[i], nombre);

    int temp_int;
    float temp_float;

    printf("Nueva cantidad (-1 para mantener): ");
    scanf("%d", &temp_int);
    if (temp_int != -1) cantidades[i] = temp_int;

    printf("Nuevo tiempo por unidad (-1 para mantener): ");
    scanf("%f", &temp_float);
    if (temp_float != -1) tiempo_unitario[i] = temp_float;

    printf("Nuevos recursos por unidad (-1 para mantener): ");
    scanf("%f", &temp_float);
    if (temp_float != -1) recursos_unitarios[i] = temp_float;

    printf("Producto actualizado.\n");
}

// Eliminar producto
void eliminar_producto(char nombres[][MAX_NOMBRE], int *total, int cantidades[], float tiempo_unitario[], float recursos_unitarios[]) {
    if (*total == 0) {
        printf("No hay productos.\n");
        return;
    }

    char nombre[MAX_NOMBRE];
    printf("Ingrese nombre del producto a eliminar: ");
    scanf("%s", nombre);

    int i = encontrar_producto(nombres, *total, nombre);
    if (i == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    for (int j = i; j < *total - 1; j++) {
        strcpy(nombres[j], nombres[j+1]);
        cantidades[j] = cantidades[j+1];
        tiempo_unitario[j] = tiempo_unitario[j+1];
        recursos_unitarios[j] = recursos_unitarios[j+1];
    }

    (*total)--;
    printf("Producto eliminado correctamente.\n");
}

// Listar productos, lo usamos como prueba para saber si estan guardandose correctamente los productos
void listar_productos(char nombres[][MAX_NOMBRE], int total, int cantidades[], float tiempo_unitario[], float recursos_unitarios[]) {
    if (total == 0) {
        printf("No hay productos registrados.\n");
        return;
    }

    printf("\n%-4s %-20s %-10s %-12s %-12s\n", "ID", "Nombre", "Cantidad", "Tiempo/u", "Recursos/u");
    for (int i = 0; i < total; i++) {
        printf("%-4d %-20s %-10d %-12.2f %-12.2f\n", i + 1, nombres[i], cantidades[i], tiempo_unitario[i], recursos_unitarios[i]);
    }
}

// Calcular totales y verificar
void calcular_y_verificar(int total, int cantidades[], float tiempo_unitario[], float recursos_unitarios[]) {
    if (total == 0) {
        printf("No hay productos registrados.\n");
        return;
    }

    float tiempo_total = 0, recursos_totales = 0;
    for (int i = 0; i < total; i++) {
        tiempo_total += cantidades[i] * tiempo_unitario[i];
        recursos_totales += cantidades[i] * recursos_unitarios[i];
    }

    printf("\nTiempo total requerido: %.2f\n", tiempo_total);
    printf("Recursos totales requeridos: %.2f\n", recursos_totales);

    float tiempo_disp, recursos_disp;
    printf("Ingrese tiempo disponible: ");
    scanf("%f", &tiempo_disp);
    printf("Ingrese recursos disponibles: ");
    scanf("%f", &recursos_disp);

    if (tiempo_disp >= tiempo_total && recursos_disp >= recursos_totales) {
        printf("\n La fábrica PUEDE cumplir la demanda.\n");
    } else {
        printf("\n La fábrica NO puede cumplir la demanda.\n");
        if (tiempo_disp < tiempo_total)
            printf("  Tiempo insuficiente (%.2f requerido)\n", tiempo_total);
        if (recursos_disp < recursos_totales)
            printf("  Recursos insuficientes (%.2f requerido)\n", recursos_totales);
    }
}