#pragma once
#include "contenedor.hh"




class Vertice : public Container{ 

    Vertice(int _vertices);
    ~Vertice(); 

    bool obtenerVertice(Vertice& , const int _numVertices);     
    bool agregarVertice(Vertice& , const int _numVertices);
    bool eliminarVertice(const int _numVertices); 
    
    virtual int vertices() const override;

    private: 
    int* _vertices;
    int _numVertices;
    
  



}; 




