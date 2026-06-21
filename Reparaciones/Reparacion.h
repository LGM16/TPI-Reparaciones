#pragma once
#include "Equipo.h"
#include "Cliente.h"
#include "Fecha.h"

class Reparacion{
private:

    int _idReparacion;
    int _idEquipo;
    Fecha _fechaIngreso;
    Fecha _fechaEgreso;
    float _importe;
    int _estadoRep; // 1: en proceso; 2: reparado; 3: no reparado
    bool _estado = false;

public:

    ///Constructores

    Reparacion();
    Reparacion(int idReparacion, int idEquipo, Fecha fechaIngreso,
              Fecha fechaEgreso, float importe, int estadoRep, bool estado);

    ///Setters

    void setIdReparacion(int idReparacion);
    void setIdEquipo(int idEquipo);
    void setFechaIngreso(Fecha fechaIngreso);
    void setFechaEgreso(Fecha fechaEgreso);
    void setImporte(float importe);
    void setEstadoRep(int estadoRep);
    void setEstado(bool estado);

    ///Getters

    int getIdReparacion(){return _idReparacion;};
    int getIdEquipo(){return _idEquipo;};
    Fecha getFechaIngreso(){return _fechaIngreso;};
    Fecha getFechaEgreso(){return _fechaEgreso;};
    float getImporte(){return _importe;};
    int getEstadoRep(){return _estadoRep;};
    bool getEstado(){return _estado;};

    ///Metodos
};
