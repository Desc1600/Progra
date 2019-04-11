#include<iostream> 
#include<string.h> 
#include "clases.hh"
#include <iostream>

double Valor::evaluar(){
        return valor;
        }


double OperacionBinaria::evaluar(){
    double r1 = operador1->evaluar();
    double r2 = operador2->evaluar();
    double resultado = this -> operar(r1, r2); 
    return resultado; 
    }

double Suma::operar(const double op1, const double op2)const{

    double resultadoSuma = op1 + op2; 
    return resultadoSuma; 

}

double Multiplicacion::operar(const double op1, const double op2)const{

    double resultadoM = op1 * op2; 
    return resultadoM; 

}

//Tarea #5
bool parse(const std::string expression, Expression* resultado){
    int tam = expression.size();
    int i = 0;
    for(int i = 0; i < tam; i++)
    {
        if(expression[i] == '+' || expression[i] == '*' ){
            
            if (( tam - 1 )== '+' || ( tam + 1 )== '+'  ){

                resultado =  new Suma(new Valor(expression[i-1]));//error

            return true;
            }

        }else if(( tam - 1 )== '*' || ( tam + 1 )== '*' ) {

            resultado = new Multiplicacion(new Valor(expression[i-1])); //error 

            return true;
        }else {return false ;
        
        }
        
    }
    return false;
}



int main(){
   std::string entrada("1+2*3");
    Expression* expr;

    // Si se llama a la funcion ''parse'' de la siguiente manera
    parse(entrada, expr);

    // Es equivalente a construir una expressoin de la siguiente manera
    Expression* expr2 = new Suma(new Valor(1), new Multiplicacion(new Valor(2), new Valor(3)));

    // Por lo tanto la siguiente linea impirme:
    // "La diferencia es 0.0"
    printf("La diferencia es %d", expr2->evaluar() - expr->evaluar());
    

    return 0;
    }