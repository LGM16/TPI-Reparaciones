#include <iostream>
using namespace std;
#include "Fecha.h"

///Constructor

Fecha::Fecha(){
    _dia = 1;
    _mes = 1;
    _anio = 2023;
}

Fecha::Fecha(int dia, int mes, int anio){

    if(validarFecha(dia,mes,anio)){
        _dia = dia;
        _mes = mes;
        _anio = anio;
    }
    else{    
        _dia = 1;
        _mes = 1;
        _anio = 2023;
    }
}

///Setters

///Metodos

bool Fecha::validarFecha(int dia, int mes, int anio){
    
    // Año válido
    if (anio <= 0)
        return false;

    // Mes válido
    if (mes < 1 || mes > 12)
        return false;

    // Día mínimo válido
    if (dia < 1)
        return false;

    int maxDias;

    maxDias = obtenerCantDias(mes, anio);


    return dia <= maxDias;
}