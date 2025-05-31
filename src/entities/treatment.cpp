//Se incluye la libreria "Tratamiento.h"
#include "Tratamiento.h"

using namespace std;
// Constructor por defecto, inicializa los atributos vacíos
Tratamiento::Tratamiento() {
    paciente = "",
    medicamento = "",
    dosis = "",
    periodo = "",        
}
// Constructor que permite inicializar un tratamiento con datos específicos
Tratamiento::Tratamiento(string paciente, string medicamento, string dosis, string periodo) {
    this->paciente = paciente;
    this->medicamento = medicamento;
    this->dosis = dosis;
    this->periodo = periodo;
}
// Captura los datos de un tratamiento desde la entrada 
void Tratamiento::capturarDatos() {
    cin.ignore(); // Limpia el buffer antes de tomar entradas con getline()
    cout << "Ingrese nombre del paciente: ";
    getline(cin, paciente);
    cout << "Ingrese nombre del medicamento: ";
    getline(cin, medicamento);
    cout << "Ingrese dosis a suministrar: ";
    getline(cin, dosis);
    cout << "Ingrese período de tratamiento: ";
    getline(cin, periodo);
}
// Muestra la información de un tratamiento en un forma ordenada especificando informacion  que se debe brindar
void Tratamiento::mostrar() {
    cout << "\nInformación del Tratamiento\n";
    cout << left << setw(50) << "Paciente:" << paciente << endl;
    cout << left << setw(50) << "Medicamento:" << medicamento << endl;
    cout << left << setw(50) << "Dosis:" << dosis << endl;
    cout << left << setw(50) << "Periodo:" << periodo << endl;
}
// Guarda el tratamiento en un archivo binario dentro de "treatments.dat"
void Tratamiento::guardarEnArchivo() {
    ofstream archivo("treatments.dat", ios::binary | ios::app);
    if (!archivo) {
        cerr << "Error al abrir el archivo de tratamientos.\n";
        return;
    }
    // Escribe los datos del tratamiento en formato binario
    archivo.write(reinterpret_cast<const char*>(this), sizeof(Tratamiento));
    archivo.close();
    cout << "Tratamiento guardado correctamente.\n";
}
// Lee todos los tratamientos guardados y los muestra en pantalla
void Tratamiento::leerArchivo() {
    ifstream archivo("treatments.dat", ios::binary);
    Tratamiento tratamiento; 
    if (!archivo) {
        cerr << "No se pudo abrir el archivo de tratamientos.\n";
        return;
    }
    cout << "\nTratamientos registrados:\n";
    while (archivo.read(reinterpret_cast<char*>(&tratamiento), sizeof(Tratamiento))) {
        tratamiento.mostrar();
    }
    archivo.close();
}
// Busca un tratamiento en el archivo binario por el nombre del paciente
void Tratamiento::buscarTratamiento(string nombrePaciente) {
    ifstream archivo("treatments.dat", ios::binary);
    Tratamiento tratamiento;
    bool encontrado = false;
    if (!archivo) {
        cerr << "No se pudo abrir el archivo de tratamientos.\n";
        return;
    }
    while (archivo.read(reinterpret_cast<char*>(&tratamiento), sizeof(Tratamiento))) {
        // Se verifica si el tratamiento pertenece al paciente buscado
        if (tratamiento.paciente == nombrePaciente) {
            encontrado = true;
            cout << "\n🔎 Tratamiento encontrado:\n";
            tratamiento.mostrar();
            break;
        } }
    archivo.close();
    if (!encontrado) {
        cout << "No se encontró ningún tratamiento para el paciente: " << nombrePaciente << endl;
    }
}
// Permite editar un tratamiento ya registrado en el archivo binario
void Tratamiento::editarTratamiento(string nombrePaciente) {
    fstream archivo("treatments.dat", ios::binary | ios::in | ios::out);
    Tratamiento tratamiento;
    bool encontrado = false;
    streampos posicion;
    if (!archivo) {
        cerr << "No se pudo abrir el archivo de tratamientos.\n";
        return;
    }
    while (archivo.read(reinterpret_cast<char*>(&tratamiento), sizeof(Tratamiento))) {
        if (tratamiento.paciente == nombrePaciente) {
         encontrado = true;
        
        // Calcula la posición exacta en el archivo para editar el tratamiento
        posicion = archivo.tellg() - static_cast<streampos>(sizeof(Tratamiento));

        cout << "\nTratamiento actual:\n";
        tratamiento.mostrar();
        cout << "\nIngrese los nuevos datos:\n";
        tratamiento.capturarDatos();
        // Se mueve a la posición adecuada y se sobrescriben los datos antiguos
        archivo.seekp(posicion);
        archivo.write(reinterpret_cast<const char*>(&tratamiento), sizeof(Tratamiento));
        cout << "Tratamiento actualizado correctamente.\n";
        break;
        } }
    archivo.close();
    // Si no se encontró el tratamiento mostrara este msj
    if (!encontrado) {
        cout << " No se encontró ningún tratamiento para el paciente: " << nombrePaciente << endl;
    }
}
