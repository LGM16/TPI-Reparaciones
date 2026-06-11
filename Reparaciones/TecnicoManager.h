#pragma once
#include "Tecnico.h"
#include <string>

class TecnicoManager{
public:

    bool validarCredenciales(std::string usuario, std::string contrasenia, Tecnico& tecnico);
};
