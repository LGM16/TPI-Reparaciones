#include "EquipoArchivo.h"

///Constructor

EquipoArchivo::EquipoArchivo(){
    _ruta = "equipos.dat";
}

EquipoArchivo::EquipoArchivo(std::string ruta){
    _ruta = ruta;
}

///Getters

int EquipoArchivo::getCantidadRegistros(){

    FILE *p = fopen(_ruta.c_str(), "rb");

    if(p == NULL){
        return 0;
    }

    fseek(p, 0, SEEK_END);  //Mueve el puntero al final del archivo

    int cantidadRegistros = ftell(p) / sizeof(Equipo);

    fclose(p);
    return cantidadRegistros;
}

///Metodos

bool EquipoArchivo::guardar(Equipo reg){

    FILE *p = fopen(_ruta.c_str(), "ab");

    if(p == NULL){
        return false;
    }

    bool pudoEscribir = fwrite(&reg, sizeof(Equipo), 1, p);

    fclose(p);
    return pudoEscribir;
}

bool EquipoArchivo::guardar(Equipo reg, int posicionReemplazada){

    FILE *p = fopen(_ruta.c_str(), "rb+");

    if(p == NULL){
        return false;
    }

    fseek(p, posicionReemplazada * sizeof(Equipo), SEEK_SET);

    bool pudoEscribir = fwrite(&reg, sizeof(Equipo), 1, p);

    fclose(p);
    return pudoEscribir;
}

bool EquipoArchivo::guardar(Equipo *vec, int cantidadRegistros){

    FILE *p = fopen(_ruta.c_str(), "ab");

    if(p == NULL){
        return false;
    }

    int registrosEscritos = fwrite(vec, sizeof(Equipo), cantidadRegistros, p);

    fclose(p);
    return registrosEscritos == cantidadRegistros;
}

Equipo EquipoArchivo::leer(int posRegistro){

    Equipo reg;

    FILE *p = fopen(_ruta.c_str(), "rb");

    if(p == NULL){
        return reg;
    }

    fseek(p, posRegistro * sizeof(Equipo), SEEK_SET);
    fread(&reg, sizeof(Equipo), 1, p);
    fclose(p);
    return reg;
}

void EquipoArchivo::leerTodos(Equipo *vec, int cantidadRegistros){

    FILE *p = fopen(_ruta.c_str(), "rb");

    if(p == NULL){
        return;
    }

    fread(vec, sizeof(Equipo), cantidadRegistros, p);
    fclose(p);
}

int EquipoArchivo::buscar(int id){

    int i, cantidadRegistros = getCantidadRegistros();

    Equipo reg;

    for(i = 0; i < cantidadRegistros; i++){
        reg = leer(i);

        if(reg.getIdEquipo() == id){
            return i;
        }
    }
    return -1;
}