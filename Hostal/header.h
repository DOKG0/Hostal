#ifndef HEADER_H
#define HEADER_H
#include "MaxValues.h"
#include "DTFecha.h"
#include "DTHUESPED.h"
#include "DTHabitacion.h"
#include "DTFecha.h"

//Utiles
void clearBuffer();
void pause();

//Funciones menu 
void printMenu();
void printTitle(std::string mensaje);
int obteneropcion();

//Funciones datos
std::string obtenerNombre();
std::string obtenerEmail();
bool obtenerFinger();
bool obtenerPagado();
int obtenerNumeroHabitacion();
int obtenerPrecio();
int obtenerCapacidad();
DTFecha pedirFecha();
int mostrarHuespedes(DTHuesped** huespedes, int cantidad);
int mostrarHabitaciones(DTHabitacion** habitaciones, int cantidad);
std::string Fingersino(bool esFinger);
int pedirDia();
int pedirMes();
int pedirAnio();


#endif
