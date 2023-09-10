#include <iostream>
#include <string>
#include "Sistema.h"

int codigoReserva = 0; //Variable global de Codigos de Reserva

//Constructores
Sistema::Sistema(){};

Sistema::Sistema(Huesped **Huespedes, Habitacion **Habitaciones, ReservaIndividual** ReservasIndividuales, ReservaGrupal** ReservasGrupales){
    this->Huespedes = Huespedes;
    this->Habitaciones = Habitaciones;
    this->ReservasGrupales = ReservasGrupales;
    this->ReservasIndividuales = ReservasIndividuales;
};

Sistema::~Sistema() = default;

void Sistema::agregarHuesped(std::string nombre, std::string email, bool esFinger){
    if (!existeHuesped(email)){
        Huesped *Huesped1 = new Huesped(nombre, email, esFinger);

        Huesped *HuespedPtr = new Huesped();        
        HuespedPtr = this->Huespedes[0];

        int cantidad = 0;

        while (HuespedPtr != NULL){
            cantidad++;
            HuespedPtr = this->Huespedes[cantidad];
        }
        this->Huespedes[cantidad] = Huesped1;

        return;
    }
    
    throw std::invalid_argument("El huesped ya existe registrado");
};

void Sistema::agregarHabitacion(int numero, float precio, int capacidad){
    if (!existeHabitacion(numero)){
        Habitacion *Habitacion1 = new Habitacion(numero, precio, capacidad);
        Habitacion *HabitaciondPtr = new Habitacion();

        HabitaciondPtr = this->Habitaciones[0];
        int cantidad = 0;

        while (HabitaciondPtr != NULL){
            cantidad++;
            HabitaciondPtr = this->Habitaciones[cantidad];
        }

        this->Habitaciones[cantidad] = Habitacion1;
        return;
    }

    throw std::invalid_argument("La habitacion ingresada ya existe");
};

DTHuesped** Sistema::obtenerHuespedes(int& cantHuepedes){
    cantHuepedes = 0;
    Huesped *HuespedPtr = new Huesped();
    HuespedPtr = this->Huespedes[0];

    while (HuespedPtr != NULL){
        cantHuepedes++;
        HuespedPtr = this->Huespedes[cantHuepedes];
    }

    DTHuesped** huespedes = new DTHuesped*[cantHuepedes]();
    
    for (int i = 0; i<cantHuepedes; i++){
        huespedes[i] = new DTHuesped(this->Huespedes[i]->getNombre(),this->Huespedes[i]->getEmail(), this->Huespedes[i]->getEsfinger());
    }

    return huespedes;
};

DTHabitacion** Sistema::obtenerHabitaciones(int& cantHabitaciones){

    cantHabitaciones = 0;
    Habitacion *HabitacionesPtr = new Habitacion();
    HabitacionesPtr = this->Habitaciones[0];

    while (HabitacionesPtr != NULL){
        cantHabitaciones++;
        HabitacionesPtr = this->Habitaciones[cantHabitaciones];
    }

    DTHabitacion** Habitaciones = new DTHabitacion*[cantHabitaciones]();
    
    for (int i = 0; i<cantHabitaciones; i++){
        Habitaciones[i] = new DTHabitacion(this->Habitaciones[i]->getNumero(),this->Habitaciones[i]->getPrecio(), this->Habitaciones[i]->getCapacidad());
    }

    return Habitaciones;
};

DTReserva** Sistema::obtenerReservas(DTFecha fecha, int& cantReservas){
    ReservaGrupal* reservasPtr = new ReservaGrupal();
    cantReservas = 0;
    int cantAux = 0;

    reservasPtr = this->ReservasGrupales[0];

/*  while(reservasPtr != NULL){
        if(validarReservaFecha(reservasPtr->getCheckIN(), reservasPtr->getCheckOUT(), fecha)){
            
        }
    }
*/
};

DTReserva* Sistema::armarReserva(std::string email){
    if (!existeHuesped(email)){
        throw std::invalid_argument("El huesped no se ha registrado");
    }
    
    printTitle("Seleccion de Habiacion");
    int habitacion = obtenerNumeroHabitacion();

    if (!existeHabitacion(habitacion)){
        throw std::invalid_argument("La habitacion ingresada no existe");
    }
    
    printTitle("Fecha de CheckIn");
    int diaIN  = pedirDia();
    printTitle("Fecha de CheckIn");
    int mesIN  = pedirMes();
    printTitle("Fecha de CheckIn");
    int anioIN = pedirAnio();
    
    printTitle("Fecha de CheckOut");
    int diaOUT  = pedirDia();
    printTitle("Fecha de CheckOut");
    int mesOUT  = pedirMes();
    printTitle("Fecha de CheckOut");
    int anioOUT = pedirAnio();

    DTFecha* fechaIN = new DTFecha(diaIN, mesIN, anioIN);
    DTFecha* fechaOUT = new DTFecha(diaOUT, mesOUT, anioOUT);
    /*
    if (HayReservaParaHabitacion(fechaIN, fechaOUT, habitacion)){
        delete fechaIN;
        delete fechaOUT;
        throw std::invalid_argument("La habitacion ya esta reservada para la fecha");
    }*/

    Reserva* reserva = new Reserva();
    //Lo busco y guardo su info
    reserva->setHuesped(encontrarHuesped(email));
    //Lo busco y lo guardo
    reserva->setHabitacion(encontrarHabitacion(habitacion));
    //Fecha de CheckIN
    reserva->setCheckIN(*fechaIN);
    //Fecha de CheckOUT
    reserva->setCheckOUT(*fechaOUT);

    delete fechaIN;
    delete fechaOUT;
    reserva->setEstado(Abierta);

    codigoReserva++;
    DTReserva* ReservaDT = new DTReserva(codigoReserva, reserva->getCheckIN(), reserva->getCheckOUT(), reserva->getEstado(), reserva->calcularCosto(), reserva->getHabitacion(), reserva->getHuesped());
    
    delete reserva;
    return ReservaDT;
};  

bool Sistema::existeHuesped(std::string email){

    DTHuesped **Huespedes = new DTHuesped*();
    int cant = 0;

    Huespedes = this->obtenerHuespedes(cant);
    
    for (int i = 0; i < cant; i++){

        if (email.compare(Huespedes[i]->getEmail()) == 0){

            delete Huespedes;
            return true;
        }
    } 
    delete Huespedes;
    return false;
}

void Sistema::registrarReserva(std::string email, DTReserva* reserva){
    int var = 3;
    std::cout << "1 - Reserva Grupal"<< std::endl;
    std::cout << "2 - Reserva Individual" << std::endl;
    std::cout << "3 - Volver al menu" << std::endl;
    std::cin >> var;

    while(var != 1 && var != 2 && var != 3){
        std::cout << "La opcion introducida es incorrecta." << std::endl;
        pause();
        system("clear");
        printTitle("Registrar Reserva");
        std::cout << "1 - Reserva Grupal"<< std::endl;
        std::cout << "2 - Reserva Individual" << std::endl;
        std::cin >> var;   
    }

    if (var == 1){ //Reserva Grupal
        int opcion = 0, cant = 0;
        DTHuesped** Huespedes = new DTHuesped*[MAX_HUESPEDES]();
        std::string email2;

        Huespedes[cant] = encontrarHuesped(email);
        cant++;

        do{
            printTitle("Registrar Reserva Grupal");
            std::cout << "Ingrese el siguiente Huesped: "<< std::endl;
            email2 = obtenerEmail();
            
            if (!existeHuesped(email2)){
                throw std::invalid_argument("El huesped no se encuentra registrado");
            }

            Huespedes[cant] = encontrarHuesped(email2);
            cant++;

            printTitle("Registrar Reserva Grupal");
            std::cout << "1 - Ingresar Huesped"<< std::endl;
            std::cout << "2 - Terminar Reserva" << std::endl;
            std::cin >> opcion;

        }while(opcion != 2);

        ReservaGrupal *reservaGrupal = new ReservaGrupal(reserva->getCodigo(), reserva->getCheckin(), reserva->getCheckout(), reserva->getHabitacion(), encontrarHuesped(email), Huespedes);
        
        //this->ReservasGrupal

    } //Fin Reserva Grupal

    if (var == 2){ //Reserva Individual
        int opcion = 0, cant = 0;
        
        DTHuesped** Huespedes = new DTHuesped*[MAX_HUESPEDES]();
        std::string email;
        
        Huespedes[cant] = encontrarHuesped(email);
        cant++;

        bool pagado = obtenerPagado();
        
        
        ReservaIndividual *reservaIndividual = new ReservaIndividual(reserva->getCodigo(), reserva->getCheckin(), reserva->getCheckout(), reserva->getHabitacion(), encontrarHuesped(email), Huespedes);

    } //Fin Reserva Individual

}

bool Sistema::existeHabitacion(int numero){
    DTHabitacion **Habitaciones = new DTHabitacion*[MAX_HABITACIONES]();
    int cant = 0;

    Habitaciones = this->obtenerHabitaciones(cant);
    
    for (int i = 0; i < cant; i++){
        if (Habitaciones[i]->getNumero() == numero){
            
            delete Habitaciones;
            return true;
        }
    } 
    delete Habitaciones;
    return false;
}

DTHuesped* Sistema::encontrarHuesped(std::string email){
    DTHuesped **Huespedes = new DTHuesped*();
    int cant = 0;

    Huespedes = this->obtenerHuespedes(cant);
    for (int i = 0; i < cant; i++){

        if (email.compare(Huespedes[i]->getEmail()) == 0){

            return Huespedes[i];
        }
    }
    return NULL;
}    

DTHabitacion* Sistema::encontrarHabitacion(int numero){
    DTHabitacion **habitaciones = new DTHabitacion*();
    int cant = 0;

    habitaciones = this->obtenerHabitaciones(cant);
    for (int i=0; i<cant; i++){
        if(numero == (habitaciones[i]->getNumero())){
            
            return habitaciones[i];
        }
        
    }
    return NULL;
}

bool HayReservaParaHabitacion(DTFecha* fechaIN, DTFecha* fechaOUT, int habitacion){
    bool reservada = false;

    //Reservas**

};

bool validarReservaFecha(DTFecha* CheckIN, DTFecha* CheckOut, DTFecha* fecha){
    int anioIn = CheckIN->getAnio();
    int mesIn = CheckIN->getMes();
    int diaIn = CheckIN->getDia();
    int anioOut = CheckOut->getAnio();
    int mesOut = CheckOut->getMes();
    int diaOut = CheckOut->getDia();
    int anioRes = fecha->getAnio();
    int mesRes = fecha->getMes();
    int diaRes = fecha->getDia();

    if (anioIn > anioRes){
        return false;
    }

    if (anioOut < anioRes){
        return false;
    }

    if (mesIn > mesRes){ //Implicito mismo año
        return false;
    }

    if (mesOut < mesRes){ //Implicito mismo año
        return false;
    }

    if (diaIn > diaRes){ //Implicito mismo año y mes
        return false; 
    }

    if (diaOut < diaRes){ //Implicito mismo año y mes
        return false;
    }

    return true;
};