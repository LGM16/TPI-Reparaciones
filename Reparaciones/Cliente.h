/*
Por cada uno de los clientes registra el CUIT, el nombre, el apellido, un número de
teléfono, un email, la dirección y el tipo de cliente (1: particular; 2: empresa).
*/

#pragma once
#include "Persona.h"

class Cliente: public Persona{
private:

    int _idCliente;         //asignado por ClienteManager 
    int _tipoCliente;       //1: particular; 2: empresa
    char _telefono[16];
    char _email[51];
    char _direccion[101];
    bool _estado = true;

public:

    ///Constructores

    Cliente();

    Cliente(Persona persona, int idCliente, int tipoCliente, std::string telefono,
            std::string email, std::string direccion, bool estado);
            
    ///Setters

    void setIdCliente(int idCliente);
    void setTipoCliente(int tipoCliente);
    void setTelefono(std::string telefono);
    void setEmail(std::string email);
    void setDireccion(std::string direccion);
    void setEstado(bool estado);

    ///Getters

    int getIdCliente(){return _idCliente;}
    int getTipoCliente(){return _tipoCliente;}
    
    std::string getTelefono(){return _telefono;}
    std::string getEmail(){return _email;}
    std::string getDireccion(){return _direccion;}
    
    bool getEstado(){return _estado;}

    ///Metodos
};
