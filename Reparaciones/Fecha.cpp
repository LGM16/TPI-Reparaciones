#include <iostream>
using namespace std;
#include "Fecha.h"

///Constructor

Fecha::Fecha(){
    establecerFechaDefecto();
}

Fecha::Fecha(int dia, int mes, int anio){

    if(validarFecha(dia,mes,anio))
    {
        _dia = dia;
        _mes = mes;
        _anio = anio;
    }
    else
    {
        establecerFechaDefecto();
    }
}

///Setters

void Fecha::setDia(int dia){
    _dia = dia;
}

void Fecha::setMes(int mes){
    _mes = mes;
}

void Fecha::setAnio(int anio){
    _anio = anio;
}

///Metodos

void Fecha::establecerFechaDefecto(){
    _dia = 1;
    _mes = 1;
    _anio = 1995;
}

int Fecha::obtenerCantDias(int mes, int anio){

    int maxDias;

    switch (mes){
    case 2: // Febrero
        if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
            maxDias = 29; // Bisiesto
        else
            maxDias = 28;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        maxDias = 30;
        break;

    default:
        maxDias = 31;
        break;
    }

    return maxDias;
}

bool Fecha::validarFecha(int dia, int mes, int anio){

    // Año válido
    if (anio < 1900 || anio > 2100 ){
        return false;
    }

    // Mes válido
    if (mes < 1 || mes > 12){
        return false;
    }

    // Día mínimo válido
    if (dia < 1){
        return false;
    }

    int maxDias;

    maxDias = obtenerCantDias(mes, anio);

    /*
    if(dia <= maxDias){
        return true;
    }
    else{
        return false;
    }
    */

    return dia <= maxDias; // Equivale al if comentado de arriba
}

string Fecha::toString(){

    string dia, mes, anio, fecha;
    dia = to_string(_dia);
    mes = to_string(_mes);
    anio = to_string(_anio);

    if(_dia < 10){
        if(_mes < 10){
            fecha = "0" + dia + "/" + "0" + mes + "/" + anio;
        }
        else{
            fecha = "0" + dia + "/" + mes + "/" + anio;

        }
    }
    else{  // si viene x else -> dia es > 10

        if(_mes < 10){
            fecha = dia + "/" + "0" + mes + "/" + anio;
        }
        else{
            fecha = dia + "/" + mes + "/" + anio;
        }
    }
    return fecha;
}

void Fecha::cargar(){

    int dia,mes,anio;

    do{

        cout << "Dia: ";
        cin >> dia;
        cout << "Mes: ";
        cin >> mes;
        cout << "Anio: ";
        cin >> anio;

        if(validarFecha(dia,mes,anio)){
            _dia = dia;
            _mes = mes;
            _anio = anio;

            break;
        }
        cout << "------------------------------------------------------\n"; // linea referencia
        cout << "Fecha invalida, intenta nuevamente. \n";
    }while(true);
}

void Fecha::mostrar()
{
    cout << "La fecha es: " << _dia << "/" << _mes << "/" << _anio << endl;
}
