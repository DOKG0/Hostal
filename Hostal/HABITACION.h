#ifndef HABITACION_H_
#define HABITACION_H_

class Habitacion {
private:
	int numero;
	float precio;
	int capacidad;

public:
	Habitacion();
	Habitacion(int numero, float precio, int capacidad);
	~Habitacion();

	int getNumero();
	float getPrecio();
	int getCapacidad();

	void setNumero(int numero);
	void setPrecio(float precio);
	void setCapacidad(int capacidad);

};

#endif 