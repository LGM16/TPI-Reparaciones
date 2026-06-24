#pragma once
#include "Equipo.h"
#include "EquipoArchivo.h"
#include "ClienteArchivo.h"
#include "TecnicoArchivo.h"

class EquipoManager{
private:

    EquipoArchivo _archivo;
    ClienteArchivo _archivoCliente;
    TecnicoArchivo _archivoTecnico;

    bool existeId(int id);
    int generarId();

public:

    //Constructores

    EquipoManager();

    //Metodos

    void crearEquipo();
    void listarEquipos();
    void listarXId();
    void listar(const Equipo& equipo);
    void darBajaEquipo();
};
