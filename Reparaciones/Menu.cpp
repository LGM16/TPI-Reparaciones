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

    cout << "========== INICIO DE SESION ==========" << endl;

    if(!_managerTecnico.hayTecnicos()){
        cout << "No se encontro tecnicos.dat o no hay tecnicos registrados." << endl;
        cout << "Debe existir al menos un tecnico activo para iniciar sesion." << endl;
        return;
    }

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
        cout << "========== MENU PRINCIPAL ==========" << endl;
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
        cout << "========== MENU CLIENTES ==========" << endl;
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

    int opcion;

    do{
        cout << endl;
        cout << "========== MENU EQUIPOS ==========" << endl;
        cout << "1. Cargar equipo" << endl;
        cout << "2. Listar equipos" << endl;
        cout << "3. Buscar equipo por ID" << endl;
        cout << "4. Dar de baja equipo" << endl;
        cout << "0. Volver" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                _managerEquipo.crearEquipo();
                break;
            case 2:
                _managerEquipo.listarEquipos();
                break;
            case 3:
                _managerEquipo.listarXId();
                break;
            case 4:
                _managerEquipo.darBajaEquipo();
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

void Menu::menuReparaciones(){

    int opcion;

    do{
        cout << endl;
        cout << "========== MENU REPARACIONES ==========" << endl;
        cout << "1. Cargar reparacion" << endl;
        cout << "2. Listar reparaciones" << endl;
        cout << "3. Buscar reparacion por ID" << endl;
        cout << "4. Dar de baja reparacion" << endl;
        cout << "5. Actualizar estado de reparacion" << endl;
        cout << "0. Volver" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                _managerReparacion.crearReparacion();
                break;
            case 2:
                _managerReparacion.listarReparaciones();
                break;
            case 3:
                _managerReparacion.listarXId();
                break;
            case 4:
                _managerReparacion.darBajaReparacion();
                break;
            case 5:
                _managerReparacion.actualizarEstadoRep();
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

void Menu::menuInformes(){

    int opcion;

    do{
        cout << endl;
        cout << "========== MENU INFORMES ==========" << endl;
        cout << "1. Reparaciones en proceso" << endl;
        cout << "2. Reparaciones por cliente" << endl;
        cout << "3. Reparaciones por rango de fechas" << endl;
        cout << "4. Total facturado" << endl;
        cout << "5. Equipos por tipo" << endl;
        cout << "6. Reparaciones por tecnico" << endl;
        cout << "0. Volver" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                _managerInforme.informeReparacionesEnProceso();
                break;
            case 2:
                _managerInforme.informeReparacionesPorCliente();
                break;
            case 3:
                _managerInforme.informeReparacionesPorRangoFechas();
                break;
            case 4:
                _managerInforme.informeTotalFacturado();
                break;
            case 5:
                _managerInforme.informeEquiposPorTipo();
                break;
            case 6:
                _managerInforme.informeReparacionesPorTecnico();
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

void Menu::menuTecnicos(){

    int opcion;

    do{
        cout << endl;
        cout << "========== MENU TECNICOS ==========" << endl;
        cout << "1. Cargar tecnico" << endl;
        cout << "2. Listar tecnicos" << endl;
        cout << "3. Buscar tecnico por ID" << endl;
        cout << "4. Dar de baja tecnico" << endl;
        cout << "0. Volver" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                _managerTecnico.crearTecnico();
                break;
            case 2:
                _managerTecnico.listarTecnicos();
                break;
            case 3:
                _managerTecnico.listarXId();
                break;
            case 4:
                _managerTecnico.darBajaTecnico();
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
