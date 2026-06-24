#pragma once
#include "rlutil.h"
#include <limits>
#include "Tecnico.h"
#include "ClienteManager.h"
#include "TecnicoManager.h"
#include "EquipoManager.h"
#include "ReparacionManager.h"
#include "InformeManager.h"

class Menu{
private:

    Tecnico _tecnico;
    ClienteManager _managerCliente;
    TecnicoManager _managerTecnico;
    EquipoManager _managerEquipo;
    ReparacionManager _managerReparacion;
    InformeManager _managerInforme;
    bool _tecnicoLogueado = false;

public:

    //Constructores

    Menu();

    //Setters

    void setSesionActiva(bool tecnicoLogueado);

    //Getters

    bool getSesionActiva(){return _tecnicoLogueado;}

    //Metodos

    void ejecutar();
    void menuLogin();           // Menu de login para el tecnico
    void menuPrincipal();       // Menu que se muestra una vez logueado
    void menuClientes();        // Menu para gestionar clientes
    void menuEquipos();         // Menu para gestionar equipos
    void menuReparaciones();    // Menu para gestionar reparaciones
    void menuInformes();        // Menu para generar informes
    void menuTecnicos();        // Menu para gestionar tecnicos

};


/*
herencia
clase 6: https://www.youtube.com/watch?v=9iN5MoktbBk 1:40:00 aprox

archivos
clase 7: https://www.youtube.com/watch?v=uSG8Iny0mVk 20:00

menu y polimorfismo
clase 8: https://www.youtube.com/watch?v=t-A9Mpgc9h0 20:00 aprox
*/
