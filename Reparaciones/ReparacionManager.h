#pragma once
#include "Reparacion.h"
#include "ReparacionArchivo.h"
#include "EquipoArchivo.h"

class ReparacionManager{
private:

    ReparacionArchivo _archivo;
    EquipoArchivo _archivoEquipo;

    bool existeId(int id);
    int generarId();

public:

    //Constructores

    ReparacionManager();

    //Metodos

    void crearReparacion();
    void listarReparaciones();
    void listarXId();
    void listar(const Reparacion& reparacion);
    void darBajaReparacion();
    void actualizarEstadoRep();
};
