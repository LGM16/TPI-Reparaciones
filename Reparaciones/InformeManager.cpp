#include <iostream>
#include <cstring>
#include "InformeManager.h"

using namespace std;

///Constructor

InformeManager::InformeManager(){
}

///Metodos privados

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

///Metodos

void InformeManager::informeReparacionesEnProceso(){

    int cantidad = _archivoReparacion.getCantidadRegistros();
    bool hayResultados = false;

    cout << "\n===== REPARACIONES EN PROCESO =====\n";

    if(cantidad == 0){
        cout << "No hay reparaciones cargadas.\n";
        return;
    }

    for(int i = 0; i < cantidad; i++){
        Reparacion reg = _archivoReparacion.leer(i);

        if(reg.getIdReparacion() > 0 && reg.getEstado() && reg.getEstadoRep() == 1){
            hayResultados = true;
            cout << "ID: " << reg.getIdReparacion()
                 << " | Equipo: " << reg.getIdEquipo()
                 << " | Importe: " << reg.getImporte() << endl;
        }
    }

    if(!hayResultados){
        cout << "No hay reparaciones en proceso.\n";
    }
}

void InformeManager::informeReparacionesPorCliente(){

    int idCliente, cantidad;
    bool hayResultados = false;

    cout << "Ingrese el ID del cliente: ";
    cin >> idCliente;

    if(_archivoCliente.buscar(idCliente) == -1){
        cout << "No existe un cliente con ese ID." << endl;
        return;
    }

    cantidad = _archivoReparacion.getCantidadRegistros();

    cout << "\n===== REPARACIONES DEL CLIENTE " << idCliente << " =====\n";

    for(int i = 0; i < cantidad; i++){
        Reparacion reg = _archivoReparacion.leer(i);

        if(reg.getIdReparacion() > 0 && reg.getEstado()){
            int posEq = _archivoEquipo.buscar(reg.getIdEquipo());

            if(posEq != -1){
                Equipo eq = _archivoEquipo.leer(posEq);

                if(eq.getIdCliente() == idCliente){
                    hayResultados = true;
                    cout << "Reparacion ID: " << reg.getIdReparacion()
                         << " | Equipo: " << reg.getIdEquipo()
                         << " | Importe: " << reg.getImporte() << endl;
                }
            }
        }
    }

    if(!hayResultados){
        cout << "No hay reparaciones para ese cliente.\n";
    }
}

void InformeManager::informeReparacionesPorRangoFechas(){

    int diaD, mesD, anioD, diaH, mesH, anioH;
    int cantidad, contador = 0;

    cout << "Fecha desde (dia mes anio): ";
    cin >> diaD >> mesD >> anioD;

    cout << "Fecha hasta (dia mes anio): ";
    cin >> diaH >> mesH >> anioH;

    Fecha desde(diaD, mesD, anioD);
    Fecha hasta(diaH, mesH, anioH);

    cantidad = _archivoReparacion.getCantidadRegistros();

    cout << "\n===== REPARACIONES POR RANGO DE FECHAS =====\n";

    for(int i = 0; i < cantidad; i++){
        Reparacion reg = _archivoReparacion.leer(i);

        if(reg.getIdReparacion() > 0 && reg.getEstado()){
            if(fechaEnRango(reg.getFechaIngreso(), desde, hasta)){
                contador++;
                cout << "ID: " << reg.getIdReparacion()
                     << " | Fecha ingreso: " << reg.getFechaIngreso().getDia() << "/"
                     << reg.getFechaIngreso().getMes() << "/"
                     << reg.getFechaIngreso().getAnio()
                     << " | Importe: " << reg.getImporte() << endl;
            }
        }
    }

    cout << "Total en rango: " << contador << endl;
}

void InformeManager::informeTotalFacturado(){

    int cantidad = _archivoReparacion.getCantidadRegistros();
    float total = 0;

    for(int i = 0; i < cantidad; i++){
        Reparacion reg = _archivoReparacion.leer(i);

        if(reg.getIdReparacion() > 0 && reg.getEstado() && reg.getEstadoRep() == 2){
            total += reg.getImporte();
        }
    }

    cout << "\n===== TOTAL FACTURADO (REPARADAS) =====\n";
    cout << "Importe total: $" << total << endl;
}

void InformeManager::informeEquiposPorTipo(){

    int cantidad = _archivoEquipo.getCantidadRegistros();

    char tipos[50][51];
    int conteos[50];
    int cantTipos = 0;

    cout << "\n===== EQUIPOS POR TIPO =====\n";

    if(cantidad == 0){
        cout << "No hay equipos cargados.\n";
        return;
    }

    for(int i = 0; i < cantidad; i++){
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
        return;
    }

    for(int i = 0; i < cantTipos; i++){
        cout << tipos[i] << ": " << conteos[i] << endl;
    }
}

void InformeManager::informeReparacionesPorTecnico(){

    int idTecnico, cantidad;
    int contador = 0;

    cout << "Ingrese el ID del tecnico: ";
    cin >> idTecnico;

    if(_archivoTecnico.buscar(idTecnico) == -1){
        cout << "No existe un tecnico con ese ID." << endl;
        return;
    }

    cantidad = _archivoReparacion.getCantidadRegistros();

    cout << "\n===== REPARACIONES DEL TECNICO " << idTecnico << " =====\n";

    for(int i = 0; i < cantidad; i++){
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
                }
            }
        }
    }

    if(contador == 0){
        cout << "No hay reparaciones asignadas a ese tecnico.\n";
    }
    else{
        cout << "Total reparaciones: " << contador << endl;
    }
}
