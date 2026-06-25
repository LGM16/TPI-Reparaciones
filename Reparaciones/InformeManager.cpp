#include <iostream>
#include <cstring>
#include "InformeManager.h"

using namespace std;

///Constructor

InformeManager::InformeManager(){
}

///Metodos

int InformeManager::fechaAEntero(Fecha fecha){
    return fecha.getAnio() * 10000 + fecha.getMes() * 100 + fecha.getDia();
}

bool InformeManager::fechaEnRango(Fecha fecha, Fecha fechaDesde, Fecha fechaHasta){
    int valorFecha = fechaAEntero(fecha);
    int valorFechaDesde = fechaAEntero(fechaDesde);
    int valorFechaHasta = fechaAEntero(fechaHasta);

    if(valorFecha >= valorFechaDesde && valorFecha <= valorFechaHasta){
        return true;
    }
    else{
        return false;
    }
}

void InformeManager::informeReparacionesEnProceso(){

    int cantidadRegistros = _archivoReparacion.getCantidadRegistros();
    bool hayResultados = false;

    cout << "========== REPARACIONES EN PROCESO ==========\n";

    if(cantidadRegistros == 0){
        cout << "---------------------------------------------\n"; // linea referencia
        cout << "No hay reparaciones cargadas.\n";
        return;
    }

    for(int i = 0; i < cantidadRegistros; i++){
        Reparacion reg = _archivoReparacion.leer(i);

        if(reg.getIdReparacion() > 0 && reg.getEstado() && reg.getEstadoRep() == 1){
            hayResultados = true;
            cout << "ID: " << reg.getIdReparacion()
                 << " | Equipo: " << reg.getIdEquipo()
                 << " | Importe: $" << reg.getImporte() << endl;
            cout << "---------------------------------------------\n"; // linea referencia
        }
    }

    if(!hayResultados){
        cout << "------------------------------------\n"; // linea referencia
        cout << "No hay reparaciones en proceso.\n";
    }
}

void InformeManager::informeReparacionesPorCliente(){

    int idCliente, cantidadRegistros;
    bool hayResultados = false;

    cout << "Ingrese el ID del cliente: ";
    cin >> idCliente;

    rlutil::cls();

    if(_archivoCliente.buscar(idCliente) == -1){
        cout << "------------------------------------\n"; // linea referencia
        cout << "No existe un cliente con ese ID.\n";
        return;
    }

    cantidadRegistros = _archivoReparacion.getCantidadRegistros();

    cout << "========== REPARACIONES DEL CLIENTE " << idCliente << " ==========\n";

    for(int i = 0; i < cantidadRegistros; i++){
        Reparacion reg = _archivoReparacion.leer(i);

        if(reg.getIdReparacion() > 0 && reg.getEstado()){
            int posEq = _archivoEquipo.buscar(reg.getIdEquipo());

            if(posEq != -1){
                Equipo eq = _archivoEquipo.leer(posEq);

                if(eq.getIdCliente() == idCliente){
                    hayResultados = true;
                    cout << "Reparacion ID: " << reg.getIdReparacion()
                         << " | Equipo: " << reg.getIdEquipo()
                         << " | Importe: $" << reg.getImporte() << endl;
                    cout << "------------------------------------------------\n"; // linea referencia
                }
            }
        }
    }

    if(!hayResultados){
        cout << "------------------------------------\n"; // linea referencia
        cout << "No hay reparaciones para ese cliente.\n";
    }
}

void InformeManager::informeReparacionesPorRangoFechas(){

    int cantidadRegistros, contador = 0;

    Fecha fechaDesde;
    Fecha fechaHasta;

    do{

        cout << "------------------------------------------------------\n"; // linea referencia
        cout << "Fecha desde (DD/MM/AAAA): \n";
        fechaDesde.cargar();

        cout << "Fecha hasta (DD/MM/AAAA): \n";
        fechaHasta.cargar();

        if(fechaAEntero(fechaDesde) <= fechaAEntero(fechaHasta)){
            break;
        }

        cout << "------------------------------------------------------\n"; // linea referencia
        cout << "La fecha 'desde' no puede ser posterior a 'hasta'.\n";
        cout << "Desde: " << fechaDesde.toString()
             << " hasta: " << fechaHasta.toString() << endl;
        cout << "------------------------------------------------------\n"; // linea referencia
        cout << "Intente nuevamente \n";

    }while(true);

    cantidadRegistros = _archivoReparacion.getCantidadRegistros();

    rlutil::cls();

    cout << "========== REPARACIONES POR RANGO DE FECHAS ==========\n";
    cout << "Rango desde: " << fechaDesde.toString()
         << " hasta: " << fechaHasta.toString() << endl;
    cout << "------------------------------------------------------\n"; // linea referencia

    for(int i = 0; i < cantidadRegistros; i++){
        Reparacion reg = _archivoReparacion.leer(i);

        if(reg.getIdReparacion() > 0 && reg.getEstado()){
            if(fechaEnRango(reg.getFechaIngreso(), fechaDesde, fechaHasta)){
                contador++;
                cout << "ID: " << reg.getIdReparacion()
                     << " | Fecha ingreso: " << reg.getFechaIngreso().toString()
                     << " | Importe: $" << reg.getImporte() << endl;
                cout << "------------------------------------------------------\n"; // linea referencia
            }
        }
    }

    cout << "Total en rango: " << contador << endl;
    cout << "------------------------------------------------------\n"; // linea referencia
}

void InformeManager::informeTotalFacturado(){

    int cantidadRegistros = _archivoReparacion.getCantidadRegistros();
    float total = 0;

    for(int i = 0; i < cantidadRegistros; i++){
        Reparacion reg = _archivoReparacion.leer(i);

        if(reg.getIdReparacion() > 0 && reg.getEstado() && reg.getEstadoRep() == 2){
            total += reg.getImporte();
        }
    }

    cout << "========== TOTAL FACTURADO (REPARADAS) ==========\n";
    cout << "Importe total: $" << total << endl;
    cout << "-------------------------------------------------\n"; // linea referencia
}

void InformeManager::informeEquiposPorTipo(){

    int cantidadRegistros = _archivoEquipo.getCantidadRegistros();

    char tipos[50][51];
    int conteos[50];
    int cantTipos = 0;

    cout << "========== EQUIPOS POR TIPO ==========\n";

    if(cantidadRegistros == 0){
        cout << "------------------------------------\n"; // linea referencia
        cout << "No hay equipos cargados.\n";
        return;
    }

    for(int i = 0; i < cantidadRegistros; i++){
        Equipo reg = _archivoEquipo.leer(i);

        if(reg.getIdEquipo() > 0 && reg.getEstado()){
            string tipo = reg.getTipoEquipo();
            bool encontrado = false;

            for(int j = 0; j < cantTipos; j++){
                if(tipo == string(tipos[j])){
                    conteos[j]++;
                    encontrado = true;
                    break;
                }
            }

            if(!encontrado && cantTipos < 50){
                strcpy(tipos[cantTipos], tipo.c_str());
                conteos[cantTipos] = 1;
                cantTipos++;
            }
        }
    }

    if(cantTipos == 0){
        cout << "No hay equipos activos.\n";
        cout << "--------------------------------------\n"; // linea referencia
        return;
    }

    for(int i = 0; i < cantTipos; i++){
        cout << tipos[i] << ": " << conteos[i] << endl;
        cout << "--------------------------------------\n"; // linea referencia
    }
}

void InformeManager::informeReparacionesPorTecnico(){

    int idTecnico, cantidadRegistros, pos;
    int contador = 0;

    Tecnico tecnico;

    cout << "Ingrese el ID del tecnico: ";
    cin >> idTecnico;

    pos = _archivoTecnico.buscar(idTecnico);

    if(pos == -1){
        cout << "------------------------------------\n"; // linea referencia
        cout << "No existe un tecnico con ese ID.\n";
        return;
    }

    cantidadRegistros = _archivoReparacion.getCantidadRegistros();
    tecnico = _archivoTecnico.leer(pos);

    rlutil::cls();

    cout << "========== REPARACIONES DEL TECNICO " << idTecnico << " ==========\n";
    cout << "Tecnico: " << tecnico.getNombre() << " " << tecnico.getApellido() << endl;
    cout << "------------------------------------------------\n"; // linea referencia

    for(int i = 0; i < cantidadRegistros; i++){
        Reparacion reg = _archivoReparacion.leer(i);

        if(reg.getIdReparacion() > 0 && reg.getEstado()){
            int posEq = _archivoEquipo.buscar(reg.getIdEquipo());

            if(posEq != -1){
                Equipo eq = _archivoEquipo.leer(posEq);

                if(eq.getIdTecnico() == idTecnico){
                    contador++;
                    cout << "Reparacion ID: " << reg.getIdReparacion()
                         << " | Equipo: " << reg.getIdEquipo()
                         << " | EstadoRep: " << reg.getEstadoRep() << endl;
                    cout << "------------------------------------------------\n"; // linea referencia
                }
            }
        }
    }

    if(contador == 0){
        cout << "------------------------------------------------\n"; // linea referencia
        cout << "No hay reparaciones asignadas a ese tecnico.\n";
    }
    else{
        cout << "Total reparaciones: " << contador << endl;
        cout << "------------------------------------------------\n"; // linea referencia
    }
}
