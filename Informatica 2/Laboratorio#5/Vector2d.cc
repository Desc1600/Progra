#include "Vector2d.hh"

#include <iostream>
#include <sstream>
#include<string> 
using namespace std; 
 

Vector2d::Vector2d(const float _x, const float _y) : x(_x), y(_y) {}



//Tarea 1 
int main(){
    int f = 2, z = 5;
      
    
    std::stringstream resultado;
    resultado << "{x:" << f << ",y:" << z << "}";
    std::string s = resultado.str();
    printf(s.c_str());

}