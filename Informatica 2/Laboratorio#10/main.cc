#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

template<typename T>
class Iterador{
    public:
    virtual bool valor(T& resultado) = 0;
    virtual void siguiente() = 0;
};

template<typename K, typename V, typename T>
class Diccionario : public Iterador<T>{
    public:
    K* nombre;
    V* guardar;

    Diccionario (K n, V g) : nombre(n), guardar (g){}
    virtual bool valor(T& resultado) override{
        
    }
    virtual void siguiente() override{

    }
    T& operator[] (const K& k){
        T* e = new T();
        return *e;
       
        
    }
};

int main (){
    /*Diccionario<std::string , std::string > strs;
    strs["Universidad"] = "Universidad del Istmo";
    strs["Facultad"] = "Ingenieria";
    strs["Clase"] = "Informatica II";
    Iterator < std::string >* it = strs.iterador();
    std::string valor;
    while(it->valor(valor))
    {
    printf("Se almaceno ’’%s’’\n", valor.c_str());
    it->siguiente();
    }
    printf("La facultad es ’’%s’’\n", strs["Facultad"].c_str());
    delete it;
    */
}