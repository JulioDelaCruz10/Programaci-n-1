#include <stdio.h>
#define MAX_FILA 100
#define MAX_COL 100

int main(){

    float matriz[MAX_FILA][MAX_COL];
    int fila, col;
    do{
        printf("Ingrese el numero de filas: \n");
        scanf("%d", &fila);
    } while(fila<1 || fila >100);

        do{
        printf("Ingrese el numero de columnas: \n");
        scanf("%d", &col);
    } while(col<1 || col >100);


    for (int i=0; i <fila; i++){
        for(int j=0; j<col; j++){
            printf("matriz[%2d][%2d]: \n",i,j);
            scanf("%f",&matriz[i][j]);
        }
    }

    printf("Imprimir matriz\n");
    for(int i=0; i<fila;i++){
        for(int j=0; j<col;j++){
            printf("%5.2f\n", matriz[i][j]);
        }
        printf("\n");
    }

}