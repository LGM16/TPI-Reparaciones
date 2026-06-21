#include <iostream>
#include "Reparacion.h"

///Constructor

Reparacion::Reparacion(){
    _idReparacion = 0;
    _estadoRep = 1; //En proceso por defecto
    _estado = false; //Inactivo por defecto
}

Reparacion::Reparacion(int idReparacion, int idEquipo, Fecha fechaIngreso,
                         Fecha fechaEgreso, float importe, int estadoRep, bool estado)
    : _idReparacion(idReparacion), _idEquipo(idEquipo), _fechaIngreso(fechaIngreso),
      _fechaEgreso(fechaEgreso), _importe(importe), _estadoRep(estadoRep), _estado(estado)
{
    setIdReparacion(idReparacion);
    setIdEquipo(idEquipo);
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

void Reparacion::setIdEquipo(int idEquipo){
    if(idEquipo > 0){
        _idEquipo = idEquipo;
    }
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
