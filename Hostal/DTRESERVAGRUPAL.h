#ifndef DTRESERVAGRUPAL_H
#define DTRESERVAGRUPAL_H
#include "DTFecha.h"
#include "DTHabitacion.h"
#include "MaxValues.h"
#include "DTRESERVA.h"
#include "DTHUESPED.h"

class DTReservaGrupal: public DTReserva{
	private:
		DTHuesped* huespedes = new DTHuesped[MAX_HUESPEDES]();
	
	public:
		DTReservaGrupal();
		DTReservaGrupal(DTHuesped *huespedes, int cant);
		~DTReservaGrupal();

		DTHuesped* getHuespedes();
		std::string stringHuespedes();

};

std::ostream& operator<< (std::ostream& stream, DTReservaGrupal& dtReservaGrupal);

#endif