//Definicion de constructores, setters, getters y metodos de la clase Persona

#include <iostream>
#include <cstring>
#include "Persona.h"

///Constructores

Persona::Persona(){
    _cuit[0] = '\0';
    _nombre[0] = '\0';
    _apellido[0] = '\0';
}

Persona::Persona(std::string cuit, std::string nombre, std::string apellido){
    setCuit(cuit);
    setNombre(nombre);
    setApellido(apellido);
}

///Setters

void Persona::setCuit(std::string cuit){
    if(cuit.length() == 11){
        strcpy(_cuit, cuit.c_str());
    }
}

void Persona::setNombre(std::string nombre){
    if(nombre.length() >= 3 && nombre.length() <= 50){
        strcpy(_nombre, nombre.c_str());
    }
}

void Persona::setApellido(std::string apellido){
    if(apellido.length() >= 3 && apellido.length() <= 50){
        strcpy(_apellido, apellido.c_str());
    }
    else if(apellido.empty()){
        _apellido[0] = '\0';
    }
}
