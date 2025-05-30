#ifndef CITAS_H
#define CITAS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>

using namespace std;

class FechaHora {
public:
    int dia, mes, anio, hora, minuto;

    FechaHora() : dia(0), mes(0), anio(0), hora(0), minuto(0) {}

    string archivoSemana() const {
        int semana = (dia - 1) / 7 + 1;
        ostringstream oss;
        oss << "registros_" << setfill('0') << setw(2) << mes << "_semana" << semana << ".bin";
        return oss.str();
    }

    string archivoMes() const {
        ostringstream oss;
        oss << "registros_mes_" << setfill('0') << setw(2) << mes << ".bin";
        return oss.str();
    }

    bool esIgual(const FechaHora& otra) const {
        return dia == otra.dia && mes == otra.mes && anio == otra.anio &&
               hora == otra.hora && minuto == otra.minuto;
    }
};

class Tratamiento {
public:
    string descripcion;
};

class Duenio {
public:
    string nombre, telefono;
};

class Paciente {
public:
    string nombreAnimal, especie;
    Duenio duenio;
};

class Cita {
public:
    Paciente paciente;
    Tratamiento tratamiento;
    FechaHora fechaHora;

    bool mismoHorario(const FechaHora& fh) const {
        return fechaHora.esIgual(fh);
    }
};

// Declaración de funciones fuera de las clases
void agregarFechaHora(FechaHora& fh);
void mostrarFechaHora(const FechaHora& fh);
void agregarTratamiento(Tratamiento& t);
void mostrarTratamiento(const Tratamiento& t);
void agregarDuenio(Duenio& d);
void mostrarDuenio(const Duenio& d);
void agregarPaciente(Paciente& p);
void mostrarPaciente(const Paciente& p);
void agregarCita(Cita& c);
void mostrarCita(const Cita& c);
bool existeConflicto(const vector<Cita>& citas, const FechaHora& nuevaFecha);
void guardarCitas(const vector<Cita>& citas);
void buscarCita(const vector<Cita>& citas, const string& nombre);
void editarCita(vector<Cita>& citas, const string& nombre);

#endif // CITAS_H
