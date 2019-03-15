#include "Vector2d.hh"
#include<string> 


//Tarea 2 , 3 , 4 
class Vehiculo{

    public:
    Vehiculo();    
    Vector2d getVelocidad();
    Vector2d getPosicion();
    const std::string to_string() const;

    void acelerar(const Vector2d aceleracion, float tiempo);
    void avanzar(float t); 
    
    
    
    private: 
    Vector2d Velocidad; 
    Vector2d Posicion; 

};