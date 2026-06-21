#pragma once
#include "Tecnico.h"
#include "TecnicoArchivo.h"

class TecnicoManager{
private:

    TecnicoArchivo _archivo;

    bool existeId(int id);
    bool existeUsuario(std::string usuario);
    int generarId();

public:

    ///Constructores

    TecnicoManager();

    ///Metodos

    void crearTecnico();
    void listarTecnicos();
    void listarXId();
    void listar(Tecnico tecnico);
    void darBajaTecnico();
    bool hayTecnicos();
    bool validarCredenciales(std::string usuario, std::string contrasenia, Tecnico& tecnico);
};
