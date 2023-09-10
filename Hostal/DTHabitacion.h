#ifndef DTHABITACION_H
#define DTHABITACION_H
#include <iostream>

//DTHabitacion
class DTHabitacion{
  private:
		int numero;
		float precio;
		int capacidad;
		
  public:
    DTHabitacion();
    DTHabitacion(int _numero, float _precio, int _capacidad);
    ~DTHabitacion();

    int getNumero();
    float getPrecio();
    int getCapacidad();
};

#endif 