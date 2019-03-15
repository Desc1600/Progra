#include "vertices.hh" 


bool Vertice::obtenerVertice(Vertice& , const int _numVertices){
    if(this->vertices() <= _numVertices){
        int agregar =  _numVertices + this->vertices(); 
            
        return true; 

    }else{
        return false; 
    }

}

bool Vertice::agregarVertice(Vertice& , const int _numVertices){
    if( 0 <_numVertices < this->vertices()){
                   
        return true;  

    }else{
        int disminuir =  _numVertices - this->vertices(); 
        return false; 
    }

}

bool Vertice::eliminarVertice(const int _numVertices){
    if(0 < _numVertices < (this->vertices())){
        
        delete _vertices;
        return true; 

    }else{
        
        return false; 
    }

}



