#pragma once
#include "Equipo.h"
#include <string>

class EquipoArchivo{
private:

    std::string _ruta;

public:

    //Constructores

    EquipoArchivo();
    EquipoArchivo(std::string ruta);

    //Setters

    int getCantidadRegistros();

    //Getters

    //Metodos

    bool existeArchivo();
    bool guardar(Equipo reg);
    bool guardar(Equipo reg, int posicionReemplazada);
    bool guardar(Equipo *vec, int cantidadRegistros);

    Equipo leer(int posRegistro);
    
    void leerTodos(Equipo *vec, int cantidadRegistros);
    
    int buscar(int id);
};
