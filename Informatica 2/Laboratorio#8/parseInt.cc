//Tarea #1 
#include <string.h> 
#include <iostream> 


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
int main(){
    std::string str1("12345");
    std::string str2("12345_mal");

    int resultado = 0;
    if(parseInt(str1, resultado)){
        // Imprime "Resultado 12345"
        printf("Resultado1 %i", resultado);
    }

    if(!parseInt(str2, resultado)){
        // Imprimie "No se pudo parsear str2"
        printf("No se pudo parsear str2");
    }
}