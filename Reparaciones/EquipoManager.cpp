#include <iostream>
#include "EquipoManager.h"

using namespace std;

///Constructor

EquipoManager::EquipoManager(){
}

///Metodos

int EquipoManager::generarId(){

    int cantidadRegistros = _archivo.getCantidadRegistros();

    if(cantidadRegistros == 0){
        return 1;
    }

    int maxId = 0;
    Equipo reg;

    for(int i = 0; i < cantidadRegistros; i++){
        reg = _archivo.leer(i);

        if(reg.getIdEquipo() > maxId){
            maxId = reg.getIdEquipo();
        }
    }
    return maxId + 1;
}

bool EquipoManager::existeId(int id){
    return _archivo.buscar(id) != -1;
}

void EquipoManager::crearEquipo(){

    string descripcion, marca, tipoEquipo;

    int idTecnico, idCliente;
    int dia, mes, anio,pos;

    int idEquipo = generarId();

    cout << "------------------------------------\n"; // linea referencia
    cout << "Ingrese los datos del equipo: \n";

    cout << "ID Cliente: ";
    cin >> idCliente;

    //pos = _archivoCliente

    if(_archivoCliente.buscar(idCliente) == -1){
        cout << "------------------------------------\n";
        cout << "No existe un cliente con ese ID.\n";
        return;
    }

    cout << "ID Tecnico: ";
    cin >> idTecnico;

    if(_archivoTecnico.buscar(idTecnico) == -1){
        cout << "------------------------------------\n";
        cout << "No existe un tecnico con ese ID.\n";
        return;
    }

    cout << "Descripcion: ";
    cin.ignore();
    getline(cin, descripcion);

    cout << "Marca: ";
    cin >> marca;

    cout << "Tipo de equipo: ";
    cin >> tipoEquipo;

    cout << "Fecha de ingreso (dia mes anio): ";
    cin >> dia >> mes >> anio;

    Fecha fechaIngreso(dia, mes, anio);

    Equipo nuevo(idEquipo, idTecnico, idCliente, descripcion, marca, tipoEquipo, fechaIngreso, true);

    if(_archivo.guardar(nuevo)){
        cout << "------------------------------------\n";
        cout << "Equipo cargado con ID: " << idEquipo << endl;
    }
    else{
        cout << "------------------------------------\n";
        cout << "No se pudo guardar el equipo.\n";
    }
}

void EquipoManager::listarEquipos(){

    int cantidadRegistros = _archivo.getCantidadRegistros();

    bool hayRegistrosValidos = false;
    bool hayActivos = false;

    if(cantidadRegistros == 0){
        cout << "------------------------------------\n";
        cout << "No hay equipos cargados.\n";
        return;
    }

    cout << "------------------------------------\n";

    for(int i = 0; i < cantidadRegistros; i++){
        Equipo reg = _archivo.leer(i);

        if(reg.getIdEquipo() > 0){

            hayRegistrosValidos = true;

            if(reg.getEstado()){

                listar(reg);

                hayActivos = true;
            }
        }
    }

    if(!hayRegistrosValidos){
        cout << "------------------------------------\n";
        cout << "No hay equipos cargados.\n";
    }
    else{
        if(!hayActivos){
            cout << "------------------------------------\n";
            cout << "No hay equipos activos.\n";
        }
    }
}

void EquipoManager::listarXId(){

    int cantidadRegistros = _archivo.getCantidadRegistros();
    int id, pos;

    Equipo reg;

    if(cantidadRegistros == 0){
        cout << "------------------------------------\n";
        cout << "No hay equipos cargados.\n";
        return;
    }

    cout << "Ingrese el ID del equipo: ";
    cin >> id;

    pos = _archivo.buscar(id);

    if(pos == -1){
        cout << "------------------------------------\n";
        cout << "No se encontro un equipo con ese ID.\n";
        return;
    }

    reg = _archivo.leer(pos);
    listar(reg);
}

void EquipoManager::listar(const Equipo& equipo){

    cout << "ID: " << equipo.getIdEquipo() << endl;
    cout << "ID Cliente: " << equipo.getIdCliente() << endl;
    cout << "ID Tecnico: " << equipo.getIdTecnico() << endl;
    cout << "Descripcion: " << equipo.getDescripcion() << endl;
    cout << "Marca: " << equipo.getMarca() << endl;
    cout << "Tipo: " << equipo.getTipoEquipo() << endl;
    cout << "Fecha ingreso: " << equipo.getFechaIngreso().getDia() << "/"
         << equipo.getFechaIngreso().getMes() << "/"
         << equipo.getFechaIngreso().getAnio() << endl;

    if(equipo.getEstado()){
        cout << "Estado: Activo\n";
    }
    else{
        cout << "Estado: Inactivo\n";
    }
    cout << "------------------------------------\n";
}

void EquipoManager::darAltaEquipo(){

    int cantidadRegistros = _archivo.getCantidadRegistros();
    int id, pos;

    Equipo reg;

    if(cantidadRegistros == 0){
        cout << "------------------------------------\n";
        cout << "No hay equipos cargados.\n";
        return;
    }

    cout << "Ingrese el ID del equipo a dar de alta: ";
    cin >> id;

    pos = _archivo.buscar(id);

    if(pos == -1){
        cout << "------------------------------------\n";
        cout << "No se encontro un equipo con ese ID.\n";
        return;
    }

    reg = _archivo.leer(pos);

    if(reg.getEstado()){
        cout << "------------------------------------\n";
        cout << "El equipo ya se encuentra activo.\n";
        return;
    }

    reg.setEstado(true);

    if(_archivo.guardar(reg, pos)){
        cout << "------------------------------------\n";
        cout << "Equipo dado de alta correctamente.\n";
    }
    else{
        cout << "------------------------------------\n";
        cout << "No se pudo dar de alta al equipo.\n";
    }
    cout << "------------------------------------\n";
}

void EquipoManager::darBajaEquipo(){

    int cantidadRegistros = _archivo.getCantidadRegistros();
    int id, pos;

    Equipo reg;

    if(cantidadRegistros == 0){
        cout << "------------------------------------\n";
        cout << "No hay equipos cargados.\n";
        return;
    }

    cout << "Ingrese el ID del equipo a dar de baja: ";
    cin >> id;

    pos = _archivo.buscar(id);

    if(pos == -1){
        cout << "------------------------------------\n";
        cout << "No se encontro un equipo con ese ID.\n";
        return;
    }

    reg = _archivo.leer(pos);

    if(!reg.getEstado()){
        cout << "------------------------------------\n";
        cout << "El equipo ya se encuentra inactivo.\n";
        return;
    }

    reg.setEstado(false);

    if(_archivo.guardar(reg, pos)){
        cout << "------------------------------------\n";
        cout << "Equipo dado de baja correctamente.\n";
    }
    else{
        cout << "------------------------------------\n";
        cout << "No se pudo dar de baja al equipo.\n";
    }
    cout << "------------------------------------\n";
}
