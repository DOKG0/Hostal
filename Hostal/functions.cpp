#include <iostream>
#include <string>
#include "header.h"

//using namespace std;

void clearBuffer(){
    char aux;
    while ((aux = getchar()) != '\n' && aux != EOF){
        //Nada, limpia buffer
    }
}

void printTitle(std::string mensaje){
    system("clear");

    std::cout << "x      x      xxx    xxxxxxxx   xxxxxxxx   xxxxxxxx    x" << std::endl;
    std::cout << "x      x     x   x   xx            xx      xx          x" << std::endl;
    std::cout << "x      x    x     x  xx            xx      xx          x" << std::endl;
    std::cout << "xxxxxxxx    x     x  xxxxxxxx      xx      xxxxxxxx    x" << std::endl;
    std::cout << "x      x    x     x        xx      xx      xx          x" << std::endl;
    std::cout << "x      x     x   x         xx      xx      xx          x" << std::endl;
    std::cout << "x      x      xxx    xxxxxxxx      xx      xxxxxxxx    xxxxxxxx" << std::endl;

    std::cout << "\n\n" << std::endl;
    std::cout << mensaje << '\n' << std::endl;
}

void printMenu(){
    std::cout << "1 - Agregar Huesped" << std::endl;
    std::cout << "2 - Agregar Habitacion" << std::endl;
    std::cout << "3 - Obtener Huesped" << std::endl;
    std::cout << "4 - Obtener Habitacion" << std::endl;
    std::cout << "5 - Registrar Reserva" << std::endl;
    std::cout << "6 - Obtener Reservas" << std::endl;
    std::cout << "7 - Salir" << std::endl;
    std::cout << '\n' << std::endl;
}

int obteneropcion(){
    //Obtengo opcion de menu
    std::cout << "--> ";
    int opcion = 0;
    std::cin >> opcion;
    
    clearBuffer();
    
    return opcion;
}

std::string obtenerNombre(){
    std::string nombre;

    std::cout << "Ingrese nombre: ";
    std::cin >> nombre;

    clearBuffer();

    return nombre;
}

std::string obtenerEmail(){
    std::string email;

    std::cout << "Ingrese email: ";
    std::cin >> email;

    clearBuffer();

    return email;
};

bool obtenerFinger(){
    int auxiliar;
 
    std::cout << "¿Es finger? 1 = Si| 2 = No" <<std::endl;
    std::cin >> auxiliar;

    clearBuffer();

    if (auxiliar == 1){
        return true;
    }
    return false;
}

bool obtenerPagado(){
    int auxiliar;

    std::cout << "¿Ya pago la reserva? 1 = Si | 2 = No" <<std::endl;
    std::cin >> auxiliar;

    clearBuffer();

    if(auxiliar == 1){
        return true;
    }
    return false;
}

int obtenerNumeroHabitacion(){
    int habitacion;

    std::cout << "Ingrese numero de habitacion: ";
    std::cin >> habitacion;

    clearBuffer();

    return habitacion;
}

int obtenerPrecio(){
    float precio;

    std::cout << "Ingrese precio de la habitacion: ";
    std::cin >> precio;

    clearBuffer();

    return precio;
}

int obtenerCapacidad(){
    int capacidad;

    std::cout << "Ingrese capacidad de la habitacion: ";
    std::cin >> capacidad;

    clearBuffer();

    return capacidad;
}

int pedirDia(){
    int dia;

    std::cout << "Ingrese dia de la reserva (valores 1 a 31): ";
    std::cin >> dia;

    clearBuffer();

    if (dia < 1 or 31 < dia){
        throw std::invalid_argument("El valor de dia ingresado es invalido, favor de leer");
    }

    return dia;
}

int pedirMes(){
    int mes;
    std::cout << "Ingrese mes de la reserva (valores 1 a 12): ";
    std::cin >> mes;

    clearBuffer();

    if (mes < 1 or 12 < mes){
        throw std::invalid_argument("El valor de mes ingresado es invalido, favor de leer");
    }

    return mes;
} 

int pedirAnio(){
    int Anio;

    std::cout << "Ingrese año de la reserva (valores mayores o igual a 1900): ";
    std::cin >> Anio;

    clearBuffer();

    if (1899 > Anio){
        throw std::invalid_argument("El valor de año ingresado es invalido, favor de leer");
    }

    return Anio;
}

DTFecha pedirFecha(){
    try{
        DTFecha *fecha = new DTFecha(pedirDia(), pedirMes(), pedirAnio());
        return *fecha;
    }
    catch (std::invalid_argument& err){
        std::cout << err.what();
        system("read");
    }
};

std::string Fingersino(bool esFinger){
    if(esFinger){
        return "si";
    }
    return "no";
}

int mostrarHuespedes(DTHuesped** huespedes, int cantidad){
    //lista de huespedes
    DTHuesped * huespedesptr = new DTHuesped();
    
    for(int i = 0; i < cantidad; i++){
        huespedesptr = huespedes[i];
        std::cout << "----------------------------" << std::endl;
        //std::cout << "Huesped nro: " << i << std::endl;
        std::cout << "Nombre: " << huespedes[i]->getNombre() << std::endl;
        std::cout << "Email: " << huespedes[i]->getEmail() << std::endl;
        std::cout << "Finger: " << Fingersino(huespedes[i]->getEsFinger()) << std::endl;
    }

    delete huespedesptr;
}

int mostrarHabitaciones(DTHabitacion** habitaciones, int cantidad){
    //lista de habitaciones
    DTHabitacion * habitacionptr = new DTHabitacion();
    
    for(int i=0; i<cantidad; i++){

        habitacionptr = habitaciones[i];
        std::cout << "----------------------------" << std::endl;
        std::cout << "Numero: " << habitaciones[i]->getNumero() << std::endl;
        std::cout << "Precio: " << habitaciones[i]->getPrecio() << std::endl;
        std::cout << "Capacidad: " << habitaciones[i]->getCapacidad() << std::endl;
    }
    pause();
    delete habitacionptr;
};

void pause(){
    std::cout << "Press enter to continue...";
    std::cin.get();
};
