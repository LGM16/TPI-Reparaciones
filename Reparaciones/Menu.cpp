#include <iostream>
#include "Menu.h"
using namespace std;

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
        cout << "No se pudo iniciar sesion, hasta luego! :(\n";

        rlutil::setColor(rlutil::WHITE);
    }
}

void Menu::menuLogin(){

    string usuario, contrasenia;

    int intentos = 0;

    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::WHITE);

    cout << "========== INICIO DE SESION ==========\n";

    if(!_managerTecnico.hayTecnicos()){
        string opcion;
        //int opcion;

        cout << "No hay tecnicos registrados (tecnicos.dat no existe o esta vacio).\n";
        cout << "Desea crear el primer tecnico para ingresar? (1: Si, 0: No): ";
        cin >> opcion;

        //if(opcion != 1) si uso el int
        if(opcion != "1" && opcion != "si" && opcion != "Si" && opcion != "SI" && opcion != "sI" && opcion != "s" && opcion != "S" ){
            rlutil::setColor(rlutil::RED);

            cout << "No se puede continuar sin un tecnico registrado.\n";
            return;
        }

        if(_managerTecnico.crearTecnico(_tecnico)){
            setSesionActiva(true);
            cout << endl;
            cout << "Tecnico creado. Bienvenido " << _tecnico.getNombre() << "!\n";

            rlutil::anykey();

            return;
        }
        else{
            cout << "No se pudo crear el tecnico. Fin del programa.\n";
            return;
        }
    }

    while(intentos < 3 && !getSesionActiva()){

        cout << "Usuario: ";
        cin >> usuario;

        cout << "Contrasenia: ";
        cin >> contrasenia;

        if(_managerTecnico.validarCredenciales(usuario, contrasenia, _tecnico)){
            setSesionActiva(true);

            cout << endl;
            cout << "Bienvenido " << _tecnico.getNombre() << "!\n";

            rlutil::anykey();
        }
        else{
            intentos++;

            rlutil::setColor(rlutil::RED);

            cout << "Credenciales incorrectas, intenta de nuevo :(\n";
            cout << "Intento: " << intentos << " de 3\n";
            cout << "---------------------------------------------\n";

            rlutil::setColor(rlutil::WHITE);
        }
    }
}

void Menu::menuPrincipal(){

    int opcion;

    do{
        rlutil::cls();
        rlutil::setBackgroundColor(rlutil::BLUE);

        cout << endl;
        cout << "========== MENU PRINCIPAL ==========\n";
        cout << "1. Clientes\n";
        cout << "2. Equipos\n";
        cout << "3. Reparaciones\n";
        cout << "4. Informes\n";
        cout << "5. Tecnicos\n";
        cout << "0. Salir\n";
        cout << "------------------------------------\n"; // linea referencia
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        /*  si ingreso una letra, menu se rompe, esto no lo soluciona
        if(cin >> opcion){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            rlutil::setColor(rlutil::RED);

            cout << "Ingresa un numero.\n";

            rlutil::anykey();
            rlutil::setColor(rlutil::WHITE);

            continue;
        }
        */

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
                cout << "------------------------------------\n"; // linea referencia
                cout << "Sesion cerrada, hasta luego!\n";
                setSesionActiva(false);
                break;
            default:
                ///copiar en todos los default
                rlutil::setColor(rlutil::RED);

                cout << "Opcion no valida, intente nuevamente\n";

                rlutil::anykey();
                rlutil::setColor(rlutil::WHITE);
                break;
        }

    }while(opcion != 0);
}

void Menu::menuClientes(){

    int opcion;

    do{
        rlutil::cls();

        cout << endl;
        cout << "========== MENU CLIENTES ==========\n";
        cout << "1. Cargar cliente\n";
        cout << "2. Listar clientes\n";
        cout << "3. Buscar cliente por ID\n";
        cout << "4. Dar de baja cliente\n";
        cout << "0. Volver\n";
        cout << "------------------------------------\n"; // linea referencia
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                _managerCliente.cargarCliente();
                rlutil::anykey();
                break;
            case 2:
                _managerCliente.listarClientes();
                rlutil::anykey();
                break;
            case 3:
                _managerCliente.listarXId();
                rlutil::anykey();
                break;
            case 4:
                _managerCliente.darBajaCliente();
                rlutil::anykey();
                break;
            case 0:
                break;
            default:
                rlutil::setColor(rlutil::RED);

                cout << "Opcion no valida, intente nuevamente\n";

                rlutil::anykey();
                rlutil::setColor(rlutil::WHITE);
                break;
        }

        if(opcion != 0){
            cout << endl;
        }

    }while(opcion != 0);
}

void Menu::menuEquipos(){

    int opcion;

    do{
        rlutil::cls();

        cout << endl;
        cout << "========== MENU EQUIPOS ==========\n";
        cout << "1. Cargar equipo\n";
        cout << "2. Listar equipos\n";
        cout << "3. Buscar equipo por ID\n";
        cout << "4. Dar de baja equipo\n";
        cout << "0. Volver\n";
        cout << "------------------------------------\n"; // linea referencia
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                _managerEquipo.crearEquipo();
                rlutil::anykey();
                break;
            case 2:
                _managerEquipo.listarEquipos();
                rlutil::anykey();
                break;
            case 3:
                _managerEquipo.listarXId();
                rlutil::anykey();
                break;
            case 4:
                _managerEquipo.darBajaEquipo();
                rlutil::anykey();
                break;
            case 0:
                break;
            default:
                rlutil::setColor(rlutil::RED);

                cout << "Opcion no valida, intente nuevamente\n";

                rlutil::anykey();
                rlutil::setColor(rlutil::WHITE);
                break;
        }

        if(opcion != 0){
            cout << endl;
        }

    }while(opcion != 0);
}

void Menu::menuReparaciones(){

    int opcion;

    do{
        rlutil::cls();

        cout << endl;
        cout << "========== MENU REPARACIONES ==========\n";
        cout << "1. Cargar reparacion\n";
        cout << "2. Listar reparaciones\n";
        cout << "3. Buscar reparacion por ID\n";
        cout << "4. Dar de baja reparacion\n";
        cout << "5. Actualizar estado de reparacion\n";
        cout << "0. Volver\n";
        cout << "------------------------------------\n"; // linea referencia
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                _managerReparacion.crearReparacion();
                rlutil::anykey();
                break;
            case 2:
                _managerReparacion.listarReparaciones();
                rlutil::anykey();
                break;
            case 3:
                _managerReparacion.listarXId();
                rlutil::anykey();
                break;
            case 4:
                _managerReparacion.darBajaReparacion();
                rlutil::anykey();
                break;
            case 5:
                _managerReparacion.actualizarEstadoRep();
                rlutil::anykey();
                break;
            case 0:
                break;
            default:
                rlutil::setColor(rlutil::RED);

                cout << "Opcion no valida, intente nuevamente\n";

                rlutil::anykey();
                rlutil::setColor(rlutil::WHITE);
                break;
        }

        if(opcion != 0){
            cout << endl;
        }

    }while(opcion != 0);
}

void Menu::menuInformes(){

    int opcion;

    do{
        rlutil::cls();

        cout << endl;
        cout << "========== MENU INFORMES ==========\n";
        cout << "1. Reparaciones en proceso\n";
        cout << "2. Reparaciones por cliente\n";
        cout << "3. Reparaciones por rango de fechas\n";
        cout << "4. Total facturado\n";
        cout << "5. Equipos por tipo\n";
        cout << "6. Reparaciones por tecnico\n";
        cout << "0. Volver\n";
        cout << "------------------------------------\n"; // linea referencia
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                _managerInforme.informeReparacionesEnProceso();
                rlutil::anykey();
                break;
            case 2:
                _managerInforme.informeReparacionesPorCliente();
                rlutil::anykey();
                break;
            case 3:
                _managerInforme.informeReparacionesPorRangoFechas();
                rlutil::anykey();
                break;
            case 4:
                _managerInforme.informeTotalFacturado();
                rlutil::anykey();
                break;
            case 5:
                _managerInforme.informeEquiposPorTipo();
                rlutil::anykey();
                break;
            case 6:
                _managerInforme.informeReparacionesPorTecnico();
                rlutil::anykey();
                break;
            case 0:
                break;
            default:
                rlutil::setColor(rlutil::RED);

                cout << "Opcion no valida, intente nuevamente\n";

                rlutil::anykey();
                rlutil::setColor(rlutil::WHITE);
                break;
        }

        if(opcion != 0){
            cout << endl;
        }

    }while(opcion != 0);
}

void Menu::menuTecnicos(){

    int opcion;

    do{
        rlutil::cls();

        cout << endl;
        cout << "========== MENU TECNICOS ==========\n";
        cout << "1. Cargar tecnico\n";
        cout << "2. Listar tecnicos\n";
        cout << "3. Buscar tecnico por ID\n";
        cout << "4. Dar de baja tecnico\n";
        cout << "0. Volver\n";
        cout << "------------------------------------\n"; // linea referencia
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:{
                Tecnico t;
                _managerTecnico.crearTecnico(t);
                rlutil::anykey();
                break;
            }
            case 2:
                _managerTecnico.listarTecnicos();
                rlutil::anykey();
                break;
            case 3:
                _managerTecnico.listarXId();
                rlutil::anykey();
                break;
            case 4:
                _managerTecnico.darBajaTecnico();
                rlutil::anykey();
                break;
            case 0:
                break;
            default:
                rlutil::setColor(rlutil::RED);

                cout << "Opcion no valida, intente nuevamente\n";

                rlutil::anykey();
                rlutil::setColor(rlutil::WHITE);
                break;
        }

        if(opcion != 0){
            cout << endl;
        }

    }while(opcion != 0);
}
