#pragma once
#include "Equipo.h"
#include "Cliente.h"
#include "Fecha.h"

class Reparacion{
private:

    int _idReparacion;
    Equipo _equipo;
    Cliente _idCliente;
    Fecha _fechaIngreso;
    Fecha _fechaEgreso;
    float _importe;
    int _estadoRep; // 1: en proceso; 2: reparado; 3: no reparado
    bool _estado = false;

public:

    ///Constructores

    Reparacion();
    Reparacion(int idReparacion, Equipo equipo, Cliente idCliente, Fecha fechaIngreso,
              Fecha fechaEgreso, float importe, int estadoRep, bool estado);

    ///Setters

    void setIdReparacion(int idReparacion);
    void setEquipo(Equipo equipo);
    void setIdCliente(Cliente idCliente);
    void setFechaIngreso(Fecha fechaIngreso);
    void setFechaEgreso(Fecha fechaEgreso);
    void setImporte(float importe);
    void setEstadoRep(int estadoRep);
    void setEstado(bool estado);

    ///Getters

    int getIdReparacion(){return _idReparacion;};
    Equipo getEquipo(){return _equipo;};
    Cliente getIdCliente(){return _idCliente;};
    Fecha getFechaIngreso(){return _fechaIngreso;};
    Fecha getFechaEgreso(){return _fechaEgreso;};
    float getImporte(){return _importe;};
    int getEstadoRep(){return _estadoRep;};
    bool getEstado(){return _estado;};

    ///Metodos
};
