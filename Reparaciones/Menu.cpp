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
        cout << "Menu Principal" << endl;
        

    }while(opcion != 0);
}