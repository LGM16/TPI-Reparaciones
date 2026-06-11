#pragma once
#include "Cliente.h"
#include <string>

class ClienteArchivo{
private:

    std::string _ruta;

public:

    //Constructores

    ClienteArchivo();
    ClienteArchivo(std::string ruta);

    //Getters

    int getCantidadRegistros();

    //Metodos

    bool existeArchivo();
    bool guardar(Cliente reg);
    bool guardar(Cliente reg, int posicionReemplazada);
    bool guardar(Cliente *vec, int cantidadRegistros);

    Cliente leer(int posRegistro);
    
    void leerTodos(Cliente *vec, int cantidadRegistros);
    
    int buscar(int id);
};
