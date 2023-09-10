#ifndef DTRESERVAINDOVIDUAL_H
#define DTRESERVAINDIVIDUAL_H
#include "DTRESERVA.h"

class DTReservaIndividual: public DTReserva{
	private:
		bool pagado;

	public:
		DTReservaIndividual();
		DTReservaIndividual(bool pagado);
		~DTReservaIndividual();

		bool getPagado();
		std::string pagadoSiNo();
};

std::ostream& operator<< (std::ostream& stream, DTReservaIndividual& dtReservaInvidual);

#endif