/*
Para cada equipo se registra el número de equipo, la descripción del equipo, la marca,
el tipo de equipo, y la fecha en la que ingresó para su reparación. El número de equipo
es un código numérico que identifica de forma única a cada equipo. El tipo de equipo
se usa para saber si se trata de una PC de escritorio, una notebook, una impresora, un
periférico, etc.
*/

#pragma once
#include <string>

class Equipo{
private:

    int _numeroEquipo;
    std::string _descripcion;
    std::string _marca;
    std::string _tipoEquipo;
    
public:
};
