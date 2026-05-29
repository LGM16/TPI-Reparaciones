#pragma once
#include "ManagerArchivo.h"
#include "Tecnico.h"

class Menu{
private:

    Tecnico _tecnicoLogueado;
    ManagerArchivo _manager;
    bool _sesionActiva = true;

public:

    //Constructores

    Menu();

    //Setters

    bool setSesionActiva(bool sesionActiva);

    //Getters

    bool getSesionActiva();

    //Metodos

    void ejecutar();
    void menuLogin();
    void menuPrincipal();
    void menuClientes();
    void menuEquipos();
    void menuReparaciones();
    void menuInformes();

};
