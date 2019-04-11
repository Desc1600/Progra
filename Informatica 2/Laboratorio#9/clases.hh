#pragma once


//Tarea#1
 
class Expression {
    public: 
    virtual double evaluar(); 

}; 

//Tarea#2 
class Valor: public Expression{
    public: 
    Valor(double valor);
    virtual double evaluar() override;   
    
    double valor; 
};

//Tarea#3 
class OperacionBinaria: public Expression{
        public: 

        OperacionBinaria(Expression* operador1, Expression* operador2){}
        virtual double evaluar()override; 
        virtual double operar(const double op1, const double op2)const = 0;

        private:
        double op1; 
        double op2; 
        Expression* operador1;
        Expression* operador2;
        
}; 

//Tarea #4

class Suma : public OperacionBinaria{
    
    public: 

    Suma(Expression* _operador1, Expression* _operador2): operador1(_operador1),operador2(_operador2){}//error si no encontras forma borra esta linea
    virtual double evaluar()override;  
    virtual double operar(const double op1, const double op2)const override;

    private: 
    Expression* operador1;
	Expression* operador2;


};

class Multiplicacion : public OperacionBinaria{
    
    public: 

    Multiplicacion(Expression* _operador1, Expression* _operador2):operador1(_operador1), operador2(_operador2){}//error  //error si no encontras forma borra esta linea
    virtual double evaluar()override; 
    virtual double operar(const double op1, const double op2)const override;

    private: 
    Expression* operador1;
	Expression* operador2;

   
};


