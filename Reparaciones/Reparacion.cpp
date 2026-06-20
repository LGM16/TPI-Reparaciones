#include <iostream>
#include "Reparacion.h"

///Constructor

Reparacion::Reparacion(){
    _idReparacion = 0;
    _estadoRep = 1; //En proceso por defecto
    _estado = false; //Inactivo por defecto
}

Reparacion::Reparacion(int idReparacion, Equipo equipo, Cliente idCliente, Fecha fechaIngreso,
                         Fecha fechaEgreso, float importe, int estadoRep, bool estado)
    : _idReparacion(idReparacion), _equipo(equipo), _idCliente(idCliente), _fechaIngreso(fechaIngreso),
      _fechaEgreso(fechaEgreso), _importe(importe), _estadoRep(estadoRep), _estado(estado)
{
    setIdReparacion(idReparacion);
    setEquipo(equipo);
    setIdCliente(idCliente);
    setFechaIngreso(fechaIngreso);
    setFechaEgreso(fechaEgreso);
    setImporte(importe);
    setEstadoRep(estadoRep);
}

///Setters

void Reparacion::setIdReparacion(int idReparacion){
    if(idReparacion > 0){
        _idReparacion = idReparacion;
    }
}

void Reparacion::setEquipo(Equipo equipo){
    _equipo = equipo;
}

void Reparacion::setIdCliente(Cliente idCliente){
    _idCliente = idCliente;
}

void Reparacion::setFechaIngreso(Fecha fechaIngreso){
    _fechaIngreso = fechaIngreso;
}

void Reparacion::setFechaEgreso(Fecha fechaEgreso){
    _fechaEgreso = fechaEgreso;
}

void Reparacion::setImporte(float importe){
    if(importe >= 0){
        _importe = importe;
    }
}

void Reparacion::setEstadoRep(int estadoRep){
    if(estadoRep >= 1 && estadoRep <= 3){
        _estadoRep = estadoRep;
    }
}

void Reparacion::setEstado(bool estado){
    _estado = estado;
}

///Metodos
