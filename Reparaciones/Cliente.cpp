#include <iostream>
using namespace std;
#include "Cliente.h"

//Constructores

Cliente::Cliente(){
    setIdCliente(1);
    setTipoCliente(1);
    setTelefono("");
    setEmail("");
    setDireccion("");
    setEstado(true);
}

//Setters

void Cliente::setIdCliente(int idCliente){
    
    if(idCliente > 0){
        _idCliente = idCliente;
    }
    else{
        _idCliente = 1;
    }
}

void Cliente::setTipoCliente(int tipoCliente){

    if(tipoCliente == 1 || tipoCliente == 2){
        _tipoCliente = tipoCliente;
    }
    else{
        _tipoCliente = 1;
    }

    /*
    if(validarTipoCliente(tipoCliente)){
        _tipoCliente = tipoCliente;
    }
    else{
        _tipoCliente = 1;
    }
    */

}

void Cliente::setTelefono(string telefono){
    if(telefono.length() >= 8 && telefono.length() <= 15){ //idem .size()
        _telefono = telefono;
    }
    else{
        _telefono = "";
    }
}

void Cliente::setEmail(string email){
    if(email.find('@') != string::npos){ // busca el caracter '@' en la cadena email, si lo encuentra devuelve la posición, sino devuelve string::npos
        _email = email;
    }
    else{
        _email = "";
    }
}

void Cliente::setDireccion(string direccion){
    _direccion = direccion;
}

void Cliente::setEstado(bool estado){
    _estado = estado;
}

//Metodos

void Cliente::cargar(){

    int idCliente, tipoCliente;
    string telefono, email, direccion;

    Persona::cargar();
    // aca puedo hacer una metodo para incrementar el idCliente automaticamente verificando el ultimo cargado
    //implementar do while en cada carga para validar cada dato ingresado?
    cout << "Ingrese el ID del Cliente: " << endl;
    cin >> idCliente;
    setIdCliente(idCliente);
    cout << "Ingrese el tipo de Cliente (1: Particular, 2: Empresa): " << endl;
    cin >> tipoCliente;
    setTipoCliente(tipoCliente);
    cout << "Ingrese el telefono del Cliente: " << endl;
    cin >> telefono;
    setTelefono(telefono);
    cout << "Ingrese el email del Cliente: " << endl;
    cin >> email;
    setEmail(email);
    cout << "Ingrese la direccion del Cliente: " << endl;
    cin >> direccion;
    setDireccion(direccion);
}

// TODO ESTO (CARGAR Y MOSTRAR) VA EN MANAGER, NO EN LA CLASE
void Cliente::mostrar(){
    Persona::mostrar();
    cout << "ID del Cliente: " << getIdCliente() << endl;

    if(getTipoCliente() == 1){
        cout << "Tipo de Cliente: Particular" << endl;
    }
    else{
        if(getTipoCliente () == 2){
            cout << "Tipo de Cliente: Empresa" << endl;
        }
    }

    cout << "Telefono de Cliente: " << getTelefono() << endl;
    cout << "Email de Cliente: " << getEmail() << endl;
    cout << "Direccion de Cliente: " << getDireccion() << endl;
}

bool Cliente::validarTipoCliente(int tipoCliente){
    if(tipoCliente == 1 || tipoCliente == 2){
        return true;
    }
    return false;
}
