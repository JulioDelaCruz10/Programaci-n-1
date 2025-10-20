#include <stdio.h>

int main(void) {

    int agenda[5][9] = {0};

    const char *diasN[5] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes"};
    const char *horasN[9] = {
        "09:00-10:00", "10:00-11:00", "11:00-12:00",
        "12:00-13:00", "13:00-14:00", "14:00-15:00",
        "15:00-16:00", "16:00-17:00", "17:00-18:00"
    };

    int opcion;
    do {
        printf("\n=== AGENDA JUANITO (paseo de perros) ===\n");
        printf("1) Agendar contrato\n");
        printf("2) Mostrar agenda\n");
        printf("3) Salir\n");
        printf("Elija una opcion: ");
        if (scanf("%d", &opcion) != 1) {
        
            int c; while ((c = getchar()) != '\n' && c != EOF);
            opcion = -1;
        }

        if (opcion == 1) {
            int d, s;
            printf("\n--- Agendar contrato ---\n");
            printf("Dias: 1=Lunes, 2=Martes, 3=Miercoles, 4=Jueves, 5=Viernes\n");
            printf("Ingrese dia (1-5): ");
            if (scanf("%d", &d) != 1) { int c; while ((c=getchar())!='\n' && c!=EOF); d = -1; }

            printf("\nEspacios horarios:\n");
            for (int i = 0; i < 9; i++) {
                printf("%d) %s\n", i+1, horasN[i]);
            }
            printf("Ingrese hora (1-9): ");
            if (scanf("%d", &s) != 1) { int c; while ((c=getchar())!='\n' && c!=EOF); s = -1; }

     
            if (d < 1 || d > 5) {
                printf("Error: dia inexistente. Ingrese un dia de Lunes a Viernes\n");
                continue;
            }
            if (s < 1 || s > 9) {
                printf("Error: Horario invalido, ingrese uno dentro del rango.\n");
                continue;
            }

   
            d--; s--;

            if (agenda[d][s] == 1) {
                printf("Conflicto: %s %s ya esta RESERVADO.\n", diasN[d], horasN[s]);
            } else {
                agenda[d][s] = 1;
                printf("OK: reservado %s %s.\n", diasN[d], horasN[s]);
            }

        } else if (opcion == 2) {
            printf("\n--- Mostrar agenda ---\n");


            printf("%-12s", ""); 
            for (int s = 0; s < 9; s++) {
                printf("%-13s", horasN[s]);
            }
            printf("\n");


            for (int d = 0; d < 5; d++) {
                printf("%-12s", diasN[d]);
                for (int s = 0; s < 9; s++) {
                    printf("%-13s", agenda[d][s] ? "RESERVADO" : "LIBRE");
                }
                printf("\n");
            }

  
            int libres = 0, ocupados = 0;
            for (int d = 0; d < 5; d++) {
                for (int s = 0; s < 9; s++) {
                    if (agenda[d][s]) ocupados++; else libres++;
                }
            }
            printf("\nTotal LIBRE: %d | Total RESERVADO: %d\n", libres, ocupados);

        } else if (opcion == 3) {
            printf("Saliendo...\n");
        } else {
            printf("** Opcion invalida\n");
        }

    } while (opcion != 3);

    return 0;
}