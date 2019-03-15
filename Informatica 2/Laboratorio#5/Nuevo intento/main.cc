#include "Vehiculo.hh"
#include "Vector2d.hh"
#include <iostream>
#include <string>

int main(){

    Vehiculo carro;
    carro.acelerar(Vector2d(3,1), 5);
    carro.avanzar(10);
    
    std::string estadoActual = carro.to_string(); 
    printf(estadoActual.c_str());
    
    carro.acelerar(Vector2d(-7.2,8), 4);
    carro.avanzar(9); 

    std::string estadoActual2 = carro.to_string(); 
    printf(estadoActual2.c_str()); 
}