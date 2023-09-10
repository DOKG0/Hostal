#include "RESERVAGRUPAL.h"

ReservaGrupal::ReservaGrupal(){};

ReservaGrupal::ReservaGrupal(int codigo, DTFecha checkin, DTFecha checkout, DTHabitacion* habitacion, DTHuesped* huesped, DTHuesped** Huespedes){
	this->codigo = codigo;
	this->checkin = checkin;
	this->checkout = checkout;
	this->habitacion = habitacion;
	this->huesped = huesped;
	this->Huespedes = Huespedes;
	this->costo = Reserva::calcularCosto();
};

ReservaGrupal::~ReservaGrupal(){};

void ReservaGrupal::setCheckInGrupal(DTFecha checkin){
	this->checkin = checkin;
};

void ReservaGrupal::setCheckOutGrupal(DTFecha checkout){
	this->checkout = checkout;
};

void ReservaGrupal::setEstadoGrupal(EstadoReserva estado){
	this->estado = estado;
};

int ReservaGrupal::getCodigoGrupal(){
	return this->codigo;
};

DTFecha ReservaGrupal::getCheckIN(){
	return this->checkin;
};

DTFecha ReservaGrupal::getCheckOUT(){
	return this->checkout;
};

EstadoReserva ReservaGrupal::getEstadoGrupal(){
	return this->estado;
};