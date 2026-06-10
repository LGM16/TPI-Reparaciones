#include <iostream>
using namespace std;
#include "Menu.h"

///Constructor

Menu::Menu(){
    _tecnicoLogueado = false;
}

///Setters

///Metodos

//Menu::ejecutar() es el metodo que se encarga de ejecutar el programa 
//Mostrando el menu de login y luego el menu principal
/*

void Menu::ejecutar(){
    menuLogin();
    if(getSesionActiva()){
        menuPrincipal();
    }
    else{
        cout << "No se pudo iniciar sesion, hasta luego! :(" << endl;
    }
}

void Menu::menuLogin(){
    int intentos = 0;
    while(intentos < 3 && !getSesionActiva()){
        if(algo){ //to do: aca tengo que validar contra archivosTecnicos?
            cout << "Bievenido " << endl; //aca iria getnombre del tecnico?
        }
        else{
            intentos++;
            cout << "Credenciales incorrectas, intenta de nuevo :(" << endl;
            cout << "Intento: " << intentos << " de 3" << endl;
        }
    }
}

*/
///Menu::menuPrincipal() es el menu que se muestra al tecnico una vez que se loguea
//

void Menu::menuPrincipal(){
    int opcion;

    do{
        cin >> opcion;
        switch (opcion){
            case 1:
                menuClientes();
                break;
            case 2:
                menuEquipos();
                break;
            case 3:
                menuReparaciones();
                break;
            case 4:
                menuInformes();
                break;
            case 5:
                menuTecnicos();
                break;
            case 0:
                cout << "Sesion cerrada, hasta luego!" << endl;
                setSesionActiva(false);
            default:
                cout << "Opcion no valida, intente nuevamente" << endl;
                break;
        }


    }while(opcion != 0);
}

void Menu::menuClientes(){
    
}