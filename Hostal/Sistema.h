#ifndef SISTEMA_H
#define SISTEMA_H
#include <string>
#include "HUESPED.h"
#include "DTHUESPED.h"
#include "HABITACION.h"
#include "DTHabitacion.h"
#include "DTRESERVA.h"
#include "RESERVA.h"
#include "MaxValues.h"
#include "header.h"
#include "RESERVAGRUPAL.h"
#include "RESERVAINDIVIDUAL.h"

class Sistema{

private:
    //vars
    Huesped** Huespedes = new Huesped*[MAX_HUESPEDES]();
    Habitacion** Habitaciones = new Habitacion*[MAX_HABITACIONES]();
    //Reserva** Reservas = new Reserva*[MAX_RESERVAS]();
    ReservaIndividual** ReservasIndividuales = new ReservaIndividual*[MAX_RESERVAS]();
    ReservaGrupal** ReservasGrupales = new ReservaGrupal*[MAX_RESERVAS]();

public:
    //Constructores
    Sistema();
    Sistema(Huesped **Huespedes, Habitacion **Habitaciones, ReservaIndividual** ReservasIndividuales, ReservaGrupal** ReservasGrupales);
    ~Sistema();

    //Metodos
    void agregarHuesped(std::string nombre, std::string email, bool esFinger);
    void agregarHabitacion(int numero, float precio, int capacidad);
    void registrarReserva(std::string email, DTReserva* reserva);
    DTHuesped** obtenerHuespedes(int& cantHuepedes);
    DTHabitacion** obtenerHabitaciones(int& cantHabitaciones);
    DTReserva** obtenerReservas(DTFecha fecha, int& cantReservas);
    DTReserva* armarReserva(std::string email); //Func Auxiliar para armar el parametro DTReserva
    bool existeHuesped(std::string); //Verifica existencia
    bool existeHabitacion(int);
    DTHuesped* encontrarHuesped(std::string email); //Encuentra huesped en hotel
    DTHabitacion* encontrarHabitacion(int numero); //Encuentra la habitacion en el hotel
    bool HayReservaParaHabitacion(DTFecha* fechaIN, DTFecha* fechaOUT, int habitacion); //Verifica que no haya reservas para la habitacion entre las fechas
    bool validarReservaFecha(DTFecha CheckIN, DTFecha CheckOut, DTFecha fecha); //Checkea que la reserva exista en la fecha. FechaCheckIn < fecha < FechaCheckOut

};

#endif