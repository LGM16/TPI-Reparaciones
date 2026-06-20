#pragma once
#include "Persona.h"

class Tecnico: public Persona{
private:

    int _idTecnico;
    char _usuario[21];
    char _contrasenia[51];
    bool _estado = true;

public:

    ///Constructores

    Tecnico();
    Tecnico(Persona persona, int idTecnico, std::string usuario, std::string contrasenia);

    ///Setters

    void setIdTecnico(int idTecnico);
    void setUsuario(std::string usuario);
    void setContrasenia(std::string contrasenia);
    void setEstado(bool estado);

    ///Getters

    int getIdTecnico(){return _idTecnico;}
    std::string getUsuario(){return std::string(_usuario);}
    std::string getContrasenia(){return std::string(_contrasenia);}
    bool getEstado(){return _estado;}

    ///Metodos
};
