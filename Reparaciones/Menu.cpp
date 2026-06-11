#include <iostream>
using namespace std;
#include "Menu.h"

///Constructor

Menu::Menu(){
    _tecnicoLogueado = false;
}

///Setters

void Menu::setSesionActiva(bool tecnicoLogueado){
    _tecnicoLogueado = tecnicoLogueado;
}

///Metodos

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
    string usuario, contrasenia;
    int intentos = 0;

    cout << "===== INICIO DE SESION =====" << endl;

    while(intentos < 3 && !getSesionActiva()){
        cout << "Usuario: ";
        cin >> usuario;
        cout << "Contrasenia: ";
        cin >> contrasenia;

        if(_managerTecnico.validarCredenciales(usuario, contrasenia, _tecnico)){
            setSesionActiva(true);
            cout << "Bienvenido " << _tecnico.getNombre() << "!" << endl;
        }
        else{
            intentos++;
            cout << "Credenciales incorrectas, intenta de nuevo :(" << endl;
            cout << "Intento: " << intentos << " de 3" << endl;
        }
    }
}

void Menu::menuPrincipal(){
    int opcion;

    do{
        cout << endl;
        cout << "===== MENU PRINCIPAL =====" << endl;
        cout << "1. Clientes" << endl;
        cout << "2. Equipos" << endl;
        cout << "3. Reparaciones" << endl;
        cout << "4. Informes" << endl;
        cout << "5. Tecnicos" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion){
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
                break;
            default:
                cout << "Opcion no valida, intente nuevamente" << endl;
                break;
        }

    }while(opcion != 0);
}

void Menu::menuClientes(){
    int opcion;

    do{
        cout << endl;
        cout << "===== MENU CLIENTES =====" << endl;
        cout << "1. Cargar cliente" << endl;
        cout << "2. Listar clientes" << endl;
        cout << "3. Buscar cliente por ID" << endl;
        cout << "4. Dar de baja cliente" << endl;
        cout << "0. Volver" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                _managerCliente.cargarCliente();
                break;
            case 2:
                _managerCliente.listarClientes();
                break;
            case 3:
                _managerCliente.listarXId();
                break;
            case 4:
                _managerCliente.darBajaCliente();
                break;
            case 0:
                break;
            default:
                cout << "\nOpcion no valida, intente nuevamente\n";
                break;
        }

        if(opcion != 0){
            cout << "\n";
        }

    }while(opcion != 0);
}

void Menu::menuEquipos(){
    cout << "Menu de equipos en construccion." << endl;
}

void Menu::menuReparaciones(){
    cout << "Menu de reparaciones en construccion." << endl;
}

void Menu::menuInformes(){
    cout << "Menu de informes en construccion." << endl;
}

void Menu::menuTecnicos(){
    cout << "Menu de tecnicos en construccion." << endl;
}
