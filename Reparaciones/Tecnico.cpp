#include <iostream>
using namespace std;
#include "Tecnico.h"

///Constructores

Tecnico::Tecnico(){
    setIdTecnico(1);
    setUsuario("");
    setContrasenia("");
}

///Setters

void Tecnico::setIdTecnico(int idTecnico){
    if(idTecnico > 0){
        _idTecnico = idTecnico;
    }
    else{
        _idTecnico = 1;
    }
}

void Tecnico::setUsuario(string usuario){
    if(usuario.length() >= 3 && usuario.length() <= 20){
        _usuario = usuario;
    }
    else{
        _usuario = "";
    }
}

void Tecnico::setContrasenia(string contrasenia){
    if(contrasenia.length() >= 1){
        _contrasenia = contrasenia;
    }
    else{
        _contrasenia = "";
    }
}