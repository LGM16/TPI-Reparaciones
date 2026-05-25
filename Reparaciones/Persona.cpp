//Definicion de constructores, setters, getters y metodos de la clase Persona

#include <iostream>
using namespace std;
#include "Persona.h"

//Constructores

Persona::Persona(){
    setCuit("");
    setNombre("");
    setApellido("");
}

//Setters

void Persona::setCuit(string cuit){
    _cuit = cuit;
}

void Persona::setNombre(string nombre){
    _nombre = nombre;
}

void Persona::setApellido(string apellido){
    _apellido = apellido;
}

//Metodos

void Persona::cargar(){
    cout << "Apellido: " << endl;
    cin >> _apellido;
    cout << "Nombre: " << endl;
    cin >> _nombre;
    cout << "CUIT: " << endl;
    cin >> _cuit;
}

void Persona::mostrar(){
    cout << getApellido() << ", " << getNombre() << " - CUIT: " << getCuit() << endl;
}