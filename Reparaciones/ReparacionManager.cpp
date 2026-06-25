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

int ReparacionManager::fechaAEntero(Fecha fecha){
    return fecha.getAnio() * 10000 + fecha.getMes() * 100 + fecha.getDia();
}

void ReparacionManager::crearReparacion(){

    int idEquipo, posEquipo;
    float importe;
    int estadoRep;
    int idReparacion = generarId();

    Fecha fechaEgreso;

    cout << "------------------------------------\n"; // linea referencia
    cout << "Ingrese los datos de la reparacion: \n";

    cout << "ID Equipo: ";
    cin >> idEquipo;

    posEquipo = _archivoEquipo.buscar(idEquipo);

    if(posEquipo == -1){
        cout << "No existe un equipo con ese ID.\n";
        return;
    }

    Equipo equipo = _archivoEquipo.leer(posEquipo);
    Fecha fechaIngreso = equipo.getFechaIngreso();

    cout << "Fecha de ingreso (del equipo): " << fechaIngreso.toString() << endl;

    do{
        cout << "Fecha de egreso estimada (DD/MM/AAAA): \n";

        fechaEgreso.cargar();

        if(fechaAEntero(fechaEgreso) >= fechaAEntero(fechaIngreso)){
            break;
        }

        cout << "------------------------------------\n"; // linea referencia
        cout << "La fecha de egreso no puede ser anterior al ingreso (" << fechaIngreso.toString() << ").\n";
        cout << "Intente nuevamente.\n";

    }while(true);




    cout << "Importe: $";
    cin >> importe;

    cout << "Estado reparacion (1: en proceso, 2: reparado, 3: no reparado): ";
    cin >> estadoRep;

    while(estadoRep < 1 || estadoRep > 3){
        cout << "Estado invalido. Ingrese 1, 2 o 3: ";
        cin >> estadoRep;
    }

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
    cout << "Fecha ingreso: " << reparacion.getFechaIngreso().toString() << endl;
    cout << "Fecha egreso: " << reparacion.getFechaEgreso().toString() << endl;
    cout << "Importe: $" << reparacion.getImporte() << endl;

    switch(reparacion.getEstadoRep()){
        case 1:
            cout << "Estado reparacion: En proceso\n";
            break;
        case 2:
            cout << "Estado reparacion: Reparado\n";
            break;
        case 3:
            cout << "Estado reparacion: Sin reparacion\n";
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

    cout << "Nuevo estado (1: en proceso, 2: reparado, 3: sin reparacion): ";
    cin >> estadoRep;

    while(estadoRep < 1 || estadoRep > 3){
        cout << "------------------------------------\n"; // linea referencia
        cout << "Estado invalido. Ingrese 1, 2 o 3: ";
        cin >> estadoRep;
    }

    reg.setEstadoRep(estadoRep);

    if(_archivo.guardar(reg, pos)){
        cout << "------------------------------------\n"; // linea referencia
        cout << "Estado de reparacion actualizado correctamente.\n";
    }
    else{
        cout << "------------------------------------\n"; // linea referencia
        cout << "No se pudo actualizar el estado de la reparacion.\n";
    }
    cout << "------------------------------------\n"; // linea referencia
}
