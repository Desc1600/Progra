#include "Vector2d.hh"
#include "Vehiculo.hh"
#include <string> 
#include <iostream>
#include <sstream>
using namespace std; 


Vehiculo::Vehiculo() : Velocidad(0.0,0), Posicion(0.0,0.0) {}


Vector2d Vehiculo::getVelocidad(){
        return Velocidad; 
}

Vector2d Vehiculo::getPosicion(){
        return Posicion; 
}

const std::string Vehiculo::to_string()const {
    std::stringstream valtotal;
    valtotal << "{La posicion es:" << Posicion.to_string() << ",La velocidad es:" << Velocidad.to_string() << "}";
    std::string s = valtotal.str();
    printf(s.c_str());
}

void Vehiculo::acelerar(const Vector2d aceleracion, float tiempo){
    Velocidad.x = (Velocidad.x + aceleracion.x )* tiempo;
    Velocidad.y = (Velocidad.y + aceleracion.y )* tiempo;
    Posicion.x = (Posicion.x + Velocidad.x)* tiempo;
    Posicion.y = (Posicion.y + Velocidad.y) * tiempo;
    
}


void Vehiculo::avanzar(float t){

    Posicion.x = (Posicion.x + Velocidad.x)* t;
    Posicion.y = (Posicion.y + Velocidad.y )* t;
}












