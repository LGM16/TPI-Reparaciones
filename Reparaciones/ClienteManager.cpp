#include <iostream>
#include "ClienteManager.h"

using namespace std;

///Constructor

ClienteManager::ClienteManager(){
}

///Metodos

int ClienteManager::generarId(){
    int cantidadRegistros = _archivo.getCantidadRegistros();

    if(cantidadRegistros == 0){
        return 1;
    }

    int maxId = 0;
    Cliente reg;

    for(int i = 0; i < cantidadRegistros; i++){
        reg = _archivo.leer(i);

        if(reg.getIdCliente() > maxId){
            maxId = reg.getIdCliente();
        }
    }
    return maxId + 1;
}

bool ClienteManager::existeId(int id){
    return _archivo.buscar(id) != -1;
}

void ClienteManager::cargarCliente(){

    string cuit, nombre, apellido, telefono, email, direccion;

    int tipoCliente;
    int idCliente = generarId();

    cout << "------------------------------------\n"; // linea referencia
    cout << "Ingrese los datos del cliente: " << endl;

    cout << "Tipo Cliente (1: Particular, 2: Empresa): ";
    cin >> tipoCliente;

    while(tipoCliente != 1 && tipoCliente != 2){
        cout << "------------------------------------\n"; // linea referencia
        cout << "Tipo invalido. Ingrese 1 (Particular) o 2 (Empresa): ";
        cin >> tipoCliente;
    }

    cout << "CUIT: ";
    cin >> cuit;

    if(tipoCliente == 1){
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, nombre);

        cout << "Apellido: ";
        getline(cin, apellido);
    }
    else{
        cout << "Razon Social: ";
        cin.ignore();
        getline(cin, nombre);
        apellido = "";
    }

    cout << "Telefono: ";
    cin >> telefono;

    cout << "Email: ";
    cin >> email;

    cout << "Direccion: ";
    cin.ignore();
    getline(cin, direccion);

    Persona persona(cuit, nombre, apellido);
    Cliente nuevo(persona, idCliente, tipoCliente, telefono, email, direccion, true);

    if(_archivo.guardar(nuevo)){
        cout << "------------------------------------\n"; // linea referencia
        cout << "Cliente cargado con ID: " << idCliente << endl;
    }
    else{
        cout << "------------------------------------\n"; // linea referencia
        cout << "No se pudo guardar el cliente." << endl;
    }
}

void ClienteManager::listarClientes(){

    int cantidadRegistros = _archivo.getCantidadRegistros();

    bool hayRegistrosValidos = false;
    bool hayActivos = false;

    if(cantidadRegistros == 0){
        cout << "------------------------------------\n"; // linea referencia
        cout << "No hay clientes cargados.\n";
        return;
    }

    for(int i = 0; i < cantidadRegistros; i++){
        Cliente reg = _archivo.leer(i);

        if(reg.getIdCliente() > 0){

            hayRegistrosValidos = true;

            if(reg.getEstado()){

                listar(reg);
                //cout << "------------------------------------\n"; // linea referencia

                hayActivos = true;
            }
        }
    }

    if(!hayRegistrosValidos){
        cout << "------------------------------------\n"; // linea referencia
        cout << "No hay clientes cargados.\n";
    }
    else{
        if(!hayActivos){
            cout << "------------------------------------\n"; // linea referencia
            cout << "No hay clientes activos.\n";
        }
    }
}

void ClienteManager::listarXId(){

    int id;
    int cantidadRegistros = _archivo.getCantidadRegistros();

    if(cantidadRegistros == 0){
        cout << "------------------------------------\n"; // linea referencia
        cout << "No hay clientes cargados.\n";
        return;
    }

    cout << "Ingrese el ID del cliente: ";
    cin >> id;

    int pos = _archivo.buscar(id);

    if(pos == -1){
        cout << "------------------------------------\n"; // linea referencia
        cout << "No se encontro un cliente con ese ID\n.";
        return;
    }

    Cliente reg = _archivo.leer(pos);

    cout << "------------------------------------\n"; // linea referencia
    listar(reg);
}

void ClienteManager::listar(const Cliente& cliente){

    cout << "ID: " << cliente.getIdCliente() << endl;
    cout << "CUIT: " << cliente.getCuit() << endl;

    if(cliente.getTipoCliente() == 1){
        cout << "Tipo Cliente: Particular\n";
        cout << "Nombre: " << cliente.getNombre() << endl;
        cout << "Apellido: " << cliente.getApellido() << endl;
    }
    else{
        cout << "Tipo Cliente: Empresa\n";
        cout << "Razon Social: " << cliente.getNombre() << endl;
    }

    cout << "Telefono: " << cliente.getTelefono() << endl;
    cout << "Email: " << cliente.getEmail() << endl;
    cout << "Direccion: " << cliente.getDireccion() << endl;

    if(cliente.getEstado()){
        cout << "Estado: Activo\n";
    }
    else{
        cout << "Estado: Inactivo\n";
    }
    cout << "------------------------------------\n"; // linea referencia
}

void ClienteManager::darBajaCliente(){

    int id;
    int cantidadRegistros = _archivo.getCantidadRegistros();

    if(cantidadRegistros == 0){
        cout << "------------------------------------\n"; // linea referencia
        cout << "No hay clientes cargados.\n";
        return;
    }

    cout << "Ingrese el ID del cliente a dar de baja: ";
    cin >> id;

    int pos = _archivo.buscar(id);

    if(pos == -1){
        cout << "------------------------------------\n"; // linea referencia
        cout << "No se encontro un cliente con ese ID.\n";
        return;
    }

    Cliente reg = _archivo.leer(pos);

    if(!reg.getEstado()){
        cout << "------------------------------------\n"; // linea referencia
        cout << "El cliente ya se encuentra inactivo.\n";
        return;
    }

    reg.setEstado(false);

    if(_archivo.guardar(reg, pos)){
        cout << "------------------------------------\n"; // linea referencia
        cout << "Cliente dado de baja correctamente.\n";
    }
    else{
        cout << "------------------------------------\n"; // linea referencia
        cout << "No se pudo dar de baja al cliente.\n";
    }
}
