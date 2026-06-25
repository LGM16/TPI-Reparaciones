#pragma once
#include "Tecnico.h"
#include <string>

class TecnicoArchivo{
private:

    std::string _ruta;

public:

    ///Constructores

    TecnicoArchivo();
    TecnicoArchivo(std::string ruta);

    ///Getters

    int getCantidadRegistros();

    ///Metodos

    bool guardar(Tecnico reg);
    bool guardar(Tecnico reg, int posicionReemplazada);
    bool guardar(Tecnico *vec, int cantidadRegistros);
    Tecnico leer(int posRegistro);
    void leerTodos(Tecnico *vec, int cantidadRegistros);
    int buscar(int id);
    void vaciar();
};
