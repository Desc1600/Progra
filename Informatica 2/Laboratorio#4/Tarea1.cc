#include<iostream>
void porValor(int valor){
    valor = 42;
}

void porReferencia(int& valor){
    valor = 42;
}

int main(){
    int valor1 = 0;
    int valor2 = 0;

    porValor(valor1);
    porReferencia(valor2);

    printf("El resultado por valor es %i\n", valor1);
    printf("El resultado por referencia es %i\n", valor2);
}
/* En el void porValor lo unico que se hace es indicar que valor es igual a 42 
pero nunca realiza ningun cambio on la variable Valor1 
en cambio en porReferencia lo que gace es hacer referencia al espacio 
de memoria de valor2 por lo que el cambio de valor a 42 se hace en ese espacio
cambiando el valor de valor2
*/