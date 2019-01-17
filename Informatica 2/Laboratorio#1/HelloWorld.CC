// el include abre el archivo on el nombre "x" 
#include <iostream>

//Dentro de el archivo siguiente esta el comando #define Mensaje " Hello World "
#include "mensaje1.hh"
#include "valor3.hh"

int main(){
    // se utiliza el "std" para acceder a los ,etodos incluidos en el lenguaje
    printf ("%s, %i\n", Mensaje1 , Valor3);
    // se retorna el 0 para indicar que el programa se ejecuta sin errores
    return 0;
}