#pragma once
#include "Cliente.h"
#include "ArchivoCliente.h"

class ManagerCliente{
private:

    ArchivoCliente _archivoCliente;
    //ArchivoTecnico _archivoClienteBackUp;  un backup?

    bool existeId(int id);

public:

    //Constructores

    ManagerCliente();

    //Setters

    //Getters

    //Metodos

    void CargarCliente();
    void listarClientes();
    void listar
};
