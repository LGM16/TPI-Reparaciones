#include "TecnicoManager.h"

bool TecnicoManager::validarCredenciales(std::string usuario, std::string contrasenia, Tecnico& tecnico){
    //Validacion provisoria hasta implementar TecnicoArchivo
    if(usuario == "admin" && contrasenia == "1234"){
        Persona persona("20123456789", "Juan", "Perez");
        tecnico = Tecnico(persona, 1, usuario, contrasenia);
        return true;
    }
    return false;
}
