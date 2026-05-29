#include <iostream>
using namespace std;
#include "Menu.h"

///Constructor

Menu::Menu(){
    _sesionActiva = false;
}

///Setters

///Metodos

Menu::ejecutar(){
    while(_sesionActiva){
        mostrarMenuPrincipal();
    }
}

Menu::menuPrincipal(){
    int opcion;
    do{
        switch (opcion){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
        }


    }while(opcion != 0);
}