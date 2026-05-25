#pragma once
#include "Persona.h"

class Tecnico: public Persona{
private:

    int _idTecnico;
    std::string _usuario;
    std::string _contrasenia;

public:

    //Constructores

    Tecnico();

    //Setters

    void setIdTecnico(int idTecnico);
    void setUsuario(std::string usuario);
    void setContrasenia(std::string contrasenia);

    //Getters

    int getIdTecnico(){return _idTecnico;};
    std::string getUsuario(){return _usuario;};
    std::string getContrasenia(){return _contrasenia;};

    //Metodos

    void cargar();
    void mostrar();
};
