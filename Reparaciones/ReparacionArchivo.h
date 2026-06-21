#pragma once
#include "Reparacion.h"
#include <string>

class ReparacionArchivo{
private:

    std::string _ruta;

public:

    //Constructores

    ReparacionArchivo();
    ReparacionArchivo(std::string ruta);

    //Getters

    int getCantidadRegistros();

    //Metodos

    bool guardar(Reparacion reg);
    bool guardar(Reparacion reg, int posicionReemplazada);
    bool guardar(Reparacion *vec, int cantidadRegistros);
    Reparacion leer(int posRegistro);
    void leerTodos(Reparacion *vec, int cantidadRegistros);
    int buscar(int id);
};
