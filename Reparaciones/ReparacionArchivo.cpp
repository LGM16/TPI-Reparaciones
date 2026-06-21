#include "ReparacionArchivo.h"

///Constructor

ReparacionArchivo::ReparacionArchivo(){
    _ruta = "reparaciones.dat";
}

ReparacionArchivo::ReparacionArchivo(std::string ruta){
    _ruta = ruta;
}

///Getters

int ReparacionArchivo::getCantidadRegistros(){

    FILE *p = fopen(_ruta.c_str(), "rb");

    if(p == NULL){
        return 0;
    }

    fseek(p, 0, SEEK_END);

    int cantidadRegistros = ftell(p) / sizeof(Reparacion);

    fclose(p);
    return cantidadRegistros;
}

///Metodos

bool ReparacionArchivo::guardar(Reparacion reg){

    FILE *p = fopen(_ruta.c_str(), "ab");

    if(p == NULL){
        return false;
    }

    bool pudoEscribir = fwrite(&reg, sizeof(Reparacion), 1, p);

    fclose(p);
    return pudoEscribir;
}

bool ReparacionArchivo::guardar(Reparacion reg, int posicionReemplazada){

    FILE *p = fopen(_ruta.c_str(), "rb+");

    if(p == NULL){
        return false;
    }

    fseek(p, posicionReemplazada * sizeof(Reparacion), SEEK_SET);

    bool pudoEscribir = fwrite(&reg, sizeof(Reparacion), 1, p);

    fclose(p);
    return pudoEscribir;
}

bool ReparacionArchivo::guardar(Reparacion *vec, int cantidadRegistros){

    FILE *p = fopen(_ruta.c_str(), "ab");

    if(p == NULL){
        return false;
    }

    int registrosEscritos = fwrite(vec, sizeof(Reparacion), cantidadRegistros, p);

    fclose(p);
    return registrosEscritos == cantidadRegistros;
}

Reparacion ReparacionArchivo::leer(int posRegistro){

    Reparacion reg;

    FILE *p = fopen(_ruta.c_str(), "rb");

    if(p == NULL){
        return reg;
    }

    fseek(p, posRegistro * sizeof(Reparacion), SEEK_SET);
    fread(&reg, sizeof(Reparacion), 1, p);
    fclose(p);
    return reg;
}

void ReparacionArchivo::leerTodos(Reparacion *vec, int cantidadRegistros){

    FILE *p = fopen(_ruta.c_str(), "rb");

    if(p == NULL){
        return;
    }

    fread(vec, sizeof(Reparacion), cantidadRegistros, p);
    fclose(p);
}

int ReparacionArchivo::buscar(int id){

    int i, cantidadRegistros = getCantidadRegistros();

    Reparacion reg;

    for(i = 0; i < cantidadRegistros; i++){
        reg = leer(i);

        if(reg.getIdReparacion() == id){
            return i;
        }
    }
    return -1;
}
