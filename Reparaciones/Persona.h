//Clase Base para Cliente y Tecnico

#pragma once
#include <string>

class Persona{
protected:

    std::string _cuit;
    std::string _nombre;
    std::string _apellido;

public:

    ///Constructores

    Persona(std::string cuit, std::string nombre, std::string apellido);
    
    ///Setters

    void setCuit(std::string cuit);
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    
    ///Getters

    std::string getCuit(){return _cuit;}
    std::string getNombre(){return _nombre;}
    std::string getApellido(){return _apellido;}

    ///Metodos

    void cargar();
    void mostrar();
};
