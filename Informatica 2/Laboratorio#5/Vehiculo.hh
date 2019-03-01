#include "Vector2d.hh"
#include<string> 


//Tarea 2 

class Vehiculo{

    public:
    //Vehiculo(Vector2d&, const float t);
    Vector2d getVelocidad();
    Vector2d getPosicion();
    Vehiculo operator*();
      
    float Acelerar(const Vector2d&, const float t); 
   
    
    private:
    Vector2d Velocidad = {0,0}; 
    Vector2d Posicion= {0,0}; 

};


