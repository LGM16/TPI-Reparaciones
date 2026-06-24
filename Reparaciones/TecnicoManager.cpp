#include <iostream>
#include "TecnicoManager.h"

using namespace std;

///Constructor

TecnicoManager::TecnicoManager(){
}

///Metodos

int TecnicoManager::generarId(){

    int cantidadRegistros = _archivo.getCantidadRegistros();

    if(cantidadRegistros == 0){
        return 1;
    }

    int maxId = 0;
    Tecnico reg;

    for(int i = 0; i < cantidadRegistros; i++){
        reg = _archivo.leer(i);

        if(reg.getIdTecnico() > maxId){
            maxId = reg.getIdTecnico();
        }
    }
    return maxId + 1;
}

bool TecnicoManager::existeId(int id){
    return _archivo.buscar(id) != -1;
}

bool TecnicoManager::existeUsuario(string usuario){

    int cantidadRegistros = _archivo.getCantidadRegistros();

    for(int i = 0; i < cantidadRegistros; i++){
        Tecnico reg = _archivo.leer(i);

        if(reg.getIdTecnico() > 0 && reg.getUsuario() == usuario){
            return true;
        }
    }
    return false;
}

bool TecnicoManager::hayTecnicos(){
    return _archivo.getCantidadRegistros() > 0;
}

bool TecnicoManager::crearTecnico(Tecnico& tecnicoCreado){

    string nombre, apellido, usuario, contrasenia;

    int idTecnico = generarId();

    cout << "Ingrese los datos del tecnico: " << endl;

    cout << "Nombre: ";
    cin >> nombre;

    cout << "Apellido: ";
    cin >> apellido;

    cout << "Usuario: ";
    cin >> usuario;

    if(existeUsuario(usuario)){
        cout << "El usuario ya existe. Elija otro." << endl;
        return false;
    }

    cout << "Contrasenia: ";
    cin >> contrasenia;

    Persona persona("", nombre, apellido);
    Tecnico nuevo(persona, idTecnico, usuario, contrasenia);

    if(_archivo.guardar(nuevo)){
        cout << "Tecnico creado con ID: " << idTecnico << endl;
        tecnicoCreado = nuevo;
        return true;
    }
    else{
        cout << "No se pudo guardar el tecnico." << endl;
        return false;
    }
}

void TecnicoManager::listarTecnicos(){

    int cantidadRegistros = _archivo.getCantidadRegistros();

    bool hayRegistrosValidos = false;
    bool hayActivos = false;

    ///Esta validacion sobra, si no existe el .dat lo tenes que crear para logearte
    if(cantidadRegistros == 0){
        cout << "\nNo hay tecnicos cargados.\n";
        return;
    }

    for(int i = 0; i < cantidadRegistros; i++){
        Tecnico reg = _archivo.leer(i);

        if(reg.getIdTecnico() > 0){

            hayRegistrosValidos = true;

            if(reg.getEstado()){

                listar(reg);
                cout << "-----------------------------------\n";

                hayActivos = true;
            }
        }
    }

    if(!hayRegistrosValidos){
        cout << "\nNo hay tecnicos cargados.\n";
    }
    else{
        if(!hayActivos){
            cout << "\nNo hay tecnicos activos.\n";
        }
    }
}

void TecnicoManager::listarXId(){

    int id, pos;

    Tecnico reg;

    cout << "Ingrese el ID del tecnico: ";
    cin >> id;

    pos = _archivo.buscar(id);

    if(pos == -1){
        cout << "No se encontro un tecnico con el ID ingresado." << endl;
        return;
    }

    reg = _archivo.leer(pos);
    listar(reg);
}

void TecnicoManager::listar(Tecnico tecnico){

    cout << "ID: " << tecnico.getIdTecnico() << endl;
    cout << "Nombre: " << tecnico.getNombre() << endl;
    cout << "Apellido: " << tecnico.getApellido() << endl;
    cout << "Usuario: " << tecnico.getUsuario() << endl;
    //cout << "Estado: " << (tecnico.getEstado() ? "Activo" : "Inactivo") << endl; operador ternario?
    if(tecnico.getEstado()){
        cout << "Estado: Activo" << endl;
    }
    else{
        cout << "Estado: Inactivo" << endl;
    }
}

void TecnicoManager::darBajaTecnico(){

    int id, pos;

    Tecnico reg;

    cout << "Ingrese el ID del tecnico a dar de baja: ";
    cin >> id;

    pos = _archivo.buscar(id);

    if(pos == -1){
        cout << "No se encontro un tecnico con el ID ingresado." << endl;
        return;
    }

    reg = _archivo.leer(pos);

    if(!reg.getEstado()){
        cout << "El tecnico ya se encuentra inactivo." << endl;
        return;
    }

    reg.setEstado(false);

    if(_archivo.guardar(reg, pos)){
        cout << "Tecnico dado de baja exitosamente." << endl;
    }
    else{
        cout << "No se pudo dar de baja el tecnico." << endl;
    }
}

bool TecnicoManager::validarCredenciales(string usuario, string contrasenia, Tecnico& tecnico){

    int cantidadRegistros = _archivo.getCantidadRegistros();

    for(int i = 0; i < cantidadRegistros; i++){
        Tecnico reg = _archivo.leer(i);

        if((reg.getIdTecnico() > 0 && reg.getEstado()) && (reg.getUsuario() == usuario && reg.getContrasenia() == contrasenia)){
            tecnico = reg;
            return true;
        }
    }
    return false;
}
