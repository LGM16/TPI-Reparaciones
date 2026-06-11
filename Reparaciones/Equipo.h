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
    //sumar int numSerie
    Tecnico _idTecnico;
    Cliente _idCliente;
    std::string _descripcion;
    std::string _marca;
    std::string _tipoEquipo;
    Fecha _fechaIngreso;
    bool _estado = true;
    
public:

    ///Constructores

    Equipo(int idEquipo, Tecnico idTecnico, Cliente idCliente, std::string descripcion,
           std::string marca, std::string tipoEquipo, Fecha fechaIngreso, bool estado);

    ///Setters

    void setIdEquipo(int idEquipo);
    void setIdTecnico(Tecnico idTecnico);
    void setIdCliente(Cliente idCliente);
    void setDescripcion(std::string descripcion);
    void setMarca(std::string marca);
    void setTipoEquipo(std::string tipoEquipo);
    void setFechaIngreso(Fecha fechaIngreso);
    void setEstado(bool estado);

    ///Getters

    int getIdEquipo();
    Tecnico getIdTecnico();
    Cliente getIdCliente();
    std::string getDescripcion();
    std::string getMarca();
    std::string getTipoEquipo();
    Fecha getFechaIngreso();
    bool getEstado();

    ///Metodos
};
