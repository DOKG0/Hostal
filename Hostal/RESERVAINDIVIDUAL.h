#ifndef RESERVAINDIVIDUAL_H
#define RESERVAINDIVIDUAL_H

#include <iostream>
#include "RESERVA.h"

//Clase Reserva individual
class ReservaIndividual: public Reserva{
	private:
		bool pagado;

	public:
		float calcularCosto();
		ReservaIndividual();
		ReservaIndividual(int codigo, DTFecha checkin, DTFecha checkout, DTHabitacion* habitacion, DTHuesped* huesped, bool pagado);
		~ReservaIndividual();

		void setCheckInIndividual(DTFecha checkin);
		void setCheckOutIndividual(DTFecha checkout);
		void setEstadoIndividual(EstadoReserva estado);
		int getCodigoIndividual();
		DTFecha getCheckIN();
		DTFecha getCheckOUT();
		EstadoReserva getEstadoIndividual();
};

#endif