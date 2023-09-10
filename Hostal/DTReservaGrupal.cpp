#include "DTRESERVAGRUPAL.h"
#include "DTHUESPED.h"

DTReservaGrupal::DTReservaGrupal(){};
DTReservaGrupal::~DTReservaGrupal(){};

DTReservaGrupal::DTReservaGrupal(DTHuesped *huespedes, int cant){
    for (int i = 0; i<cant; i++){
        this->huespedes[i] = huespedes[i];
    }
};

DTHuesped* DTReservaGrupal::getHuespedes(){
    return this->huespedes;
};

std::string DTReservaGrupal::stringHuespedes(){
    DTHuesped* huespedesPtr = new DTHuesped();
    std::string retorno; //String de retorno

    for (huespedesPtr = &huespedes[0]; huespedesPtr != NULL; huespedesPtr++){
        retorno.append(huespedesPtr->getNombre());
        retorno.append(" - ");
        retorno.append(huespedesPtr->getEmail());
        
        if (huespedesPtr->getEsFinger()){
            retorno.append(" - ");
            retorno.append("es Finger,");
        } else {
            retorno.append(",");
        }
        retorno.append("\n");
        retorno.append("           ");
    }

    delete huespedesPtr;
    return retorno;
};

std::ostream& operator<< (std::ostream& stream, DTReservaGrupal& dtReservaGrupal){
    stream << "TipoReserva: Grupal\nFechaCheckIn: " << dtReservaGrupal.getCheckin().getDia() << '/' << dtReservaGrupal.getCheckin().getMes() << '/' 
    << dtReservaGrupal.getCheckin().getAnio() << "\nHabitacion: " << dtReservaGrupal.getCodigo() << "\nCosto: $" << dtReservaGrupal.getCosto()
    << "\nHuespedes: " << dtReservaGrupal.stringHuespedes();

    return stream;
};