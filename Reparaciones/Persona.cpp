//Definicion de constructores, setters, getters y metodos de la clase Persona

#include <iostream>
using namespace std;
#include "Persona.h"

///Constructores
Persona::Persona():_cuit("Sin Asignar"), _nombre("Lucas"), _apellido("Migliore") {
}

Persona::Persona(string cuit, string nombre, string apellido){
    setCuit(cuit);
    setNombre(nombre);
    setApellido(apellido);
}

///Setters

void Persona::setCuit(string cuit){
    if(cuit.length() == 11){
        _cuit = cuit;
    }
    else{
        _cuit = "00000000000";
    }
}

void Persona::setNombre(string nombre){
    if(nombre.length() >= 3 && nombre.length() <= 50){
        _nombre = nombre;
    }
    else{
        _nombre = "Pepe";
    }
}

void Persona::setApellido(string apellido){
    if(apellido.length() >= 3 && apellido.length() <= 50){
        _apellido = apellido;
    }
    else{
        _apellido = "Lopez";
    }
}

///Metodos

void Persona::cargar(){
    string cuit, nombre, apellido;
    cout << "Apellido: ";
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