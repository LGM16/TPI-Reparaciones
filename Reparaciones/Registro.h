#pragma once
#include <string>

class Registro{
protected:

    std::string _nombreArchivo;
    FILE* _archivo;
    
public:

    ///Constructores

    Registro();
    Registro(std::string nombreArchivo, FILE* archivo);

    ///Setters

    void setNombreArchivo(std::string nombreArchivo);
    void setArchivo(FILE* archivo);
    
    ///Getters

    std::string getNombreArchivo();
    FILE* getArchivo();

    ///Metodos

    void leer();
    void escribir();
};
