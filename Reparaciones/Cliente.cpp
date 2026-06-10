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
    setEstado(true);
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
/*
// TODO ESTO (CARGAR Y MOSTRAR) VA EN MANAGER, NO EN LA CLASE
void Cliente::cargar(){

    int idCliente, tipoCliente;
    std::string telefono, email, direccion;

    Persona::cargar(); //falta _estado
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

*/

bool Cliente::validarTipoCliente(int tipoCliente){
    if(tipoCliente == 1 || tipoCliente == 2){
        return true;
    }
    return false;
}
