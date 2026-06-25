#pragma once
#include "ReparacionArchivo.h"
#include "EquipoArchivo.h"
#include "ClienteArchivo.h"
#include "TecnicoArchivo.h"
#include "Fecha.h"

class InformeManager{
private:

    ReparacionArchivo _archivoReparacion;
    EquipoArchivo _archivoEquipo;
    ClienteArchivo _archivoCliente;
    TecnicoArchivo _archivoTecnico;

    int fechaAEntero(Fecha fecha);
    bool fechaEnRango(Fecha fecha, Fecha fechaDesde, Fecha fechaHasta);

public:

    ///Constructor

    InformeManager();

    ///Metodos

    void informeReparacionesEnProceso();
    void informeReparacionesPorCliente();
    void informeReparacionesPorRangoFechas();
    void informeTotalFacturado();
    void informeEquiposPorTipo();
    void informeReparacionesPorTecnico();
};
