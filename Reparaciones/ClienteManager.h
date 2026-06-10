#pragma once
#include "Cliente.h"
#include "ClienteArchivo.h"

class ManagerCliente{
private:

    ClienteArchivo _archivo;
    //ArchivoTecnico _archivoClienteBackUp;  un backup?

    bool existeId(int id);
    int generarId();

public:

    //Constructores

    ManagerCliente();

    //Setters

    //Getters

    //Metodos

    void cargarCliente();
    void listarClientes();
    void listarXId();
    void listar(Cliente Cliente);
    //void darBajaCliente();?
};
