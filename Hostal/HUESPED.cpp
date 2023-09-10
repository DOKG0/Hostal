#include "HUESPED.h"
#include <iostream>

Huesped::Huesped() {};

Huesped::Huesped(std::string nombre, std::string email, bool esFinger){
	this->nombre = nombre;
	this->email = email;
	this->esFinger = esFinger;
};

Huesped::~Huesped() {

};

std::string Huesped::getNombre(){
	return this->nombre;
};

std::string Huesped::getEmail(){
	return this->email;
};

bool Huesped::getEsfinger(){
	return this->esFinger;
};

void Huesped::setNombre(std::string nombre){
	this->nombre = nombre;
};

void Huesped::setEmail(std::string email){
	this->email = email;
};

void Huesped::setEsfinger(bool esFinger){
	this->esFinger = esFinger;
};
