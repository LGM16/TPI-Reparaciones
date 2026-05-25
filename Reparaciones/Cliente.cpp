#include <iostream>
using namespace std;
#include "Cliente.h"

//Constructores

Cliente::Cliente(){
    setIdCliente(1);
    setTipoCliente(1);
    setTelefono("");
    setEmail("");
    setDireccion("");
    setEstado(true);
}

//Setters

void Cliente::setIdCliente(int idCliente){
    if(idCliente > 0){
        _idCliente = idCliente;
    }
    else{
        _idCliente = 1;
    }
}

void Cliente::setTipoCliente(int tipoCliente){
    if(validarTipoCliente(tipoCliente)){
        _tipoCliente = tipoCliente;
    }
    else{
        _tipoCliente = 1;
    }
    /*
    if(tipoCliente == 1 || tipoCliente == 2){
        _tipoCliente = tipoCliente;
    }
    else{
        _tipoCliente = 1;
    }
    */
}

void Cliente::setTelefono(std::string telefono){
    _telefono = telefono;
}

void Cliente::setEmail(std::string email){
    _email = email;
}

void Cliente::setDireccion(std::string direccion){
    _direccion = direccion;
}

void Cliente::setEstado(bool estado){
    _estado = estado;
}

//Metodos

void Cliente::cargar(){

    int idCliente, tipoCliente;

    Persona::cargar();
    cout << "Ingrese el ID del Cliente: " << endl;
    cin >> idCliente;
    setIdCliente(idCliente);
    cout << "Ingrese el tipo de Cliente (1: Particular, 2: Empresa): " << endl;
    cin >> tipoCliente;
    setTipoCliente(tipoCliente);
}

void Cliente::mostrar(){
    Persona::mostrar();

}

bool Cliente::validarTipoCliente(int tipoCliente){
    if(tipoCliente == 1 || tipoCliente == 2){
        return true;
    }
    return false;
}