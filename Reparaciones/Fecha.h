#pragma once

class Fecha{
private:
    
    int _dia;
    int _mes;
    int _anio;

public:

    ///Constructores
    
    Fecha();
    Fecha(int dia, int mes, int anio);

    ///Setters

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    ///Getters

    int getDia();
    int getMes();
    int getAnio();

    ///Metodos

    int obtenerCantDias(int mes, int anio);
    bool validarFecha(int dia, int mes, int anio);
};
