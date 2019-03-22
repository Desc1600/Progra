#include "Vector2d.hh"
#pragma once
#include <string> 





class Figura{

    public: 

    virtual double area()const = 0; 
    virtual void escalar(const double escala) = 0;
    virtual void mover(const Vector2d lugar) = 0;
    virtual bool estaAdentro(const Vector2d posicion) = 0; 
    
    virtual const std::string to_String() const = 0;

};