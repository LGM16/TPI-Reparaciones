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

        rlutil::setColor(rlutil::WHITE);
    }
}

void Menu::menuLogin(){

    string usuario, contrasenia;

    int intentos = 0;

    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::WHITE);

    cout << "========== INICIO DE SESION ==========" << endl;

    if(!_managerTecnico.hayTecnicos()){
        string opcion;
        //int opcion;

        cout << "No hay tecnicos registrados (tecnicos.dat no existe o esta vacio)." << endl;
        cout << "Desea crear el primer tecnico para ingresar? (1: Si, 0: No): ";
        cin >> opcion;

        //if(opcion != 1) si uso el int
        if(opcion != "1" && opcion != "si" && opcion != "Si" && opcion != "SI" && opcion != "sI" && opcion != "s" && opcion != "S" ){
            rlutil::setColor(rlutil::RED);

            cout << "No se puede continuar sin un tecnico registrado." << endl;
            return;
        }

        if(_managerTecnico.crearTecnico(_tecnico)){
            setSesionActiva(true);
            cout << endl;
            cout << "Tecnico creado. Bienvenido " << _tecnico.getNombre() << "!" << endl;

            rlutil::anykey();

            return;
        }
        else{
            cout << "No se pudo crear el tecnico. Fin del programa." << endl;
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
            cout << "Bienvenido " << _tecnico.getNombre() << "!" << endl;

            rlutil::anykey();
        }
        else{
            intentos++;

            rlutil::setColor(rlutil::RED);

            cout << "Credenciales incorrectas, intenta de nuevo :(" << endl;
            cout << "Intento: " << intentos << " de 3" << endl;
            cout << "---------------------------------------------" << endl;

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
        cout << "========== MENU PRINCIPAL ==========" << endl;
        cout << "1. Clientes\n";
        cout << "2. Equipos\n";
        cout << "3. Reparaciones\n";
        cout << "4. Informes\n";
        cout << "5. Tecnicos\n";
        cout << "0. Salir\n";
        cout << "------------------------------------\n"; // linea referencia
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
                cout << "------------------------------------\n"; // linea referencia
                cout << "Sesion cerrada, hasta luego!" << endl;
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
        cout << "========== MENU CLIENTES ==========" << endl;
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
        cout << "========== MENU EQUIPOS ==========" << endl;
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
        cout << "========== MENU REPARACIONES ==========" << endl;
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
        cout << "========== MENU INFORMES ==========" << endl;
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
        cout << "========== MENU TECNICOS ==========" << endl;
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
                break;
            }
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
