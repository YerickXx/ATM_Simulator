#include <iostream>
#include "declaracionesClases.h"
#include <limits>

/*
clase que controla el funcionamiento de los menus

se encarga tambien de invocar ciertas funciones de la clase ATM definida en la carpeta Headers
*/

int maxIntentos = 5;


void menu::menuOpcionesCajero(int option){ //funcion del menu de las opciones del cajero
    int subMenu = 0;
    int intentos = 0; // contador para determinar los intentos del usuario
    ATM cajero; // instancia de la clase ATM

    do {
        opcionesUsuario();  // solo muestra el menu
        std::cout << "Seleccione una opcion: ";

      while (!cajero.validacionEntrada(option)) { // invoca la funcion de validacion desarrollada en ATM{}
        std::cout << "Seleccione una opcion: ";
    }
        switch(option) { //switch case sobre las opciones del cajero
            case 1:
                cajero.verCuenta();
                break;
            case 2:
                cajero.retirarDinero();
                intentos++;// contador de las transacciones del usuario
                break;
            case 3:
                cajero.depositarDinero();
                intentos++; // contador de las transacciones del usuario
                break;
            case 4:
                cajero.historialTransacciones();
                break;
            case 5:
                std::cout << "Saliendo...\n";
                return;   // termina el menú y sale del programa
            default:
                std::cout << "Opcion invalida\n";
        }
        std::cout << "La consulta ha finalizado. Desea realizar algun otro proceso? |1.SI/2.NO| Seleccione una opcion: ";
        std::cin >> subMenu;
        while (!cajero.validacionEntrada(subMenu)) { // invoca la funcion de validacion desarrollada en ATM{}
        std::cout << "Seleccione una opcion: ";
    }

    } while(subMenu == 1 && intentos <= maxIntentos); // condicion del do..while
    std::cout << "Saliendo del programa...Usted solo puede realizar 5 operaciones entre retiros y depositos o bien digito la opcion 2 de no realizar mas operaciones.. Gracias\n";}

    void menu::opcionesUsuario(){ // funcion que se encarga de solo mostrar el menu
    std::cout << "================\n";
    std::cout << "MENU DE OPCIONES\n";
    std::cout << "================\n";
    std::cout << "1. Consultar saldo\n";
    std::cout << "2. Retirar dinero\n";
    std::cout << "3. Depositar dinero\n";
    std::cout << "4. Ver historial de transacciones\n";
    std::cout << "5. Salir\n";
}

