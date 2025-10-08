#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <ctime>
#include "declaracionesClases.h"

std::map<std::string, int> transacciones; // map para almacenar las transacciones
std::stringstream ss; // variable para el formateo para ingresar los datos al map
int subMenu =0;
int retiro = 0;
int deposito = 0;
int saldo = 150000;

    void ATM::verCuenta(){ // funcion para que el usuario vea la cuenta
        time_t tiempoTransaccion; // para trabajar fecha y hora exacta de la transaccion
        std::time(&tiempoTransaccion);
        std::cout << "===============\n";
        std::cout << "Consultar Saldo\n";
        std::cout << "El saldo de su cuenta es de: " << saldo << " mil colones\n";
        ss << "Consulta de saldo ..Realizada: " << ctime(&tiempoTransaccion) << "monto: ";

        transacciones.insert({ss.str(),saldo}); // almacenamiento de la transaccion
      }

    void ATM::retirarDinero(){ // funcion para el retiro de dinero
        time_t tiempoTransaccion; // para trabajar fecha y hora exacta de la transaccion
        std::time(&tiempoTransaccion);
         std::cout << "================\n";
         std::cout << "Retiro de dinero\n";
         while (true) { //loop de validacion y almacenamiento de la transaccion
        std::cout << "Ingrese la cantidad que desea retirar: ";
        if (std::cin >> retiro && retiro > 0 && saldo > retiro) { //verificacion de que el input retiro sea mayor a cero y a la misma ves que sea una cantidad numerica valida
            saldo = saldo - retiro;
            std::cout << "Transaccion efectuada con exito el nuevo saldo de su cuenta es de: " << saldo << "\n";
             ss << "Retiro de dinero ..Realizado: " << ctime(&tiempoTransaccion) << "monto: ";
             transacciones.insert({ss.str(),retiro}); // almacenamiento de la transaccion
            break;//cantidad ingresada validada, se sale del loop
        } else {
            std::cout << "El dinero que desea retirar debe ser una cantidad valida mayor a 0 ademas su saldo debe ser mayor a la cantidad que desea retirar!.\n";
            std::cin.clear(); // limpia errores de cin
            std::cin.ignore(10000, '\n'); // descarta/elimina las cantidades erroneas
        }
    }
 }

    void ATM::depositarDinero(){ // funcion para el deposito de dinero
        time_t tiempoTransaccion;
        std::time(&tiempoTransaccion);
         std::cout << "===============\n";
         std::cout << "Ingresar Dinero\n";
        while (true) { //loop de validacion y almacenamiento de la transaccion
        std::cout << "Ingrese la cantidad que desea Depositar: ";
        if (std::cin >> deposito && deposito > 0) { //verificacion de que el input deposito sea mayor a cero y a la misma ves que sea una cantidad numerica valida
            saldo = saldo + deposito;
            std::cout << "Transaccion efectuada con exito el nuevo saldo de su cuenta es de: " << saldo << "\n";
             ss << "Deposito de dinero ..Realizado: " << ctime(&tiempoTransaccion) << "monto: ";
              transacciones.insert({ss.str(),deposito}); // almacenamiento de la transaccion en el map
            break; //cantidad ingresada validada, se sale del loop
        } else {
            std::cout << "El dinero que desea depositar debe ser una cantidad valida!\n";
            std::cin.clear(); // limpia errores de cin
            std::cin.ignore(10000, '\n'); // descarta/elimina las cantidades erroneas
        }
    }
}

    void ATM::historialTransacciones(){ // funcion para ver el historial del usuario
        time_t tiempoTransaccion;
        std::time(&tiempoTransaccion);
      if (!transacciones.empty()) { // verificacion de que haya algo en el map
       for (auto &transaccion : transacciones) { // recorrido del map usando auto para que automaticamente la funcion sepa que tipo debe usar para iterar
         std::cout << transaccion.first << " " << transaccion.second << "\n"; // mostrar al usuario las transacciones
    }}else {
       std::cout << "Usted no ha realizado transacciones aun!\n";} // se el map esta vacio mensaje de que no se han registrado transacciones
   }

   bool ATM::validacionEntrada(int &option){ // funcion validacion de opciones
            if (!(std::cin >> option)) {
            std::cout << "la opcion que debe ser un numero valido:\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            return false;
        }else{
          return true;
        }}




