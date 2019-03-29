//Tarea #2 
#pragma once 

#include<string> 

class Semantica{
    
    public: 
    
    virtual bool parse(const std::string valor, int& resultado)const = 0; 
    virtual int opSuma(const int arg1, const int arg2)const = 0; 
    virtual int opProducto(const int arg1, const int arg2)const = 0; 
    

}; 