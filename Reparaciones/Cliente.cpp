#include <iostream>
#include <cstring>
#include "Cliente.h"

///Constructores

Cliente::Cliente()
    : Persona(),
      _idCliente(0),
      _tipoCliente(0),
      _estado(true)
{
    _telefono[0] = '\0';
    _email[0] = '\0';
    _direccion[0] = '\0';
}

Cliente::Cliente(Persona persona, int idCliente, int tipoCliente, std::string telefono,
                 std::string email, std::string direccion, bool estado)
    : Persona(persona.getCuit(), persona.getNombre(), persona.getApellido()),
      _idCliente(idCliente),
      _estado(estado)
{
    setTipoCliente(tipoCliente);
    setTelefono(telefono);
    setEmail(email);
    setDireccion(direccion);
}

///Setters

void Cliente::setIdCliente(int idCliente){
        _idCliente = idCliente;
}

void Cliente::setTipoCliente(int tipoCliente){

    if(tipoCliente == 1 || tipoCliente == 2){
        _tipoCliente = tipoCliente;
    }

    /*
    if(validarTipoCliente(tipoCliente)){
        _tipoCliente = tipoCliente;
    }
    else{
        _tipoCliente = 1;
    }
    */

}

void Cliente::setTelefono(std::string telefono){
    if(telefono.length() >= 8 && telefono.length() <= 15){ //idem .size()
        strcpy(_telefono, telefono.c_str());
    }
}

void Cliente::setEmail(std::string email){
    if(email.find('@') != std::string::npos && email.length() <= 50){
        strcpy(_email, email.c_str());
    }
}

void Cliente::setDireccion(std::string direccion){
    if(direccion.length() <= 100){
        strcpy(_direccion, direccion.c_str());
    }
}

void Cliente::setEstado(bool estado){
    _estado = estado;
}

///Metodos

void Cliente::mostrar(){
    std::cout << "ID del Cliente: " << getIdCliente() << "\n";
    std::cout << "CUIT: " << getCuit() << "\n";

    if(getTipoCliente() == 1){
        std::cout << "Tipo de Cliente: Particular" << "\n";
        std::cout << "Nombre: " << getNombre() << "\n";
        std::cout << "Apellido: " << getApellido() << "\n";
    }
    else{
        if(getTipoCliente() == 2){
            std::cout << "Tipo de Cliente: Empresa" << "\n";
            std::cout << "Razon Social: " << getNombre() << "\n";
        }
    }

    std::cout << "Telefono de Cliente: " << getTelefono() << "\n";
    std::cout << "Email de Cliente: " << getEmail() << "\n";
    std::cout << "Direccion de Cliente: " << getDireccion() << "\n";
}

bool Cliente::validarTipoCliente(int tipoCliente){
    if(tipoCliente == 1 || tipoCliente == 2){
        return true;
    }
    return false;
}
