#include "Vehiculo.hh"
#include "Vector2d.hh"

#include <iostream>
#include <sstream>
#include<string> 



Vector2d Vehiculo::getVelocidad(){return Velocidad;};
Vector2d Vehiculo::getPosicion(){return Posicion; };
float Vehiculo::Acelerar(const Vector2d&, const float _t){return 0.0;}


int main(){
     float Velocidad[2]={2.5,3.56}; 
     float Posicion[]={5.0,6.0}; 
     float f = *Velocidad;
     float z = *Posicion;  
    
    std::stringstream resultado;
    resultado << "{x:" << f << ",y:" << z << "}";
    std::string s = resultado.str();
    printf(s.c_str());
        

    

    
         
}