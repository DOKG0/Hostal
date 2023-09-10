#include<iostream>
#include "RESERVAINDIVIDUAL.h"
#include "DTRESERVA.h"
#include "DTFecha.h"
#include "MaxValues.h"
#include <string>

ReservaIndividual::ReservaIndividual(){};

ReservaIndividual::ReservaIndividual(int codigo, DTFecha checkin, DTFecha checkout, DTHabitacion* habitacion, DTHuesped* huesped, bool pagado){
	this->codigo = codigo;
	this->checkin = checkin;
	this->checkout = checkout;
	this->habitacion = habitacion;
	this->huesped = huesped;
	this->pagado = pagado;
	this->costo = Reserva::calcularCosto();
};

ReservaIndividual::~ReservaIndividual(){};

void ReservaIndividual::setCheckInIndividual(DTFecha checkin){
	this->checkin = checkin;
};

void ReservaIndividual::setCheckOutIndividual(DTFecha checkout){
	this->checkout = checkout;
};

void ReservaIndividual::setEstadoIndividual(EstadoReserva estado){
	this->estado = estado;
}

int ReservaIndividual::getCodigoIndividual(){
	return this->codigo;
};

DTFecha ReservaIndividual::getCheckIN(){
	return this->checkin;
};

DTFecha ReservaIndividual::getCheckOUT(){
	return this->checkout;
};

EstadoReserva ReservaIndividual::getEstadoIndividual(){
	return this->estado;
};
