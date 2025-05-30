#include "citas.h"

void agregarFechaHora(FechaHora& fh) {
    cout << "Ingrese dia, mes, anio, hora, minuto: ";
    cin >> fh.dia >> fh.mes >> fh.anio >> fh.hora >> fh.minuto;
}

void mostrarFechaHora(const FechaHora& fh) {
    cout << setfill('0') << setw(2) << fh.dia << "/"
         << setw(2) << fh.mes << "/" << fh.anio << " "
         << setw(2) << fh.hora << ":" << setw(2) << fh.minuto << endl;
}

void agregarTratamiento(Tratamiento& t) {
    cout << "Descripcion del tratamiento: ";
    cin.ignore();
    getline(cin, t.descripcion);
}

void mostrarTratamiento(const Tratamiento& t) {
    cout << "Tratamiento: " << t.descripcion << endl;
}

void agregarDuenio(Duenio& d) {
    cout << "Nombre del dueno: ";
    cin.ignore();
    getline(cin, d.nombre);
    cout << "Telefono: ";
    getline(cin, d.telefono);
}

void mostrarDuenio(const Duenio& d) {
    cout << "Duenio: " << d.nombre << ", Telefono: " << d.telefono << endl;
}

void agregarPaciente(Paciente& p) {
    cout << "Nombre del animal: ";
    cin.ignore();
    getline(cin, p.nombreAnimal);
    cout << "Especie: ";
    getline(cin, p.especie);
    agregarDuenio(p.duenio);
}

void mostrarPaciente(const Paciente& p) {
    cout << "Paciente: " << p.nombreAnimal << " (" << p.especie << ")\n";
    mostrarDuenio(p.duenio);
}

void agregarCita(Cita& c) {
    agregarPaciente(c.paciente);
    agregarTratamiento(c.tratamiento);
    agregarFechaHora(c.fechaHora);
}

void mostrarCita(const Cita& c) {
    mostrarPaciente(c.paciente);
    mostrarTratamiento(c.tratamiento);
    mostrarFechaHora(c.fechaHora);
}

bool existeConflicto(const vector<Cita>& citas, const FechaHora& nuevaFecha) {
    for (const auto& c : citas) {
        if (c.mismoHorario(nuevaFecha)) return true;
    }
    return false;
}

void guardarCitas(const vector<Cita>& citas) {
    for (const auto& c : citas) {
        string archivoSem = c.fechaHora.archivoSemana();
        string archivoMes = c.fechaHora.archivoMes();
        ofstream outSem(archivoSem, ios::binary | ios::app);
        ofstream outMes(archivoMes, ios::binary | ios::app);

        size_t len;

        len = c.paciente.nombreAnimal.size();
        outSem.write((char*)&len, sizeof(len));
        outSem.write(c.paciente.nombreAnimal.c_str(), len);
        outMes.write((char*)&len, sizeof(len));
        outMes.write(c.paciente.nombreAnimal.c_str(), len);

        len = c.paciente.especie.size();
        outSem.write((char*)&len, sizeof(len));
        outSem.write(c.paciente.especie.c_str(), len);
        outMes.write((char*)&len, sizeof(len));
        outMes.write(c.paciente.especie.c_str(), len);

        len = c.paciente.duenio.nombre.size();
        outSem.write((char*)&len, sizeof(len));
        outSem.write(c.paciente.duenio.nombre.c_str(), len);
        outMes.write((char*)&len, sizeof(len));
        outMes.write(c.paciente.duenio.nombre.c_str(), len);

        len = c.paciente.duenio.telefono.size();
        outSem.write((char*)&len, sizeof(len));
        outSem.write(c.paciente.duenio.telefono.c_str(), len);
        outMes.write((char*)&len, sizeof(len));
        outMes.write(c.paciente.duenio.telefono.c_str(), len);

        len = c.tratamiento.descripcion.size();
        outSem.write((char*)&len, sizeof(len));
        outSem.write(c.tratamiento.descripcion.c_str(), len);
        outMes.write((char*)&len, sizeof(len));
        outMes.write(c.tratamiento.descripcion.c_str(), len);

        outSem.write((char*)&c.fechaHora, sizeof(FechaHora));
        outMes.write((char*)&c.fechaHora, sizeof(FechaHora));

        outSem.close();
        outMes.close();
    }
    cout << "Citas guardadas por semana y mes en formato binario.\n";
}

void buscarCita(const vector<Cita>& citas, const string& nombre) {
    for (const auto& c : citas) {
        if (c.paciente.nombreAnimal == nombre) {
            mostrarCita(c);
        }
    }
}

void editarCita(vector<Cita>& citas, const string& nombre) {
    for (auto& c : citas) {
        if (c.paciente.nombreAnimal == nombre) {
            cout << "Editando cita para: " << nombre << endl;
            agregarCita(c);
            break;
        }
    }
}
