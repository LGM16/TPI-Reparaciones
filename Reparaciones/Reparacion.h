#pragma once
#include "Equipo.h"
#include "Cliente.h"
#include "Fecha.h"

class Reparacion{
private:

    Equipo _equipo;
    Cliente _idCliente;
    Fecha _fechaIngreso;
    Fecha _fechaEgreso;
    float _importe;
    int _estadoRep; // quiza: 1: en proceso; 2: reparado; 3: no reparado
    bool _estado = true;

public:

    //Constructores

    Reparacion();

    //Setters

    void setEquipo(Equipo equipo);
    void setIdCliente(Cliente idCliente);
    void setFechaIngreso(Fecha fechaIngreso);
    void setFechaEgreso(Fecha fechaEgreso);
    void setImporte(float importe);
    void setEstadoRep(int estadoRep);
    void setEstado(bool estado);
    //Getters

    Equipo getEquipo();
    Cliente getIdCliente();
    Fecha getFechaIngreso();
    Fecha getFechaEgreso();
    float getImporte();
    int getEstadoRep();
    bool getEstado();

    //Metodos
};
