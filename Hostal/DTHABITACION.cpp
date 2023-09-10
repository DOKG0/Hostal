#include "DTHabitacion.h"
#include <iostream>

DTHabitacion::DTHabitacion(){};

DTHabitacion::DTHabitacion(int _numero, float _precio, int _capacidad){
    this->numero = _numero;
    this->precio = _precio;
    this->capacidad = _capacidad;
};

DTHabitacion::~DTHabitacion(){};

int DTHabitacion::getNumero() {
    return this->numero;
}

float DTHabitacion::getPrecio() {
    return this->precio;
}

int DTHabitacion::getCapacidad() {
    return this->capacidad;
}
