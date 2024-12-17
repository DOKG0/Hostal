# Sistema de Gestión de Reservas de Hostel

## Descripción

Es una aplicación diseñada para administrar las reservas en un hostel, dirigido especialmente a estudiantes de la carrera Tecnólogo en Informática (TecnoPackers) que desean disfrutar de precios preferenciales en sus vacaciones. El sistema permite gestionar los huéspedes, las habitaciones, y las reservas, con una estructura de precios y descuentos según el tipo de reserva.

Cada huésped tiene información relevante, como su email (que lo identifica), nombre, y si es "Finger" o no. Las habitaciones se identifican por un número y tienen un precio por noche y una capacidad específica. Las reservas pueden ser individuales o grupales, con diferentes estados y costos asociados.

---

## Funcionalidades

### Gestión de Huéspedes
- Los huéspedes tienen un email único, nombre y un campo que indica si son "Finger" o no.

### Gestión de Habitaciones
- Cada habitación tiene un número único, un precio por noche y una capacidad.

### Gestión de Reservas
- Las reservas se pueden hacer de manera individual o grupal.
- Cada reserva tiene un código único, fechas de check-in y check-out, y un estado (Abierta, Cerrada o Cancelada).
- Las reservas individuales pueden tener un estado de "Abonada" o "No Abonada".
- El costo de las reservas individuales se calcula en función del precio de la habitación y la duración de la estancia.
- Las reservas grupales tienen un 30% de descuento si incluyen al menos dos TecnoPackers.

---

## Estructura del Proyecto

- **Programación Orientada a Objetos**: El sistema está implementado utilizando principios de POO.
- **Clases**:
  - **Huésped**: Representa a los huéspedes con sus detalles (email, nombre, si es Finger).
  - **Habitación**: Representa una habitación del hostel, con un número, precio por noche y capacidad.
  - **Reserva**: Representa una reserva, con código, fechas, estado y costo (individual o grupal).
- **Controlador**:
  - **Sistema**: Controlador principal que maneja la lógica de las operaciones (agregar huéspedes, crear reservas, etc.).
- **Tipos de Datos**:
  - Se utilizan tipos de datos específicos para almacenar las propiedades de los huéspedes, habitaciones y reservas.

---

## Tecnologías Utilizadas

- **Lenguaje**: C++
- **Conceptos**: Programación Orientada a Objetos, manejo de tipos de datos, clases, objetos, herencia y encapsulamiento.
- **Compilación**: Utiliza **Makefile** para la compilación y ejecución del proyecto.

---

## Instrucciones de Uso

### Requisitos Previos

- Tener instalado un compilador C++ (como `g++`).
- Tener un entorno de desarrollo adecuado para C++.
- Tener instalado make.

### Instalación

1. Clona o descarga el repositorio del proyecto:

   ```bash
   git clone https://github.com/usuario/tecnoVMB.git
   
2. Utiliza el **Makefile** incluido para compilar y ejecutar el proyecto.
   - Compilar:  
     ```bash
     make
     ```
   - Ejecutar:  
     ```bash
     Abre la consola en el directorio de la aplicacion y ejecuta ./main
     ```
3. Limpiar archivos generados:  
   ```bash
   make clean
