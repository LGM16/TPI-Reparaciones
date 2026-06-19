#include <cstring>
#include "Tecnico.h"

///Constructores

Tecnico::Tecnico()
    : Persona(),
      _idTecnico(0),
      _estado(true)
{
    _usuario[0] = '\0';
    _contrasenia[0] = '\0';
}

Tecnico::Tecnico(Persona persona, int idTecnico, std::string usuario, std::string contrasenia)
    : Persona(persona.getCuit(), persona.getNombre(), persona.getApellido())
{
    setIdTecnico(idTecnico);
    setUsuario(usuario);
    setContrasenia(contrasenia);
}

///Setters

void Tecnico::setIdTecnico(int idTecnico){
    if(idTecnico > 0){
        _idTecnico = idTecnico;
    }
}

void Tecnico::setUsuario(std::string usuario){
    if(usuario.length() >= 3 && usuario.length() <= 20){
        strcpy(_usuario, usuario.c_str());
    }
}

void Tecnico::setContrasenia(std::string contrasenia){
    if(contrasenia.length() >= 1 && contrasenia.length() <= 50){
        strcpy(_contrasenia, contrasenia.c_str());
    }
}
