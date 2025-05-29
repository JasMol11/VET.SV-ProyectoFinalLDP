#include "Tratamiento.h" //Importara la Clase Tratamientocon sus atributos y metodos definida anteriormente 
#include <iostream>//Ayudara a Entrada y salida de datos
#include <fstream>//Ayudara a manipular datos
#include <iomanip>

using namespace std;

// Constructor vacio que se utilizara mas adelante
Tratamiento::Tratamiento(){}
// Constructor para crear objeto con sus parámetros establecidos
Tratamiento::Tratamiento(string paciente, string medicamento, string dosis, string periodo) {
    this->paciente = paciente;
    this->medicamento = medicamento;
    this->dosis = dosis;
    this->periodo = periodo;
}

// Método para ingresar y capturar datos de Tratamientos
void Tratamiento::capturarDatos() {
    cin.ignore(); // Usaremospara limpiar el buffer antes de getline(), evitando errores en la captura de datos
    cout << "Ingrese nombre del paciente: ";
    getline(cin, paciente);
    cout << "Ingrese nombre del medicamento: ";
    getline(cin, medicamento);
    cout << "Ingrese dosis a suministrar: ";
    getline(cin, dosis);
    cout << "Ingrese período de tratamiento: ";
    getline(cin, periodo);
}

// Método para mostrar datos en pantalla de un tratamiento
void Tratamiento::mostrar() {
    cout << "\n---- Tratamiento ----\n";
    cout << left << setw(20) << "Paciente:" << paciente << endl;
    cout << left << setw(20) << "Medicamento:" << medicamento << endl;
    cout << left << setw(20) << "Dosis:" << dosis << endl;
    cout << left << setw(20) << "Periodo:" << periodo << endl;
}

// Método para guardar en archivo binario al cual llamaremos "tratamiento.dat"
void Tratamiento::guardarEnArchivo() {
    ofstream archivo("tratamientos.dat", ios::binary | ios::app);
    if (!archivo) {
    cerr << "Error al abrir el archivo.\n";
    return;
    }
    archivo.write(reinterpret_cast<const char*>(this), sizeof(Tratamiento));
    archivo.close();
    cout << "Tratamiento guardado correctamente.\n";
}
// Método para leer los tratamientos guardados
void Tratamiento::leerArchivo() {
    ifstream archivo("tratamientos.dat", ios::binary);
    Tratamiento tratamiento;
    if (!archivo) {
    cerr << "No se pudo abrir el archivo.\n";
    return;
    }
    cout << "\n--- Tratamientos Guardados ---\n";
    while (archivo.read(reinterpret_cast<char*>(&tratamiento), sizeof(Tratamiento))) {
        tratamiento.mostrar();
    }
    archivo.close();
}
// Método para buscar un tratamiento por nombre de paciente
void Tratamiento::buscarTratamiento(string nombrePaciente) {
    ifstream archivo("tratamientos.dat", ios::binary);
    Tratamiento tratamiento;
    bool encontrado = false;
    if (!archivo) {
    cerr << "No se pudo abrir el archivo.\n";
    return;
    }
    while (archivo.read(reinterpret_cast<char*>(&tratamiento), sizeof(Tratamiento))) {
        if (tratamiento.paciente == nombrePaciente) {
            encontrado = true;
            tratamiento.mostrar();
            break; }
    }
    archivo.close();
    if (!encontrado) {
        cout << "No se encontró ningún tratamiento para el paciente: " << nombrePaciente << endl;
    }
}
// Método para editar un tratamiento existente por si necesita modificacion el cual ya esta guardado en archivo Binario
void Tratamiento::editarTratamiento(string nombrePaciente) {
    fstream archivo("tratamientos.dat", ios::binary | ios::in | ios::out); //El prpgrama buscara en la lista del archivo binario la informacion por si la tuviese
    Tratamiento tratamiento;
    bool encontrado = false;
    streampos posicion;

    if (!archivo) {
        cerr << "No se pudo abrir el archivo.\n"; //si no la encuentra mostrara esto en pantalla
        return;
    }

    while (archivo.read(reinterpret_cast<char*>(&tratamiento), sizeof(Tratamiento))) {
        if (tratamiento.paciente == nombrePaciente) {
            encontrado = true;
            posicion = archivo.tellg() - static_cast<streampos>(sizeof(Tratamiento));
            cout << "\nTratamiento Actual\n";// al recorrer el programa si encuentra  mostrara la informacion del paciente 
            tratamiento.mostrar();
            cout << "\nIngrese nuevos datos:\n"; // dara paso para editar y actualizar
            tratamiento.capturarDatos();
            archivo.seekp(posicion);
            archivo.write(reinterpret_cast<const char*>(&tratamiento), sizeof(Tratamiento));
            cout << "Tratamiento actualizado correctamente.\n";
            break;
        }
    }

    archivo.close();

    if (!encontrado) {
        cout << "No se encontró ningún tratamiento para el paciente: " << nombrePaciente << endl;
    }
}
