#ifndef DECLARACIONESCLASES_H_INCLUDED
#define DECLARACIONESCLASES_H_INCLUDED

/*
Header que define las clases que se usaran y sus metodos ademas de crear 2 instancias de objeto de cada clase

ATM{} clase encargada de desarrollar las funcionalidades del cajero
menu{} clase encargada de ejecutar todas las funciones del menu principal y los submenus

*/

class ATM { //declaracion de la clase ATM que contiene las funciones del cajero
public:
    void verCuenta();
    void retirarDinero();
    void depositarDinero();
    void historialTransacciones();
    bool validacionEntrada(int &option);
};


class menu { //declaracion de la clase menu que contiene el funcionamiento de los menus
public:
    void menuOpcionesCajero(int option);
    void opcionesUsuario();
};

extern ATM cajero;

extern menu Principal;

#endif // DECLARACIONESCLASES_H_INCLUDED
