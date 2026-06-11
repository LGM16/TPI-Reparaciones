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

    cout << "Ingrese los datos del cliente: " << endl;

    cout << "Tipo Cliente (1: Particular, 2: Empresa): ";
    cin >> tipoCliente;

    while(tipoCliente != 1 && tipoCliente != 2){
        cout << "Tipo invalido. Ingrese 1 (Particular) o 2 (Empresa): ";
        cin >> tipoCliente;
    }

    cout << "CUIT: ";
    cin >> cuit;

    if(tipoCliente == 1){
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Apellido: ";
        cin >> apellido;
    }
    else{
        cout << "Razon Social: ";
        cin >> nombre;
        apellido = "";
    }

    cout << "Telefono: ";
    cin >> telefono;

    cout << "Email: ";
    cin >> email;

    cout << "Direccion: ";
    cin >> direccion;

    Persona persona(cuit, nombre, apellido);
    Cliente nuevo(persona, idCliente, tipoCliente, telefono, email, direccion, true);

    if(_archivo.guardar(nuevo)){
        cout << "Cliente cargado con ID: " << idCliente << endl;
    }
    else{
        cout << "No se pudo guardar el cliente." << endl;
    }
}

void ClienteManager::listarClientes(){
    int cantidadRegistros = _archivo.getCantidadRegistros();

    if(cantidadRegistros == 0){
        cout << "No hay clientes cargados." << endl;
        return;
    }

    bool hayActivos = false;

    for(int i = 0; i < cantidadRegistros; i++){
        Cliente reg = _archivo.leer(i);

        if(reg.getEstado()){
            listar(reg);
            cout << "-------------------------" << endl;
            hayActivos = true;
        }
    }

    if(!hayActivos){
        cout << "No hay clientes activos." << endl;
    }
}

void ClienteManager::listarXId(){
    int id;
    cout << "Ingrese el ID del cliente: ";
    cin >> id;

    int pos = _archivo.buscar(id);

    if(pos == -1){
        cout << "No se encontro un cliente con ese ID." << endl;
        return;
    }

    Cliente reg = _archivo.leer(pos);
    listar(reg);
}

void ClienteManager::listar(Cliente cliente){
    cliente.mostrar();
}

void ClienteManager::darBajaCliente(){
    int id;
    cout << "Ingrese el ID del cliente a dar de baja: ";
    cin >> id;

    int pos = _archivo.buscar(id);

    if(pos == -1){
        cout << "No se encontro un cliente con ese ID." << endl;
        return;
    }

    Cliente reg = _archivo.leer(pos);

    if(!reg.getEstado()){
        cout << "El cliente ya se encuentra inactivo." << endl;
        return;
    }

    reg.setEstado(false);

    if(_archivo.guardar(reg, pos)){
        cout << "Cliente dado de baja correctamente." << endl;
    }
    else{
        cout << "No se pudo dar de baja al cliente." << endl;
    }
}
