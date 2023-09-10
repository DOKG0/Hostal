#include "DTHUESPED.h"
#include <iostream>

DTHuesped::DTHuesped(){};

DTHuesped::DTHuesped(std::string _nombre, std::string _email, bool _esFinger){
    this->nombre = _nombre;
    this->email = _email;
    this->esFinger = _esFinger;
};

DTHuesped::DTHuesped(DTHuesped&){};

DTHuesped::~DTHuesped(){};

std::string DTHuesped::getNombre(){
    return this->nombre;
};

std::string DTHuesped::getEmail(){
    return this->email;
};

bool DTHuesped::getEsFinger(){
    return this->esFinger;
};
