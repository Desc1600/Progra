#include <iostream>
using namespace std; 
#include<math.h>

int main(){

char p;
char salida;
float g = 0.0;
float k = 0.0;
float t = 0;//tiempo contador
float t2;
int vo = 0; //velocidad original
system("clear");
printf("\nBIENVENIDO \n Escoja un caracter de la sigiente lista:\n Tierra = t\n Venus = v\n Luna = l\n Callisto = c\n");
cout<<"Ingrese el caracter deseado:\n";
std::cin >> p;
system("clear");

switch(p){
    case 't':
    g = 9.8;
    k = 0.0023;
    printf("Usted ha selccionado la Tierra\nLa gravedad es: %.2f, la resistencia del viento es: %.4f\n", g ,k);
    printf("Ingrese el tiempo de caida libre:\n");
    cin >> t2;//solicitud del tiempo
    while(t2 >= t ){
        float fatm = k * (pow(vo,2));
        float f = g - fatm;
        float a = f ;
        float v = v + (a * (0.01));
        float d = d + (v * (0.01));
        t += 0.01;
        vo = v;
        if(t2 <= t){
            printf("La distancia es %.2f\n La velocidad es %.2f \n",d ,v);
            }
        }
    break; 
    
    case 'v':
    g = 8.87;
    k = 0.0023;
    printf("Usted ha selccionado Venus\nLa gravedad es: %.2f, la resistencia del viento es: %.4f\n", g ,k);
    printf("Ingrese el tiempo de caida libre:\n");
    cin >> t2;
    while(t2 >= t ){
        float fatm = k * (pow(vo,2));
        float f = g - fatm;
        float a = f ;
        float v = v + (a * (0.01));
        float d = d + (v * (0.01));
        t += 0.01;
        vo = v;     
        if(t2 <= t){
            printf("La distancia es %.2f\n La velocidad es %.2f \n",d ,v);
            }
        }
    break;
    
    case 'l':
    g = 1.62;
    k = 0.0;
    printf("Usted ha selccionado la Luna\nLa gravedad es: %.2f , la resistencia del viento es: %.4f\n", g ,k);
    printf("Ingrese el tiempo de caida libre:\n");
    cin >> t2;
    while(t2 >= t ){
        float fatm = k * (pow(vo,2));
        float f = g - fatm;
        float a = f ;
        float v = v + (a * (0.01));
        float d = d + (v * (0.01));
        t += 0.01;
        vo = v;   
        if(t2 <= t){
            printf("La distancia es %.2f \nLa velocidad es %.2f \n",d ,v);
            }
        }
    break;
    
    case 'c':
    g = 1.23;
    k = 0.0;
    printf("Usted ha selccionado Callisto\nLa gravedad es: %.2f, la resistencia del viento es: %.4f\n", g ,k);
    printf("Ingrese el tiempo de caida libre:\n");
    cin >> t2;
    while(t2 >= t ){
        float fatm = k * (pow(vo,2));
        float f = g - fatm;
        float a = f ;
        float v = v + (a * (0.01));
        float d = d + (v * (0.01));
        t += 0.01;
        vo = v;
        if(t2 <= t){
            printf("La distancia es %.2f \nLa velocidad es %.2f \n",d ,v);
            }
        }
    break;

default: cout << "ENTRADA INVALIDA";main(); 
}
cout<<"\n Desea salir del programa (s/n)?:\n";cin >> salida;
switch(salida){
        case 's':
        system("clear");
        return 0;
        break;

        case 'n':
        system("clear");
        main();
        break;
        }
return 0; 
}
//Se aproximo la respuesta a dos decimales. 