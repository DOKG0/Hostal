#include "DTRESERVAINDIVIDUAL.h"   
#include "DTFecha.h"

DTReservaIndividual::DTReservaIndividual(){};
DTReservaIndividual::~DTReservaIndividual(){};

DTReservaIndividual::DTReservaIndividual(bool pagado){
    this->pagado = pagado;
};

bool DTReservaIndividual::getPagado(){
    return this->pagado;
};

std::string DTReservaIndividual::pagadoSiNo(){
    if (this->pagado){
        return "Si";
    }
    return "No";
};

std::ostream& operator<< (std::ostream& stream, DTReservaIndividual dtReservaIndividual){
    stream << "TipoReserva: Grupal\nFechaCheckIn: " << dtReservaIndividual.getCheckin().getDia() << '/' << dtReservaIndividual.getCheckin().getMes() << '/' 
    << dtReservaIndividual.getCheckin().getAnio() << "\nHabitacion: " << dtReservaIndividual.getCodigo() << "\nCosto: $" << dtReservaIndividual.getCosto()
    << "\nPagado" << dtReservaIndividual.pagadoSiNo();

    return stream;
};
