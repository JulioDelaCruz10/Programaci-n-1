#include <stdio.h>
int main(){
float promedio;
int estudiantes = 5;
int materias = 3;
int aprobado=0;
int reprobado=0;
float calificaciones[estudiantes][materias];
float estudianteMayor[estudiantes];
float estudianteMenor[estudiantes];
float materiaMayor[materias];
float materiaMenor[materias];
float mayor = 0;
float menor = 0;
float suma = 0;

for(int i=0; i < estudiantes; i++){
    printf("Ingrese las calificaciones del estudiante %d:\n", i+1);
    for (int j=0; j<materias; j++ ){
    do
    {
    printf("materia %d:\n", j+1);
    scanf("%f", &calificaciones[i][j]);
    
    if(calificaciones [i][j] < 0 || calificaciones[i][j] > 10){

        printf("Error! Ingrese una calificacion entre 0 y 10!\n");
    }else{
        printf("Se guardaron con exito!\n");
    }
    } while (calificaciones [i][j] < 0 || calificaciones[i][j] > 10);
    }
}

for(int i = 0; i < estudiantes; i++){
    suma = 0;
    
    
    
    for(int j = 0; j < materias; j++){
    suma = suma + calificaciones[i][j];
    }
printf("El promedio de notas del estudiante %d es: %.2f\n", i+1, suma / 3);

}

printf("\n");
printf("\n");

for(int j = 0; j < materias; j++){
suma = 0;
for(int i = 0; i < estudiantes; i++){
    suma = suma + calificaciones[i][j];

}
printf("El promedio de notas de la materia %d es: %.2f\n", j+1, suma / 5);

}

printf("\n");
printf("\n");

// Ciclo exclusivo para estudianted 
for(int i=0; i < estudiantes; i++){
    mayor = 0;
    menor =0;


// Ciclo exclusivo para materia de estudiantes especificas
    for(int j = 0; j < materias; j++){

        estudianteMayor[j] = calificaciones [i][j];


    }
    // ciclo exclusivo para materia mayor, estudiante especifico    
   mayor = estudianteMayor [0]; // Vamos a suponer que el primer valor es el mayor y luego compararemos
   menor = estudianteMenor [0]; // Vamos a suponer que el primer valor es el menor y luego compararemos
    for(int k =0; k < materias; k++){
            if(estudianteMayor[k]>mayor){
                mayor=estudianteMayor[k];
            }else{
                menor = estudianteMayor[k];
            }
    }
        printf("La calificacion mas alta del estudiante %d es: %.2f\n", i+1, mayor);
        printf("La calificacion menor del estudiante %d es: %.2f\n", i+1, menor);

}


printf("\n");
printf("\n");

// Ciclo exclusivo para materias 
for(int i=0; i < materias; i++){
    mayor = 0;
    menor =0;


// Ciclo exclusivo para estudiantes de materias especificas IMPORTANTISIMO QUE J E I ESTEN AL REVEZ PORQUE SI NO, NO FUNCIONA!!!!!!!
    for(int j = 0; j < estudiantes; j++){

        materiaMayor[j] = calificaciones [j][i];


    }
    // ciclo exclusivo para materia mayor, estudiante especifico    
   mayor = materiaMayor [0]; // Vamos a suponer que el primer valor es el mayor y luego compararemos
   menor = materiaMayor [0]; // Vamos a suponer que el primer valor es el menor y luego compararemos
    for(int k =0; k < estudiantes; k++){
            if(materiaMayor[k]>mayor){
                mayor=materiaMayor[k];
            }else{
                menor = materiaMayor[k];
            }
    }
        printf("La calificacion mas alta de la materia %d es: %.2f\n", i+1, mayor);
        printf("La calificacion menor de la materia %d es: %.2f\n", i+1, menor);

}

printf("\n");
printf("\n");

for(int i = 0; i < materias; i++){
    aprobado=0;
    reprobado=0;


    for(int j = 0; j< estudiantes; j++){

        if(calificaciones[j][i]>= 6){
            aprobado= aprobado+1;
        }else{
            reprobado= reprobado +1;
        }
    }

        printf("La cantidad de estudiantes aprobados en la materia %d es: %d\n",i+1,aprobado);
        printf("La cantidad de estudiantes reprobados en la materia %d es: %d\n",i+1, reprobado);

}

    return 0;
}

// Este deber fue realizado de 6pm a 10:45pm, con explicacion de un estudiante de 7mo de Semestre de Ingenieria en Software, un trabajo plenamente realizado
// con el sudor de mi frente, gracias por la molestia de leer este comentario

// ELABORADO POR: JULIO DE LA CRUZ