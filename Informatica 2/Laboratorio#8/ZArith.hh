#pragma once 
#include "Semantica.hh"


class ZArith : public Semantica{

    public: 
    
    ZArith(int base); 
    virtual bool parse(const std::string valor, int& resultado)const override; 
    virtual int opSuma(const int arg1, const int arg2)const override; 
    virtual int opProducto(const int arg1, const int arg2)const override;
   

    private: 

    int arg1; 
    int arg2;
    int _base; 


}; 