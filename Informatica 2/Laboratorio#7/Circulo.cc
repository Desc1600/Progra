#include"Circulo.hh"
#include"Vector2d.hh"
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string> 


//Tarea#2 

Circulo::Circulo(Vector2d centro, double _radio): centro(centro) ,_radio(_radio){}

double Circulo::area()const {
    double areaC = M_PI * pow(_radio,2); 
    return areaC; 
}

void Circulo::escalar(const double escalax){
    double nuevoradio = _radio * escalax;
}

void Circulo::mover(const Vector2d lugarx){
    Vector2d centro = lugarx; 
}


bool Circulo::estaAdentro(const Vector2d posicion){
        double distancia;
        distancia = sqrt((centro.x - posicion.x) + (centro.y - posicion.y));

        if (distancia >= _radio){
            return false;

        }else {
            return true;
        }
    }
    

const std::string Circulo::to_String()const{
    std::stringstream resultado;
    resultado << "{c( " << centro.to_string() << " " << _radio << ")}";
    std::string s = resultado.str();
    printf(s.c_str());
    return 0;
   
}


Circulo::~Circulo(){

    printf("Se destruyo\n");
    delete &_radio;
}

int main(){

}

