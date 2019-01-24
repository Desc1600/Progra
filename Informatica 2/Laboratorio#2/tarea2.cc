#include <iostream>

int main(){
    int valor1 = 1;
    int valor2 = 1;

    int resultado = ++valor1 + valor2++;

    std::printf("valor1: %i, valor2: %i, resultado: %i\n", valor1, valor2, resultado);
} 
// el resultado es 3 gracias a la jerarquia en la que se hace la operacion
// es decir lo que hace en resultado es aumentar el valor1 y luego sumar el valor 2 lo que seria igual a 2+1= 3
// y por ultimo lo que hace es aumentar el valor 2.