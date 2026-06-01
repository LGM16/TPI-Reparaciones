#pragma once

class Fecha{
private:
    
    int _dia;
    int _mes;
    int _anio;

    void establecerFechaDefecto();
    int obtenerCantDias(int mes, int anio);
    bool validarFecha(int dia, int mes, int anio);

public:

    ///Constructores
    
    Fecha();
    Fecha(int dia, int mes, int anio);

    ///Setters

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    ///Getters

    int getDia(){return _dia;}
    int getMes(){return _mes;}
    int getAnio(){return _anio;}

    ///Metodos
    
    //void agregarDias(int dias); ?
    // agregar cargar() y mostrar() para no crear un manager?
};
