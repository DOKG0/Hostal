#ifndef DTFECHA_H
#define DTFECHA_H
#include <iostream>

//DTFecha
class DTFecha{
	private:
		int dia;
		int mes;
		int anio;
	public:
		DTFecha();
		DTFecha(int dia, int mes, int anio);
		~DTFecha();
		int getDia();
		int getMes();
		int getAnio();
};

#endif 