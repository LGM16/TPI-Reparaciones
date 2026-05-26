#include <iostream>
using namespace std;
#include "Equipo.h"

//Constructores

Equipo::Equipo(){
    setIdEquipo(1);
    setIdTecnico(Tecnico());
    setIdCliente(Cliente());
    setDescripcion("");
    setMarca("");
    setTipoEquipo("");
    setFechaIngreso(Fecha());
    setEstado(true);
}

//Setters

void Equipo::setIdEquipo(int idEquipo){
    if(idEquipo > 0){
        _idEquipo = idEquipo;
    }
    else{
        _idEquipo = 1;
    }
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

//Metodos