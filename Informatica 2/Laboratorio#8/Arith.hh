//Tarea #3 
#pragma once 
#include "Semantica.hh"


class Arith : public Semantica{

    public: 
    
    Arith(); 
    virtual bool parse(const std::string valor, int& resultado)const override; 
    virtual int opSuma(const int arg1, const int arg2)const override; 
    virtual int opProducto(const int arg1, const int arg2)const override;
    

    private: 

    int arg1; 
    int arg2;
     


}; 