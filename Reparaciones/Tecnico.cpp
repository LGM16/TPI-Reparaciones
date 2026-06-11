#include "Tecnico.h"

///Constructores

Tecnico::Tecnico()
    : Persona("", "", ""),
      _idTecnico(0),
      _usuario(""),
      _contrasenia("")
{
}

Tecnico::Tecnico(Persona persona, int idTecnico, std::string usuario, std::string contrasenia)
    : Persona(persona.getCuit(), persona.getNombre(), persona.getApellido()),
      _idTecnico(idTecnico),
      _usuario(usuario),
      _contrasenia(contrasenia)
{
}

///Setters

void Tecnico::setIdTecnico(int idTecnico){
    if(idTecnico > 0){
        _idTecnico = idTecnico;
    }
}

void Tecnico::setUsuario(std::string usuario){
    if(usuario.length() >= 3 && usuario.length() <= 20){
        _usuario = usuario;
    }
}

void Tecnico::setContrasenia(std::string contrasenia){
    if(contrasenia.length() >= 1){
        _contrasenia = contrasenia;
    }
}