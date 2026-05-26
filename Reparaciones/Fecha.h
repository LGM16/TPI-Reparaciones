#pragma once

class Fecha{
private:
    
    int _dia;
    int _mes;
    int _anio;

public:

    //Constructores
    
    Fecha();

    //Setters

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    //Getters

    int getDia();
    int getMes();
    int getAnio();

    //Metodos

    bool validarFecha(int dia, int mes, int anio);
};
