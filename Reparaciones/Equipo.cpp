#include <iostream>
#include <cstring>
#include "Reparacion.h"

///Constructores

Equipo::Equipo()
    : _idEquipo(0), _idTecnico(), _idCliente(), _fechaIngreso(), _estado(true)
{
    _descripcion[0] = '\0';
    _marca[0] = '\0';
    _tipoEquipo[0] = '\0';
}

Equipo::Equipo(int idEquipo, Tecnico idTecnico, Cliente idCliente, std::string descripcion, 
    std::string marca, std::string tipoEquipo, Fecha fechaIngreso, bool estado){
        setIdEquipo(idEquipo);
        setIdTecnico(idTecnico);
        setIdCliente(idCliente);
        setDescripcion(descripcion);
        setMarca(marca);
        setTipoEquipo(tipoEquipo);
        setFechaIngreso(fechaIngreso);
        setEstado(estado);
    }

///Setters

void Equipo::setIdEquipo(int idEquipo){
        if(idEquipo > 0){
            _idEquipo = idEquipo;
        }
}

void Equipo::setIdTecnico(Tecnico idTecnico){
    if(idTecnico.getIdTecnico() > 0){
        _idTecnico = idTecnico;
    }
}

void Equipo::setIdCliente(Cliente idCliente){
    if(idCliente.getIdCliente() > 0){
        _idCliente = idCliente;
    }
}

void Equipo::setDescripcion(std::string descripcion){
    if(descripcion.length() <= 100){
        strcpy(_descripcion, descripcion.c_str());
    }
}

void Equipo::setMarca(std::string marca){
    if(marca.length() <= 50){
        strcpy(_marca, marca.c_str());
    }
}

void Equipo::setTipoEquipo(std::string tipoEquipo){
    if(tipoEquipo.length() <= 50){
        strcpy(_tipoEquipo, tipoEquipo.c_str());
    }
}

void Equipo::setFechaIngreso(Fecha fechaIngreso){
    _fechaIngreso = fechaIngreso;
}

void Equipo::setEstado(bool estado){
    _estado = estado;
}

///Metodos