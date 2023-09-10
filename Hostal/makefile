# Makefile para proyecto

# ######################
# Vars

CC = g++
CFLAGS = -Wall -g

# ######################

copy: main
	mv *.o /home/dirty/Documentos/Vscode/Objects
	
main: DTFecha.o DTHABITACION.o DTHUESPED.o DTReserva.o DTReservaGrupal.o DTReservaIndividual.o HABITACION.o HUESPED.o RESERVA.o RESERVAGRUPAL.o RESERVAINDIVIDUAL.o functions.o Sistema.o main.o
	$(CC) $(CFLAGS) DTFecha.o DTHABITACION.o DTHUESPED.o DTReserva.o DTReservaGrupal.o DTReservaIndividual.o HABITACION.o HUESPED.o RESERVA.o RESERVAGRUPAL.o RESERVAINDIVIDUAL.o functions.o Sistema.o main.o -o main 

# ######################

main.o: main.cpp DTFecha.h DTHabitacion.h DTHUESPED.h DTRESERVA.h DTRESERVAGRUPAL.h DTRESERVAINDIVIDUAL.h HABITACION.h HUESPED.h RESERVA.h RESERVAGRUPAL.h RESERVAINDIVIDUAL.h header.h Sistema.h
	$(CC) $(CFLAGS) -c main.cpp 

Sistema.o: Sistema.h HUESPED.o DTHUESPED.o DTHABITACION.o DTReserva.o RESERVA.o MaxValues.h
	$(CC) $(CFLAGS) -c Sistema.cpp DTHUESPED.cpp DTHABITACION.cpp

RESERVAGRUPAL.o: RESERVAGRUPAL.h RESERVA.o DTFecha.o DTHUESPED.o
	$(CC) $(CFLAGS) -c RESERVAGRUPAL.cpp DTReserva.cpp DTHUESPED.cpp

RESERVAINDIVIDUAL.o: RESERVAINDIVIDUAL.h RESERVA.o
	$(CC) $(CFLAGS) -c RESERVAINDIVIDUAL.cpp DTReserva.cpp

RESERVA.o: RESERVA.h DTFecha.o MaxValues.h
	$(CC) $(CFLAGS) -c RESERVA.cpp DTFecha.cpp

functions.o: header.h MaxValues.h DTFecha.o DTHUESPED.o DTHABITACION.o
	$(CC) $(CFLAGS) -c functions.cpp DTFecha.cpp DTHUESPED.cpp DTHABITACION.cpp

DTReservaGrupal.o: DTRESERVAGRUPAL.h MaxValues.h DTHUESPED.o DTReserva.o
	$(CC) $(CFLAGS) -c DTReservaGrupal.cpp DTHUESPED.cpp

DTReservaIndividual.o: DTRESERVAINDIVIDUAL.h DTReserva.o
	$(CC) $(CFLAGS) -c DTReservaIndividual.cpp DTReserva.cpp

DTReserva.o: DTRESERVA.h MaxValues.h DTFecha.o
	$(CC) $(CFLAGS) -c DTReserva.cpp

DTFecha.o: DTFecha.h
	$(CC) $(CFLAGS) -c DTFecha.cpp

DTHABITACION.o: DTHabitacion.h
	$(CC) $(CFLAGS) -c DTHABITACION.cpp

DTHUESPED.o: DTHUESPED.h
	$(CC) $(CFLAGS) -c DTHUESPED.cpp

HABITACION.o: HABITACION.h
	$(CC) $(CFLAGS) -c HABITACION.cpp

HUESPED.o: HUESPED.h
	$(CC) $(CFLAGS) -c HUESPED.cpp

# ######################