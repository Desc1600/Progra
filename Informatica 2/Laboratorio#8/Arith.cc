#include "Arith.hh"
#include <string> 


bool parseInt(const std::string& valor, int& resultado){
    
    int tam = valor.size();
    int i = 0;
    for(int i = 0; i < tam; i++)
    {
        if(valor[i] < '0' || valor[i] > '9' ){
            
            if (i == ( tam - 1 )){
                resultado = std::stoi( valor ); 
            return true;
            }
        }else{
            return false;
        }
        
    }
    return false;
}


bool Arith::parse(const std::string valor, int& resultado)const{

    int respuesta = 0;
    int tam = valor.size(); 
    std::string parte1 , parte2;

    if (parseInt(valor, resultado)){
        for(int i = 0; i < tam; i++){
            
            if(valor[i] == '+' || valor[i] > '*' ){
                parte1= valor[i-1];
                parte1 = arg1;
                parte2 = valor[i+1];
                parte2 = arg2;
                if(valor[i] == '+'){
                    respuesta = Arith::opSuma(arg1,arg2);
                    
                }else if(valor[i] == '+'){

                    respuesta = Arith::opProducto(arg1,arg2);
                }
            }else 
            {            
            return false; 
        }
        }
            return true; 

    }
    return true; 

} 
   
   int Arith::opSuma(const int arg1, const int arg2)const{

    int suma = arg1 + arg2; 

    return suma; 

}

int Arith::opProducto(const int arg1, const int arg2)const{

    int multiplicacion = arg1 * arg2; 

    return multiplicacion; 

}
//int main(){ } 
