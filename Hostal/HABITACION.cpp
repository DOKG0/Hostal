#include "HABITACION.h"

Habitacion::Habitacion(){};

Habitacion::Habitacion(int numero, float precio, int capacidad) {
	this->numero = numero;
	this->precio = precio;
	this->capacidad = capacidad;
};
Habitacion::~Habitacion(){};

int Habitacion::getNumero(){
	return this->numero;
};

float Habitacion::getPrecio(){
	return this->precio;
};

int Habitacion::getCapacidad(){
	return this->capacidad;
};

void Habitacion::setNumero(int numero){
	this->numero = numero;
};

void Habitacion::setPrecio(float precio){
	this->precio = precio;
};

void Habitacion::setCapacidad(int capacidad){
	this->capacidad = capacidad;
};
