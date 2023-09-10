#ifndef RESERVAGRUPAL_H
#define RESERVAGRUPAL_H

#include <iostream>
#include "RESERVA.h"
#include "DTFecha.h"
#include "DTHUESPED.h"

class ReservaGrupal: Reserva{
	
private:
	DTHuesped** Huespedes = new DTHuesped*[MAX_HUESPEDES];

public:
	ReservaGrupal();
	ReservaGrupal(int codigo, DTFecha checkin, DTFecha checkout, DTHabitacion* habitacion, DTHuesped* huesped, DTHuesped** Huespedes);
	ReservaGrupal(ReservaGrupal& );
	~ReservaGrupal();

	// void setCodigo(int);
	float calcularCosto();
	void setCheckInGrupal(DTFecha checkin);
	void setCheckOutGrupal(DTFecha checkout);
	void setEstadoGrupal(EstadoReserva estado);
	int getCodigoGrupal();
	DTFecha getCheckIN();
	DTFecha getCheckOUT();
	EstadoReserva getEstadoGrupal();
};

#endif