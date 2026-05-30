#include <iostream>
using namespace std;
#include "Menu.h"

///Constructor

Menu::Menu(){
    _tecnicoLogueado = false;
}

///Setters

///Metodos

Menu::ejecutar(){
    while(_tecnicoLogueado){
        mostrarMenuPrincipal();
    }
}

Menu::menuLogin(){
    int intentos = 0;
    while(intentos < 3 && !getSesionActiva()){

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