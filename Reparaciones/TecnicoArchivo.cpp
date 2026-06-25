#include "TecnicoArchivo.h"

///Constructor

TecnicoArchivo::TecnicoArchivo(){
    _ruta = "tecnicos.dat";
}

TecnicoArchivo::TecnicoArchivo(std::string ruta){
    _ruta = ruta;
}

///Getters

int TecnicoArchivo::getCantidadRegistros(){

    FILE *p = fopen(_ruta.c_str(), "rb"); //Lo abro nuevamente sabiendo que existe

    if(p == NULL){
        return 0;
    }

    fseek(p, 0, SEEK_END);  //Mueve el puntero al final del archivo

    int cantidadRegistros = ftell(p) / sizeof(Tecnico); //Devuelve la posicion actual del puntero

    fclose(p);
    return cantidadRegistros;
}

///Metodos

bool TecnicoArchivo::guardar(Tecnico reg){
    
    FILE *p = fopen(_ruta.c_str(), "ab");

    if(p == NULL){
        return false;
    }

    bool pudoEscribir = fwrite(&reg, sizeof(Tecnico), 1, p);

    fclose(p);
    return pudoEscribir;
}

bool TecnicoArchivo::guardar(Tecnico reg, int posicionReemplazada){

    FILE *p = fopen(_ruta.c_str(), "rb+");

    if(p == NULL){
        return false;
    }

    fseek(p, posicionReemplazada * sizeof(Tecnico), SEEK_SET); //Mueve el puntero a la posicion del registro a reemplazar

    bool pudoEscribir = fwrite(&reg, sizeof(Tecnico), 1, p);

    fclose(p);
    return pudoEscribir;
}

bool TecnicoArchivo::guardar(Tecnico *vec, int cantidadRegistros){

    FILE *p = fopen(_ruta.c_str(), "ab");

    if(p == NULL){
        return false;
    }

    int registrosEscritos = fwrite(vec, sizeof(Tecnico), cantidadRegistros, p);

    fclose(p);
    return registrosEscritos == cantidadRegistros;
}

Tecnico TecnicoArchivo::leer(int posRegistro){

    Tecnico reg;

    FILE *p = fopen(_ruta.c_str(), "rb");

    if(p == NULL){
        return reg;
    }

    fseek(p, posRegistro * sizeof(Tecnico), SEEK_SET); //Mueve el puntero a la posicion del registro a leer
    fread(&reg, sizeof(Tecnico), 1, p);
    fclose(p);
    return reg;
}

void TecnicoArchivo::leerTodos(Tecnico *vec, int cantidadRegistros){

    FILE *p = fopen(_ruta.c_str(), "rb");

    if(p == NULL){
        return;
    }

    fread(vec, sizeof(Tecnico), cantidadRegistros, p);
    fclose(p);
}

int TecnicoArchivo::buscar(int id){

    int i, cantidadRegistros = getCantidadRegistros();

    Tecnico reg;

    for(i = 0; i < cantidadRegistros; i++){
        reg = leer(i);

        if(reg.getIdTecnico() == id){
            return i;
        }
    }
    return -1;
}

void TecnicoArchivo::vaciar(){

    FILE *p = fopen(_ruta.c_str(), "wb");

    if(p == NULL){
        return;
    }
    fclose(p);
}