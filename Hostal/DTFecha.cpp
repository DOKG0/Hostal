#include "DTFecha.h"

DTFecha::DTFecha(){};
DTFecha::DTFecha(int dia, int mes, int anio){
    this->dia = dia;
    this->anio = anio;
    this->mes = mes;
};
DTFecha::~DTFecha(){};

int DTFecha::getDia(){
    return this->dia;
};

int DTFecha::getMes(){
    return this->mes;
};
int DTFecha::getAnio(){
    return this->anio;
};