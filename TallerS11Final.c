#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
    int id;
    char titulo[101];
    char autor[51];
    int anio;
    char estado[11]; // "Disponible" o "Prestado"
} Libro;

void limpiarBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int existeID(Libro v[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (v[i].id == id) return 1;
    }
    return 0;
}

void mostrarTabla(Libro v[], int n) {
    if (n == 0) {
        printf("\nNo hay libros registrados.\n");
        return;
    }

    printf("\n%-4s | %-6s | %-35s | %-20s | %-6s | %-10s\n",
           "#", "ID", "TITULO", "AUTOR", "ANIO", "ESTADO");
    printf("---- | ------ | ----------------------------------- | -------------------- | ------ | ----------\n");

    for (int i = 0; i < n; i++) {
        printf("%-4d | %-6d | %-35.35s | %-20.20s | %-6d | %-10s\n",
               i + 1,
               v[i].id,
               v[i].titulo,
               v[i].autor,
               v[i].anio,
               v[i].estado);
    }
}

void mostrarLibro(Libro x) {
    printf("\n--- DATOS DEL LIBRO ---\n");
    printf("ID: %d\n", x.id);
    printf("Titulo: %s\n", x.titulo);
    printf("Autor: %s\n", x.autor);
    printf("Anio: %d\n", x.anio);
    printf("Estado: %s\n", x.estado);
}

int buscarID(Libro v[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (v[i].id == id) return i;
    }
    return -1;
}

int buscarTitulo(Libro v[], int n, const char titulo[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(v[i].titulo, titulo) == 0) return i;
    }
    return -1;
}

void registrar(Libro v[], int *n) {
    Libro x;

    if (*n >= MAX) {
        printf("\nNo se pueden agregar mas de %d libros.\n", MAX);
        return;
    }

    do {
        printf("ID (entero unico): ");
        if (scanf("%d", &x.id) != 1) {
            printf("Entrada invalida.\n");
            limpiarBuffer();
            x.id = -1;
            continue;
        }
        limpiarBuffer();

        if (x.id <= 0) {
            printf("El ID debe ser positivo.\n");
            x.id = -1;
        } else if (existeID(v, *n, x.id)) {
            printf("Ese ID ya existe.\n");
            x.id = -1;
        }
    } while (x.id <= 0);

    do {
        printf("Titulo: ");
        fgets(x.titulo, sizeof(x.titulo), stdin);
        x.titulo[strcspn(x.titulo, "\n")] = 0;
    } while (strlen(x.titulo) == 0);

    do {
        printf("Autor: ");
        fgets(x.autor, sizeof(x.autor), stdin);
        x.autor[strcspn(x.autor, "\n")] = 0;
    } while (strlen(x.autor) == 0);

    do {
        printf("Anio: ");
        if (scanf("%d", &x.anio) != 1) {
            printf("Entrada invalida.\n");
            limpiarBuffer();
            x.anio = -1;
        }
        limpiarBuffer();
    } while (x.anio < 0 || x.anio > 2100);

    strcpy(x.estado, "Disponible");

    v[*n] = x;
    (*n)++;

    printf("\nLibro registrado correctamente.\n");
}

void buscar(Libro v[], int n) {
    int op;

    if (n == 0) {
        printf("\nNo hay libros registrados.\n");
        return;
    }

    printf("\nBuscar por:\n1) ID\n2) Titulo\nOpcion: ");
    scanf("%d", &op);
    limpiarBuffer();

    if (op == 1) {
        int id;
        printf("ID: ");
        scanf("%d", &id);
        limpiarBuffer();

        int idx = buscarID(v, n, id);
        if (idx == -1) printf("No encontrado.\n");
        else mostrarLibro(v[idx]);

    } else if (op == 2) {
        char t[101];
        printf("Titulo: ");
        fgets(t, sizeof(t), stdin);
        t[strcspn(t, "\n")] = 0;

        int idx = buscarTitulo(v, n, t);
        if (idx == -1) printf("No encontrado.\n");
        else mostrarLibro(v[idx]);
    }
}

void actualizarEstado(Libro v[], int n) {
    int id;

    printf("ID del libro: ");
    scanf("%d", &id);
    limpiarBuffer();

    int idx = buscarID(v, n, id);
    if (idx == -1) {
        printf("No existe.\n");
        return;
    }

    if (strcmp(v[idx].estado, "Disponible") == 0)
        strcpy(v[idx].estado, "Prestado");
    else
        strcpy(v[idx].estado, "Disponible");

    printf("Nuevo estado: %s\n", v[idx].estado);
}

void eliminar(Libro v[], int *n) {
    int id;

    printf("ID a eliminar: ");
    scanf("%d", &id);
    limpiarBuffer();

    int idx = buscarID(v, *n, id);
    if (idx == -1) {
        printf("No existe.\n");
        return;
    }

    for (int i = idx; i < *n - 1; i++) {
        v[i] = v[i + 1];
    }
    (*n)--;

    printf("Libro eliminado.\n");
}

int main() {
    Libro libros[MAX];
    int n = 0;
    int op;

    do {
        printf("\n===== MENU BIBLIOTECA =====\n");
        printf("1. Registrar libro\n");
        printf("2. Mostrar lista\n");
        printf("3. Buscar\n");
        printf("4. Cambiar estado\n");
        printf("5. Eliminar\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &op);
        limpiarBuffer();

        switch (op) {
            case 1: registrar(libros, &n); break;
            case 2: mostrarTabla(libros, n); break;
            case 3: buscar(libros, n); break;
            case 4: actualizarEstado(libros, n); break;
            case 5: eliminar(libros, &n); break;
        }

    } while (op != 0);

    return 0;
}