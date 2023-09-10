#include <iostream>
#include <string.h>
#include "header.h"
#include "Sistema.h"

using namespace std;

int main (int argc, char *argv[]){

    int opcion = 0; //Marca la opcion del menu
    cout<< "Algo" << endl;

    int *cantidad = new int(); //Entero que maneja las cantidades de los arreglos recibidos por parametro
    cout<< "algo2"  << endl;

    Sistema *Hotel = new Sistema(); //Abro el hotel
    cout<< "algo3"  << endl;

    //Iteracion del menu

    DTHuesped ** huespedes = new DTHuesped*[MAX_HUESPEDES];
    DTHabitacion ** habitaciones = new DTHabitacion*[MAX_HABITACIONES];

    do {
        *cantidad = 0;
        printTitle("Menu");
        printMenu(); 

        opcion = obteneropcion();
        string email;

        switch (opcion){
            case 1: 
                try{
                    string nombre = obtenerNombre();
                    string email = obtenerEmail();
                    bool finger = obtenerFinger();
                    Hotel->agregarHuesped(nombre, email, finger);
                    cout << "El huesped fue agregado con exito\n";
                }
                catch (std::invalid_argument& err){
                    cout << err.what();
                }
                pause();
                break;
            case 2: 
                try {
                    Hotel->agregarHabitacion(obtenerNumeroHabitacion(), obtenerPrecio(), obtenerCapacidad());
                    cout << "La habitacion fue agregada con exito";
                }
                catch (std::invalid_argument& err){
                    cout << err.what();
                }
                pause();
                break;
            case 3:
                try{
                    huespedes = Hotel->obtenerHuespedes(*cantidad);
                    mostrarHuespedes(huespedes, *cantidad);
                }
                catch (std::invalid_argument& err){
                    cout << err.what();
                }
                pause();
                break;
            case 4: 
                try{
                    habitaciones = Hotel->obtenerHabitaciones(*cantidad);
                    mostrarHabitaciones(habitaciones, *cantidad);
                }
                catch (std::invalid_argument& err){
                    cout << err.what();
                }
                pause();
                break;
            case 5: 
                try{
                    email = obtenerEmail();
                    Hotel->registrarReserva(email, Hotel->armarReserva(email));
                }
                catch (std::invalid_argument& err){
                    cout << err.what();
                }
                pause();
                break;
            case 6: 
                //mostrarReservas(Hotel->obtenerReservas(pedirFecha(), *cantidad));
                cout << "NO IMPLEMENTADA" << endl;
                pause();
                break;
            case 7: 

                break;
            default:
                cout << "\nLa opcion ingresada es invalida" << endl;
                system("read");
        }


    } while (opcion != 7);

    delete Hotel; //Cierro el hotel

    return 0;
}