#pragma once
#include "Figura.hh"
#include <string> 
#include"Vector2d.hh"

//Tarea #1 
class Circulo : public Figura{

        public:

        Circulo(Vector2d centro, double _radio); 
        
        virtual double area()const override; 
        virtual void escalar(const double escalax) override;
        virtual void mover(const Vector2d lugarx) override;
        virtual bool estaAdentro(const Vector2d posicionx) override; 

       virtual const std::string to_String() const override;


        ~Circulo(); 

              
        private: 

        double _radio; 
        Vector2d centro; 


       

}; 
