#pragma once
#include "Cliente.h"
#include "ClienteArchivo.h"

class ClienteManager{
private:

    ClienteArchivo _archivo;

    bool existeId(int id);
    int generarId();

public:

    //Constructores

    ClienteManager();

    //Metodos

    void cargarCliente();
    void listarClientes();
    void listarXId();
    void listar(const Cliente& cliente);
    void darBajaCliente();
};
