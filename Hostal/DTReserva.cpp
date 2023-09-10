#include "DTRESERVA.h"
#include "MaxValues.h"

DTReserva::DTReserva(){};

DTReserva::DTReserva(int codigo, DTFecha checkin, DTFecha checkout, EstadoReserva estado, float costo, DTHabitacion* habitacion, DTHuesped* huesped){
    this->codigo     = codigo;
    this->checkin    = checkin;
    this->checkout   = checkout;
    this->estado     = estado;
    this->costo      = costo;
    this->habitacion = habitacion;
    this->huesped    = huesped;
};

DTReserva::~DTReserva(){};

int DTReserva::getCodigo(){
    return this->codigo;
};
DTFecha DTReserva::getCheckin(){
    return this->checkin;
};
DTFecha DTReserva::getCheckout(){
    return this->checkout;
};
EstadoReserva DTReserva::getEstado(){
    return this->estado;
};
float DTReserva::getCosto(){
    return this->costo;
};
DTHabitacion* DTReserva::getHabitacion(){
    return this->habitacion;
};