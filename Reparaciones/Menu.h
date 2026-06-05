#pragma once
//#include "ManagerArchivo.h" //aca tengo que definir si hago un manager gral o no
//#include "ManagerTecnico.h"
#include "Tecnico.h"

class Menu{
private:

    Tecnico _tecnico;
//    ManagerArchivo _manager;
    bool _tecnicoLogueado = false;

public:

    //Constructores

    Menu();

    //Setters

    void setSesionActiva(bool tecnicoLogueado9);

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