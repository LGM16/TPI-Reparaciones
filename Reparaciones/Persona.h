//Clase Base para Cliente y Tecnico

#pragma once
#include <string>

class Persona{
protected:

    char _cuit[12];
    char _nombre[51];
    char _apellido[51];

public:

    ///Constructores

    Persona();
    Persona(std::string cuit, std::string nombre, std::string apellido);

    ///Setters

    void setCuit(std::string cuit);
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);

    ///Getters

    std::string getCuit(){return _cuit;}
    std::string getNombre(){return _nombre;}
    std::string getApellido(){return _apellido;}

};
