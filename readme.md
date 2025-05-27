# 🐾 Sistema de Gestión Clínica Veterinaria - VET.SV 🐾

Este sistema fue desarrollado como parte del proyecto final de la asignatura **Diseño y Programación de Base de Datos**, para la clínica veterinaria **VET.SV**.

El objetivo principal es facilitar la gestión y seguimiento de pacientes (mascotas), sus dueños, tratamientos y citas, resolviendo los problemas actuales que enfrenta la clínica al no tener un sistema centralizado.


## 👥 Integrantes del equipo 👥

|  Carnet  |         Nombre         |                             Rol                                   |
|----------|------------------------|-------------------------------------------------------------------|
| MO21016  | Jason Molina           | **Project Manager, Main Menu and Navigation, Team Lead and QA**   |
| CR20067  | Danilo Cabrera         | Patient Management and Documentation Contributor                  |
| GO23001  | Luis García            | Owner Management and Documentation Contributor                    |
| RM24005  | Jacqueline Renderos    | Treatment Management and Documentation Contributor                |
| CH21024  | Samuel Cortez          | Appointment Management and Documentation Contributor              |
| CM23138  | Mynor Carias           | Reports Management and Documentation Contributor                  |


## 🛠️ Tecnologías utilizadas 🛠️
    Lenguaje: C++

    Paradigmas: POO + Manejo de Archivos Binarios

    Entorno: Consola (modo texto)

    Librerías estándar: <iostream>, <fstream>


## 📁 Estructura del proyecto 📁

    VET.SV-PROYECTOFINALLDP/
    │
    ├── data/ # Archivos binarios de datos
    │ ├── patients.dat
    │ ├── owners.dat
    │ ├── treatments.dat
    │ └── appointments.dat
    │
    ├── src/
    │ ├── entities/ # Clases base (POO)
    │ │ ├── patient.{h,cpp}
    │ │ ├── owner.{h,cpp}
    │ │ ├── treatment.{h,cpp}
    │ │ └── Appointment.{h,cpp}
    │ │
    │ └── managers/ # Funciones de gestión (CRUD)
    │ ├── managePatients.{h,cpp}
    │ ├── manageOwners.{h,cpp}
    │ ├── manageTreatments.{h,cpp}
    │ └── manageAppointments.{h,cpp}
    │
    ├── main.cpp # Menú principal y navegación
    └── readme.md # Este documento


## ⚙️ Compilación y ejecución ⚙️

### 🐧 En Linux / macOS:

    bash g++ main.cpp src/entities/*.cpp src/managers/*.cpp -o vet-sv ./vet-sv

### 🪟 En Windows :
    Reemplaza system("clear") por system("cls") en el código para limpiar consola.

    Compila con MinGW o cualquier entorno compatible con C++.


## 🎮 Uso del sistema 🎮
**Al iniciar el programa se muestra el menú principal con las siguientes opciones:**

    1. Gestión de Pacientes

    2. Gestión de Dueños

    3. Gestión de Tratamientos

    4. Gestión de Citas

    5. Gestión de Reportes

    0. Salir

**Cada módulo permite:**
    
    📌 Agregar nuevos registros

    🔍 Buscar registros existentes
    
    ✏️ Editar información almacenada

Al finalizar cada gestión, se pregunta si desea continuar en el módulo o regresar al menú principal


## 📊 Reportes disponibles 📊
    📌 Todos los pacientes registrados
    
    📌 Citas por día
    
    📌 Tratamientos por paciente

    (Los reportes se muestran por consola y pueden expandirse en futuras versiones.)

---

## 🎓 Proyecto académico 🎓
    Este proyecto corresponde al trabajo final de la materia Diseño y Programación de Bases de Datos, de la carrera de Ingeniería en Desarrollo de Software de la Universidad de El Salvador