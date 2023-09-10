#include<iostream>
#include <string>
#include "RESERVA.h"
#include "MaxValues.h"

Reserva::Reserva() {};

Reserva::Reserva(int codigo, DTFecha checkin, DTFecha checkout, DTHabitacion* habitacion, DTHuesped* huesped){
	this->codigo = codigo;
	this->checkin = checkin;
	this->checkout = checkout;
	this->habitacion = habitacion;
	this->huesped = huesped;
	this->costo = calcularCosto();
};

Reserva::~Reserva() {

};

void Reserva::setCheckIN(DTFecha checkin){
	this->checkin = checkin;
};

void Reserva::setCheckOUT(DTFecha checkout){
	this->checkout = checkout;
};

void Reserva::setEstado(EstadoReserva estado){
	this->estado = estado;
}

void Reserva::setHabitacion(DTHabitacion* habitacion){
	this->habitacion = habitacion;
};

void Reserva::setHuesped(DTHuesped* huesped){
	this->huesped = huesped;
}

int Reserva::getCodigo(){
	return this->codigo;
};

DTFecha Reserva::getCheckIN(){
	return this->checkin;
};

DTFecha Reserva::getCheckOUT(){
	return this->checkout;
};

EstadoReserva Reserva::getEstado(){
	return this->estado;
};

DTHabitacion* Reserva::getHabitacion(){
	return this->habitacion;
};

DTHuesped* Reserva::getHuesped(){
	return this->huesped;
};

float Reserva::calcularCosto(){
	int difEnDias = 0;
	difEnDias = calcularDias(); //De calcular la diferencia en dias y retornarla para multiplicar difEnDias*precio. Retorna float (int * float)

	return (difEnDias * this->getHabitacion()->getPrecio());
}

int Reserva::calcularDias(){
	int anioIn, mesIn, diaIn, anioOut, mesOut, diaOut;

	anioIn  = this->checkin.getAnio();
	mesIn   = this->checkin.getMes();
	diaIn   = this->checkin.getDia();
	anioOut = this->checkout.getAnio();
	mesOut  = this->checkout.getMes();
	diaOut  = this->checkout.getDia();

	//Mismo año, mismo mes
	if ((anioIn == anioOut) && (mesIn == mesOut)){
		return (diaOut - diaIn);
	}

	//Mismo año, diferente mes
	if ((anioIn == anioOut) && (mesIn != mesOut)){
		return ((diaOut + ((mesOut - mesIn) * 31)) - diaIn);
	}

	//Distinto año, distinto mes
	if ((anioIn != anioOut)){		
		return ((((anioOut - anioIn) - 1) * 372) + (((mesOut - 1) * 31) + (diaOut)) + (((12 - mesIn) * 31) + (31 - diaIn)));
	}
};