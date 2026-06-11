#include <cstring>
#include "ClienteArchivo.h"

///Constructor

ClienteArchivo::ClienteArchivo(){
    _ruta = "clientes.dat";
}

ClienteArchivo::ClienteArchivo(std::string ruta){
    _ruta = ruta;
}

///Setters

///Getters

int ClienteArchivo::getCantidadRegistros(){
    if(!existeArchivo()){
        return 0;
    }
    
    FILE *p = fopen(_ruta.c_str(), "rb"); //Lo abro nuevamente sabiendo que existe

    fseek(p, 0, SEEK_END);  //Mueve el puntero al final del archivo

    int cantidadRegistros = ftell(p) / sizeof(Cliente); //Devuelve la posicion actual del puntero
    
    fclose(p);
    return cantidadRegistros;
}

///Metodos

bool ClienteArchivo::existeArchivo(){
    FILE *p = fopen(_ruta.c_str(), "rb"); //Si el archivo no existe devuelve 0

    if(p == NULL){
        return false;
    }

    fclose(p);
    return true;
}

bool ClienteArchivo::guardar(Cliente reg){
    FILE *p = fopen(_ruta.c_str(), "ab");

    if(p == NULL){
        return false;
    }

    bool pudoEscribir = fwrite(&reg, sizeof(Cliente), 1, p);

    fclose(p);
    return pudoEscribir;
}

/*

bool ClienteArchivo::guardar(Cliente reg, int posicionReemplazada){
    FILE *p = fopen(_ruta.c_str(), "rb+");

    if(p == NULL){
        return false;
    }

    fseek(p, posicionReemplazada * sizeof(Cliente), SEEK_SET); //Mueve el puntero a la posicion del registro a reemplazar

    bool pudoEscribir = fwrite(&reg, sizeof(Cliente), 1, p);

    fclose(p);
    return pudoEscribir;
}
    
*/

bool ClienteArchivo::guardar(Cliente *vec, int cantidadRegistros){

    FILE *p = fopen(_ruta.c_str(), "ab");

    if(p == NULL){
        return false;
    }

    int registrosEscritos = fwrite(vec, sizeof(Cliente), cantidadRegistros, p);

    fclose(p);
    return registrosEscritos == cantidadRegistros;
}

Cliente ClienteArchivo::leer(int posRegistro){
    Cliente reg;

    FILE *p = fopen(_ruta.c_str(), "rb");

    if(p == NULL){
        return reg;
    }

    fseek(p, posRegistro * sizeof(Cliente), SEEK_SET); //Mueve el puntero a la posicion del registro a leer
    fread(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return reg;
}

void ClienteArchivo::leerTodos(Cliente *vec, int cantidadRegistros){
    FILE *p = fopen(_ruta.c_str(), "rb");

    if(p == NULL){
        return;
    }

    fread(vec, sizeof(Cliente), cantidadRegistros, p);
    fclose(p);
}

int ClienteArchivo::buscar(int id){
    int i, cantidadRegistros = getCantidadRegistros();
    Cliente reg;

    for(i = 0; i < cantidadRegistros; i++){
        reg = leer(i);

        if(reg.getIdCliente() == id){
            return i;
        }
    }
    return -1;
}