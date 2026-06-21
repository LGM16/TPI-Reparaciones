/*
Para cada equipo se registra el número de equipo, la descripción del equipo, la marca,
el tipo de equipo, y la fecha en la que ingresó para su reparación. El número de equipo
es un código numérico que identifica de forma única a cada equipo. El tipo de equipo
se usa para saber si se trata de una PC de escritorio, una notebook, una impresora, un
periférico, etc.
*/

#pragma once
#include "Tecnico.h"
#include "Cliente.h"
#include "Fecha.h"

class Equipo{
private:

    int _idEquipo;
    int _idTecnico;
    int _idCliente;
    char _descripcion[101];
    char _marca[51];
    char _tipoEquipo[51];
    Fecha _fechaIngreso;
    bool _estado = true;
    
public:

    ///Constructores

    Equipo();
    Equipo(int idEquipo, int idTecnico, int idCliente, std::string descripcion,
           std::string marca, std::string tipoEquipo, Fecha fechaIngreso, bool estado);

    ///Setters

    void setIdEquipo(int idEquipo);
    void setIdTecnico(int idTecnico);
    void setIdCliente(int idCliente);
    void setDescripcion(std::string descripcion);
    void setMarca(std::string marca);
    void setTipoEquipo(std::string tipoEquipo);
    void setFechaIngreso(Fecha fechaIngreso);
    void setEstado(bool estado);

    ///Getters

    int getIdEquipo(){return _idEquipo;}
    int getIdTecnico(){return _idTecnico;}
    int getIdCliente(){return _idCliente;}
    std::string getDescripcion(){return std::string(_descripcion);}
    std::string getMarca(){return std::string(_marca);}
    std::string getTipoEquipo(){return std::string(_tipoEquipo);}
    Fecha getFechaIngreso(){return _fechaIngreso;}
    bool getEstado(){return _estado;}

    ///Metodos
};
