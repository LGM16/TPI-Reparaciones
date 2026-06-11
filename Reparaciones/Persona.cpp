//Definicion de constructores, setters, getters y metodos de la clase Persona

#include <iostream>
#include "Persona.h"

///Constructores

Persona::Persona(){
}

Persona::Persona(std::string cuit, std::string nombre, std::string apellido){
    setCuit(cuit);
    setNombre(nombre);
    setApellido(apellido);
}

///Setters

void Persona::setCuit(std::string cuit){ 
    if(cuit.length() == 11){ //esto puede ir como validacion en el archivo?
        _cuit = cuit;
    }
}

void Persona::setNombre(std::string nombre){
    if(nombre.length() >= 3 && nombre.length() <= 50){ //esto puede ir como validacion en el archivo?
        _nombre = nombre;
    }
}

void Persona::setApellido(std::string apellido){
    if(apellido.length() >= 3 && apellido.length() <= 50){ //esto puede ir como validacion en el archivo?
        _apellido = apellido;
    }
}

///Metodos
/*
void Persona::cargar(){
    std::string cuit, nombre, apellido;
    std::cout << "Apellido: ";
    cin >> apellido;
    setApellido(apellido);
    cout << "Nombre: ";
    cin >> nombre;
    setNombre(nombre);
    cout << "CUIT: ";
    cin >> cuit;
    setCuit(cuit);
}

void Persona::mostrar(){
    cout << getApellido() << ", " << getNombre() << " - CUIT: " << getCuit() << endl;
}
*/
