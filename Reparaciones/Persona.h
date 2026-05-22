//De aca va a heredar Clientes
#pragma once
#include <string>
class Persona{
protected:
    
    std::string _nombre;
    std::string _apellido;
    std::string _cuit;

public:

    //Constructores

    Persona();
    Persona(std::string nombre, std::string apellido, std::string cuit);
    
    //Setters y Getters

    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setCuit(std::string cuit);
    std::string getNombre(){return _nombre;};
    std::string getApellido(){return _apellido;};
    std::string getCuit(){return _cuit;};

    //Metodos

    void cargar();
    void mostrar();
};
