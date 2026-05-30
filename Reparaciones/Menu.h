#pragma once
#include "ManagerArchivo.h"
#include "Tecnico.h"

class Menu{
private:

    Tecnico _tecnico;
    ManagerArchivo _manager;
    bool _tecnicoLogueado = true;

public:

    //Constructores

    Menu();

    //Setters

    bool setSesionActiva(bool sesionActiva);

    //Getters

    bool getSesionActiva(){return _tecnicoLogueado;}

    //Metodos

    void ejecutar();
    void menuLogin();
    void menuPrincipal();
    void menuClientes();
    void menuEquipos();
    void menuReparaciones();
    void menuInformes();

};
