#pragma once
#include "Figura.hh"
#include <string.h> 

//Tarea#3 

class Rectangulo : public Figura{

        public:

        Rectangulo(Vector2d esquinaInf, double _ancho , double _largo ); 
        virtual double area()const override; 
        virtual void escalar(const double escalax) override;
        virtual void mover(const Vector2d lugarx) override;
        virtual bool estaAdentro(const Vector2d posicionx) override; 

        virtual const std::string to_string() const;


        private: 

        Vector2d esquinaInf;
        double _ancho;
        double _largo;

        
        

}; 
