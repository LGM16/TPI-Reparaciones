#include "Cliente.h"

///Constructores

Cliente::Cliente()
    : Persona("", "", ""),
      _idCliente(0),
      _tipoCliente(0),
      _telefono(""),
      _email(""),
      _direccion(""),
      _estado(true)
{
}

Cliente::Cliente(Persona persona, int idCliente, int tipoCliente, std::string telefono,
                 std::string email, std::string direccion, bool estado)
    : Persona(persona.getCuit(), persona.getNombre(), persona.getApellido()),
      _idCliente(idCliente),
      _estado(estado)
{
    setTipoCliente(tipoCliente);
    setTelefono(telefono);
    setEmail(email);
    setDireccion(direccion);
}

///Setters

void Cliente::setIdCliente(int idCliente){
        _idCliente = idCliente;
}

void Cliente::setTipoCliente(int tipoCliente){

    if(tipoCliente == 1 || tipoCliente == 2){
        _tipoCliente = tipoCliente;
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

void Cliente::setTelefono(std::string telefono){
    if(telefono.length() >= 8 && telefono.length() <= 15){ //idem .size()
        _telefono = telefono;
    }
}

void Cliente::setEmail(std::string email){
    if(email.find('@') != std::string::npos){ // busca el caracter '@' en la cadena email, si lo encuentra devuelve la posición, sino devuelve std::string::npos
        _email = email;
    }
}

void Cliente::setDireccion(std::string direccion){
    _direccion = direccion;
}

void Cliente::setEstado(bool estado){
    _estado = estado;
}

///Metodos

void Cliente::mostrar(){
    cout << "ID del Cliente: " << getIdCliente() << endl;
    cout << "CUIT: " << getCuit() << endl;

    if(getTipoCliente() == 1){
        cout << "Tipo de Cliente: Particular" << endl;
        cout << "Nombre: " << getNombre() << endl;
        cout << "Apellido: " << getApellido() << endl;
    }
    else{
        if(getTipoCliente() == 2){
            cout << "Tipo de Cliente: Empresa" << endl;
            cout << "Razon Social: " << getNombre() << endl;
        }
    }

    cout << "Telefono de Cliente: " << getTelefono() << endl;
    cout << "Email de Cliente: " << getEmail() << endl;
    cout << "Direccion de Cliente: " << getDireccion() << endl;
}

*/

bool Cliente::validarTipoCliente(int tipoCliente){
    if(tipoCliente == 1 || tipoCliente == 2){
        return true;
    }
    return false;
}
