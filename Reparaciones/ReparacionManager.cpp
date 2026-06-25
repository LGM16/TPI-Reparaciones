#include <iostream>
#include "ReparacionManager.h"

using namespace std;

///Constructor

ReparacionManager::ReparacionManager(){
}

///Metodos

int ReparacionManager::generarId(){

    int cantidadRegistros = _archivo.getCantidadRegistros();

    if(cantidadRegistros == 0){
        return 1;
    }

    int maxId = 0;
    Reparacion reg;

    for(int i = 0; i < cantidadRegistros; i++){
        reg = _archivo.leer(i);

        if(reg.getIdReparacion() > maxId){
            maxId = reg.getIdReparacion();
        }
    }
    return maxId + 1;
}

bool ReparacionManager::existeId(int id){
    return _archivo.buscar(id) != -1;
}

void ReparacionManager::crearReparacion(){

    int idEquipo;
    int diaIng, mesIng, anioIng;
    int diaEgr, mesEgr, anioEgr;
    float importe;
    int estadoRep;

    int idReparacion = generarId();

    cout << "------------------------------------\n"; // linea referencia
    cout << "Ingrese los datos de la reparacion: \n";

    cout << "ID Equipo: ";
    cin >> idEquipo;

    if(_archivoEquipo.buscar(idEquipo) == -1){
        cout << "No existe un equipo con ese ID.\n";
        return;
    }

    cout << "Fecha de ingreso (DD/MM/AAAA): ";
    cin >> diaIng >> mesIng >> anioIng;

    cout << "Fecha de egreso (DD/MM/AAAA): ";
    cin >> diaEgr >> mesEgr >> anioEgr;

    cout << "Importe: $";
    cin >> importe;

    cout << "Estado reparacion (1: en proceso, 2: reparado, 3: no reparado): ";
    cin >> estadoRep;

    while(estadoRep < 1 || estadoRep > 3){
        cout << "Estado invalido. Ingrese 1, 2 o 3: ";
        cin >> estadoRep;
    }

    Fecha fechaIngreso(diaIng, mesIng, anioIng);
    Fecha fechaEgreso(diaEgr, mesEgr, anioEgr);

    Reparacion nueva(idReparacion, idEquipo, fechaIngreso, fechaEgreso, importe, estadoRep, true);

    if(_archivo.guardar(nueva)){
        cout << "Reparacion cargada con ID: " << idReparacion << endl;
    }
    else{
        cout << "------------------------------------\n"; // linea referencia
        cout << "No se pudo guardar la reparacion.\n";
    }
}

void ReparacionManager::listarReparaciones(){

    int cantidadRegistros = _archivo.getCantidadRegistros();

    bool hayRegistrosValidos = false;
    bool hayActivos = false;

    if(cantidadRegistros == 0){
        cout << "------------------------------------\n"; // linea referencia
        cout << "No hay reparaciones cargadas.\n";
        return;
    }

    cout << "------------------------------------\n"; // linea referencia

    for(int i = 0; i < cantidadRegistros; i++){
        Reparacion reg = _archivo.leer(i);

        if(reg.getIdReparacion() > 0){

            hayRegistrosValidos = true;

            if(reg.getEstado()){

                listar(reg);

                hayActivos = true;
            }
        }
    }

    if(!hayRegistrosValidos){
        cout << "------------------------------------\n"; // linea referencia
        cout << "No hay reparaciones cargadas.\n";
    }
    else{
        if(!hayActivos){
            cout << "------------------------------------\n"; // linea referencia
            cout << "No hay reparaciones activas.\n";
        }
    }
}

void ReparacionManager::listarXId(){

    int id, pos;
    int cantidadRegistros = _archivo.getCantidadRegistros();

    Reparacion reg;

    if(cantidadRegistros == 0){
        cout << "------------------------------------\n"; // linea referencia
        cout << "No hay reparaciones cargadas.\n";
        return;
    }

    cout << "Ingrese el ID de la reparacion: ";
    cin >> id;

    pos = _archivo.buscar(id);

    if(pos == -1){
        cout << "------------------------------------\n"; // linea referencia
        cout << "No se encontro una reparacion con ese ID.\n";
        return;
    }

    reg = _archivo.leer(pos);

    cout << "------------------------------------\n"; // linea referencia
    listar(reg);
}

void ReparacionManager::listar(const Reparacion& reparacion){

    cout << "ID: " << reparacion.getIdReparacion() << endl;
    cout << "ID Equipo: " << reparacion.getIdEquipo() << endl;
    cout << "Fecha ingreso: " << reparacion.getFechaIngreso().getDia() << "/"
         << reparacion.getFechaIngreso().getMes() << "/"
         << reparacion.getFechaIngreso().getAnio() << endl;
    cout << "Fecha egreso: " << reparacion.getFechaEgreso().getDia() << "/"
         << reparacion.getFechaEgreso().getMes() << "/"
         << reparacion.getFechaEgreso().getAnio() << endl;
    cout << "Importe: " << reparacion.getImporte() << endl;

    switch(reparacion.getEstadoRep()){
        case 1:
            cout << "Estado reparacion: En proceso\n";
            break;
        case 2:
            cout << "Estado reparacion: Reparado\n";
            break;
        case 3:
            cout << "Estado reparacion: No reparado\n";
            break;
    }

    if(reparacion.getEstado()){
        cout << "Estado: Activo\n";
    }
    else{
        cout << "Estado: Inactivo\n";
    }
    cout << "------------------------------------\n"; // linea referencia
}

void ReparacionManager::darAltaReparacion(){

    int id, pos;
    int cantidadRegistros = _archivo.getCantidadRegistros();

    Reparacion reg;

    if(cantidadRegistros == 0){
        cout << "------------------------------------\n"; // linea referencia
        cout << "No hay reparaciones cargadas.\n";
        return;
    }

    cout << "Ingrese el ID de la reparacion a dar de alta: ";
    cin >> id;

    pos = _archivo.buscar(id);

    if(pos == -1){
        cout << "------------------------------------\n"; // linea referencia
        cout << "No se encontro una reparacion con ese ID.\n";
        return;
    }

    reg = _archivo.leer(pos);

    if(reg.getEstado()){
        cout << "------------------------------------\n"; // linea referencia
        cout << "La reparacion ya se encuentra activa.\n";
        return;
    }

    reg.setEstado(true);

    if(_archivo.guardar(reg, pos)){
        cout << "------------------------------------\n"; // linea referencia
        cout << "Reparacion dada de alta correctamente.\n";
    }
    else{
        cout << "------------------------------------\n"; // linea referencia
        cout << "No se pudo dar de alta la reparacion.\n";
    }
}

void ReparacionManager::darBajaReparacion(){

    int id, pos;
    int cantidadRegistros = _archivo.getCantidadRegistros();

    Reparacion reg;

    if(cantidadRegistros == 0){
        cout << "------------------------------------\n"; // linea referencia
        cout << "No hay reparaciones cargadas.\n";
        return;
    }

    cout << "Ingrese el ID de la reparacion a dar de baja: ";
    cin >> id;

    pos = _archivo.buscar(id);

    if(pos == -1){
        cout << "------------------------------------\n"; // linea referencia
        cout << "No se encontro una reparacion con ese ID.\n";
        return;
    }

    reg = _archivo.leer(pos);

    if(!reg.getEstado()){
        cout << "------------------------------------\n"; // linea referencia
        cout << "La reparacion ya se encuentra inactiva.\n";
        return;
    }

    reg.setEstado(false);

    if(_archivo.guardar(reg, pos)){
        cout << "------------------------------------\n"; // linea referencia
        cout << "Reparacion dada de baja correctamente.\n";
    }
    else{
        cout << "------------------------------------\n"; // linea referencia
        cout << "No se pudo dar de baja la reparacion.\n";
    }
}

void ReparacionManager::actualizarEstadoRep(){

    int id, pos, estadoRep;
    int cantidadRegistros = _archivo.getCantidadRegistros();

    Reparacion reg;

    if(cantidadRegistros == 0){
        cout << "------------------------------------\n"; // linea referencia
        cout << "No hay reparaciones cargadas.\n";
        return;
    }

    cout << "Ingrese el ID de la reparacion: ";
    cin >> id;

    pos = _archivo.buscar(id);

    if(pos == -1){
        cout << "------------------------------------\n"; // linea referencia
        cout << "No se encontro una reparacion con ese ID.\n";
        return;
    }

    reg = _archivo.leer(pos);

    if(!reg.getEstado()){
        cout << "------------------------------------\n"; // linea referencia
        cout << "La reparacion se encuentra inactiva.\n";
        return;
    }

    cout << "Nuevo estado (1: en proceso, 2: reparado, 3: no reparado): ";
    cin >> estadoRep;

    while(estadoRep < 1 || estadoRep > 3){
        cout << "Estado invalido. Ingrese 1, 2 o 3: ";
        cin >> estadoRep;
    }

    reg.setEstadoRep(estadoRep);

    if(_archivo.guardar(reg, pos)){
        cout << "Estado de reparacion actualizado correctamente.\n";
    }
    else{
        cout << "No se pudo actualizar el estado de la reparacion.\n";
    }
    cout << "------------------------------------\n"; // linea referencia
}
