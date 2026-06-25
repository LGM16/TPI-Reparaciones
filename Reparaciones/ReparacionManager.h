#pragma once
#include "Reparacion.h"
#include "ReparacionArchivo.h"
#include "EquipoArchivo.h"

class ReparacionManager{
private:

    ReparacionArchivo _archivo;
    EquipoArchivo _archivoEquipo;

    int generarId();
    bool existeId(int id);
    int fechaAEntero(Fecha fecha);

public:

    //Constructores

    ReparacionManager();

    //Metodos

    void crearReparacion();
    void listarReparaciones();
    void listarXId();
    void listar(const Reparacion& reparacion);
    void darAltaReparacion();
    void darBajaReparacion();
    void actualizarEstadoRep();
};
