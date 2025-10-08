#include <iostream>
#include <vector>
#include "declaracionesClases.h"
using namespace std;

const vector<int> Pins = {1234, 4567, 2341, 8769}; // vector de almacenamiento de Pins de usuario
int attemps = 0;
int optionsPin = 0;
bool verifyPin = false; // estado de verificacion del pin
int option = 0;

int main()
{
    menu menuUsuario;
    do {
        std::cout << "============================================\n";
        std::cout << "BIENVENIDO AL SIMULADOR DE CAJERO AUTOMATICO\n";
        std::cout << "============================================\n";
        std::cout << "Por favor, ingrese su PIN (4 digitos): \n";

        if (!(cin >> optionsPin)) {
            cout << "El pin que ingresa debe ser un numerador valido intente de nuevo!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;  // Volver al inicio del bucle
        }

        verifyPin = false;  // Resetear para cada intento el estado

        for (int i = 0; i < Pins.size(); i++) { // recorrido del vecto de Pins de usuario
            if (Pins[i] == optionsPin) {
                verifyPin = true; // cambio de estado en caso del pin ingresado estar correcto

                menuUsuario.menuOpcionesCajero(option);  // llamado de la funcion de las opciones del cajero
                break;  // Salir del for una vez encontrado el pin
            }
        }

        // Verificacion de intentos de ingreso de PIN del usuario maximo 3
        if (!verifyPin) { // si el pin ingresado es incorrecto
            attemps++; // aumento de intentos
            std::cout << "El PIN ingresado no es correcto por favor intente nuevamente!\n";
            if (attemps >= 3) {
                std::cout << "Usted ha intentado ingresar el PIN de manera erronea demasiadas veces...Sistema bloqueado\n";
                break;
            }
        }
    } while (attemps < 3 && !verifyPin);

    return 0;
}
