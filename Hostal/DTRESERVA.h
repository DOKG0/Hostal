#ifndef DTRESERVA_H
#define DTRESERVA_H
#include <iostream>
#include "DTFecha.h"
#include "MaxValues.h"
#include "DTHUESPED.h"
#include "DTHabitacion.h"

//Datatype Reserva
class DTReserva{
	private:
		int codigo;
		float costo;
		DTFecha checkin;
		DTFecha checkout;
		EstadoReserva estado;
		DTHabitacion* habitacion;
		DTHuesped* huesped;
	
	public:
		DTReserva();
		DTReserva(int codigo, DTFecha checkin, DTFecha checkout, EstadoReserva estado, float costo, DTHabitacion* habitacion, DTHuesped* huesped);
		~DTReserva();

		int getCodigo();
		DTFecha getCheckin();
		DTFecha getCheckout();
		EstadoReserva getEstado();
		float getCosto();
		DTHabitacion* getHabitacion();
};

#endif