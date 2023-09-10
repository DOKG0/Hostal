#ifndef RESERVA_H
#define RESERVA_H
#include <iostream>
#include "DTFecha.h"
#include "MaxValues.h"
#include "DTHabitacion.h"
#include "DTHUESPED.h"

//Clase Reserva
class Reserva {
	protected:
		int codigo;
		float costo;
		DTFecha checkin;
		DTFecha checkout;
		EstadoReserva estado;
		DTHabitacion* habitacion;
		DTHuesped* huesped;

	public:
		Reserva();
		Reserva(int codigo, DTFecha checkin, DTFecha checkout, DTHabitacion* habitacion, DTHuesped* huesped);
		Reserva(Reserva&);
		~Reserva();

		void setCheckIN(DTFecha checkin);
		void setCheckOUT(DTFecha checkout);
		void setEstado(EstadoReserva estado);
		void setHabitacion(DTHabitacion* habitacion);
		void setHuesped(DTHuesped* huesped);
		int getCodigo();
		virtual DTFecha getCheckIN();
		virtual DTFecha getCheckOUT();
		EstadoReserva getEstado();
		DTHabitacion* getHabitacion();
		DTHuesped* getHuesped();
		float calcularCosto();
		int calcularDias();
};


#endif