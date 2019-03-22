#include"rectangulo.hh"
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>


Rectangulo::Rectangulo(Vector2d esquinaInf, double _ancho , double _largo ): esquinaInf(esquinaInf), _largo(_largo), _ancho(_ancho) {}

double Rectangulo::area()const {
    double areaR = _largo * _ancho; 
    return areaR; 
}

void Rectangulo::escalar(const double escalax){
    double nuevorec = (_ancho * escalax)+(_largo * escalax);
}

void Rectangulo::mover(const Vector2d lugarx){
    Vector2d esquinaInf = lugarx; 
}

bool Rectangulo::estaAdentro(const Vector2d posicion){
        double distancia;
        if(_ancho < posicion.x || _largo < posicion.y){
            return false;

        }else {
            return true;
        }
    }
    
const std::string Rectangulo::to_string()const {
    std::stringstream valtotal;
    valtotal << "{r( " << esquinaInf.to_string() << " " << _largo << "" << _ancho << ")}";
    std::string s = valtotal.str();
    printf(s.c_str());
   
}

//int main(){}



