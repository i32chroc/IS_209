#include <iostream>
#include <fstream>
#include <string>

void agregarPlanConvalidacion(const std::string& archivo) {
    // Variables para los datos
    std::string id, numeroPlazas;
    std::string universidadOrigen, universidadDestino;
    std::string facultadOrigen, facultadDestino;
    std::string carrera, duracion, curso;
    std::string asignaturas;

    // Solicitar datos al usuario
    std::cout << "Ingrese el ID del plan: ";
    std::getline(std::cin, id);

    std::cout << "Ingrese el número de plazas: ";
    std::getline(std::cin, numeroPlazas);

    std::cout << "Ingrese la Universidad de origen: ";
    std::getline(std::cin, universidadOrigen);

    std::cout << "Ingrese la Universidad de destino: ";
    std::getline(std::cin, universidadDestino);

    std::cout << "Ingrese la Facultad de origen: ";
    std::getline(std::cin, facultadOrigen);

    std::cout << "Ingrese la Facultad de destino: ";
    std::getline(std::cin, facultadDestino);

    std::cout << "Ingrese la carrera: ";
    std::getline(std::cin, carrera);

    std::cout << "Ingrese la duración (en cuatrimestres): ";
    std::getline(std::cin, duracion);

    std::cout << "Ingrese el curso: ";
    std::getline(std::cin, curso);

    std::cout << "Ingrese las asignaturas (formato asignaturaOrigen-asignaturaDestino separadas por punto y un espacio '. '): \n";
    std::getline(std::cin, asignaturas);

    // Abrir el archivo en modo de adición
    std::ofstream archivoSalida(archivo, std::ios::app);

    if (archivoSalida.is_open()) {
        // Escribir los datos en el archivo
        archivoSalida << id << " " << numeroPlazas << "\n";
        archivoSalida << universidadOrigen << " " << universidadDestino << "\n";
        archivoSalida << facultadOrigen << " - " << facultadDestino << "\n";
        archivoSalida << carrera << " " << duracion << " " << curso << "\n";
        archivoSalida << asignaturas << "\n";
        archivoSalida << "\n"; // Separador entre planes

        archivoSalida.close();
        std::cout << "Plan de convalidación agregado correctamente." << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo." << std::endl;
    }
}

