#include "Vector2d.hh"
#include <string> 
#include <iostream>
#include <sstream>


//Tarea 1 
Vector2d::Vector2d(const float _x, const float _y) : x( _x), y( _y) {}

Vector2d Vector2d::operator+(const Vector2d& otro) const{
            return {x + otro.x, y + otro.y}; 
                        
}

float Vector2d::getX()const {
     return x; 
}

float Vector2d::getY()const {
    return y; 
}

const std::string Vector2d::to_string()const{

    std::stringstream valtotal;
    valtotal << "{x:" << x << ",y:" << y << "}";
    std::string s = valtotal.str();
    printf(s.c_str());
}



