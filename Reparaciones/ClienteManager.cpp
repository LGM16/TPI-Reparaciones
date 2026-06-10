#include <iostream>
#include "ManagerCliente.h"

using namespace std;

///Constructor

///Setters

///Metodos

void ManagerCliente::cargarCliente(){

    string cuit, nombre, apellido;
    int idCliente, tipoCliente;
    bool estado;
    
    cout << "Ingrese los datos del cliente: " << endl;

    cout << "CUIT: ";
    cin >> cuit;

    cout << "Nombre: ";
    cin >> nombre;

    cout << "Apellido: ";
    cin >> apellido;

    cout << "ID Cliente: ";

    cout << "Tipo Cliente (1: Particular, 2: Empresa): ";
    cin >> tipoCliente;

    bool estadoValido = true;

}

