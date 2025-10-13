#include <stdio.h>
float leerFloat(){
float dato;
printf("Ingrese un numero: \n");
scanf("%f", &dato);
return dato;
}



float mayor(float a, float b, float c){
    if(a>b){
        return a;
    }
    if (b>c)
    {
        return b;
    }else{
        return c;
    }
    
    
}

int main(){
float num1, num2, num3;
num1 = leerFloat();
num2 = leerFloat();
num3 = leerFloat();

float resultado= mayor(num1,num2,num3);
printf("El valor mayor entre %.2f, %.2f y %.2f es %.2f", num1,num2,num3,resultado);

return 0;
}




