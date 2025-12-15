#include <stdio.h>
#include "delacruz.h"

int main()
{
    struct Producto producto[MAX_PRODUCTOS];
    ingresarProductos(producto,MAX_PRODUCTOS);
    mostrarProductos(producto,MAX_PRODUCTOS);

    printf("\nTotal: %.2f " ,totalInventario(producto,MAX_PRODUCTOS));


    return 0;

}