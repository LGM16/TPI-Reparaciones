#include <iostream>
using namespace std;
#include "Equipo.h"

///Constructores

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
        _idEquipo = idEquipo;
}

void Equipo::setIdTecnico(Tecnico idTecnico){
    _idTecnico = idTecnico;
}

void Equipo::setIdCliente(Cliente idCliente){
    _idCliente = idCliente;
}

void Equipo::setDescripcion(string descripcion){
    _descripcion = descripcion;
}

void Equipo::setMarca(string marca){
    _marca = marca;
}

void Equipo::setTipoEquipo(string tipoEquipo){
    _tipoEquipo = tipoEquipo;
}

void Equipo::setFechaIngreso(Fecha fechaIngreso){
    _fechaIngreso = fechaIngreso;
}

void Equipo::setEstado(bool estado){
    _estado = estado;
}

///Metodos