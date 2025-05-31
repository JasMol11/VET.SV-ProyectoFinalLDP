//CREACION DE CLASE Tratamiento con sus respectivos atributos y metodos a utilizar
#ifndef TRATAMIENTO_H
#define TRATAMIENTO_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

class Tratamiento {
public:
    std::string paciente;
    std::string medicamento;
    std::string dosis;
    std::string periodo;

    // Constructor por defecto vacio
    Tratamiento();
    
    // Constructor con parámetros
    Tratamiento(std::string paciente, std::string medicamento, std::string dosis, std::string periodo);

    // Métodos a utilizar en desarrollo de  Tratamiento 
    void capturarDatos();
    void mostrar();
    void guardarEnArchivo();
    static void leerArchivo();
    static void buscarTratamiento(std::string nombrePaciente);
    static void editarTratamiento(std::string nombrePaciente);
};

#endif // TRATAMIENTO_H
