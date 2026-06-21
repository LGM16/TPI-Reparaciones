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

    FILE *P = fopen(_ruta.c_str(), "ab");

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

    bool pudoEscribir = fwrite(&reg, sizeof(Equipo, 1, p));

    fclose(p);
    return pudoEscribir;
}