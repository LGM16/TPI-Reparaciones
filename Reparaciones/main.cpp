/*
Reparación de equipamiento informático
Una empresa que se dedica a la reparación de equipos de informática lleva el registro
de los clientes, los equipos que repara y las reparaciones de equipos que realiza a los
clientes.

Por cada uno de los clientes registra el CUIT, el nombre, el apellido, un número de
teléfono, un email, la dirección y el tipo de cliente (1: particular; 2: empresa).

Para cada equipo se registra el número de equipo, la descripción del equipo, la marca,
el tipo de equipo, y la fecha en la que ingresó para su reparación. El número de equipo
es un código numérico que identifica de forma única a cada equipo. El tipo de equipo
se usa para saber si se trata de una PC de escritorio, una notebook, una impresora, un
periférico, etc.

En cuanto a cada una de las reparaciones, a la empresa le interesa registrar cuál es el
equipo que se reparó, a qué cliente lo hizo, cuál fue el día de la entrega y cuál fue el
importe de la reparación.

A partir de la descripción se pide:
●  Definir cuáles son los objetos que se necesitan para registrar la información
necesaria.
●  Para cada uno de los objetos, definir cuáles son las propiedades necesarias.
●  Definir el tipo de dato que corresponda para representar cada propiedad.

Luego determinar cuáles son las clases y cuáles son los archivos necesarios para el
sistema
*/



#include <iostream>
#include "Persona.h"
#include "Cliente.h"
//#include "Equipo.h"
//#include "Reparacion.h"

using namespace std;

int main() {
    //cout << "Hello, putaso! c:" << endl;
    /*
    Persona p;
    p.cargar();
    p.mostrar();
    */
    Cliente c;
    c.cargar();
    c.mostrar();
    return 0;
}

//Cliente: Puede obviarse la edad, suponiendo que al haber tipo particular o empresar, se puede inferir la edad.
// Preguntar si el CUIT seria equivalente a un id unico (o un id autoincremental).
//Tecnico: Se puede obviar, suponiendo que la empresa tiene tecnicos fijos, o no es relevante para el sistema, tambien podria incluirse
//Los técnicos serán los encargados de realizar las reparaciones. De cada técnico se registrará el legajo, apellido, nombre, teléfono y especialidad.
