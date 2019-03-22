#include "Figura.hh"
#include "Circulo.hh"
#include "rectangulo.hh"
#include<iostream>
using namespace std; 

//void const  abarcar(Figura& figura, Vector2d[] puntos, int cantidad){}

int main(){

    
    printf("Escoja un caracter: v , c ó r \n"); 
    char eleccion; 
    cin>>eleccion; 


    switch (eleccion)
    {
        case 'v' :
        printf("Ingrese el vector deseado x , y: "); 
        int x , y; 
        Vector2d(x ,y);
        cin >> x; 
        cin >> y; 
        break;

        case 'c' :
        printf("Ingrese el centro del circulo deseado x , y: \n");
        int x , y;  
        Vector2d(x ,y);
        printf("Ingrese su radio r : \n"); 
        int r;   
        cin>>r;
        Circulo(Vector2d(x ,y),r); 
        break;

        case 'r':
        printf("Ingrese dos numeros para la esquina del rectangulo x , y: \n");
        int x , y;  
        Vector2d(x ,y);
        //esquinaInf(esquinaInf), _largo(_largo), _ancho(_ancho) {}
        printf("Ingrese el ancho del rectangulo: \n"); 
        int _ancho;   
        cin>>_ancho;
        printf("Ingrese el largo del rectangulo: \n"); 
        int _largo;   
        cin>>_largo;
        //Rectangulo(Vector2d (x,y));
        break;
    
        default:
            break;
    }

return 0; 
}