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

    bool crearTecnico(Tecnico& tecnicoCreado);
    void listarTecnicos();
    void listarXId();
    void listar(const Tecnico& tecnico);
    void darAltaTecnico();
    void darBajaTecnico();
    bool hayTecnicos();
    bool validarCredenciales(std::string usuario, std::string contrasenia, Tecnico& tecnico);
};
