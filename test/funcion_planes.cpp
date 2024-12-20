#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "funcion_planes.h"

bool PlanesDeConvalidacion::agregarPlanConvalidacion(const std::string& archivo) {
    std::ofstream archivoSalida(archivo, std::ios::app);
    if (archivoSalida.is_open()) {
        std::string input;
        
        std::cout << "Ingrese el ID del plan: ";
        std::cin >> id;
        
        std::cout << "Ingrese el número de plazas: ";
        std::cin >> numeroPlazas;
        std::cin.ignore(); 
        
        std::cout << "Ingrese la universidad de origen: ";
        std::getline(std::cin, universidadOrigen);
        
        std::cout << "Ingrese la universidad de destino: ";
        std::getline(std::cin, universidadDestino);
        
        std::cout << "Ingrese la facultad de origen: ";
        std::getline(std::cin, facultadOrigen);
        
        std::cout << "Ingrese la facultad de destino: ";
        std::getline(std::cin, facultadDestino);
        
        std::cout << "Ingrese la carrera: ";
        std::getline(std::cin, carrera);
        
        std::cout << "Ingrese la duración en cuatrimestres: ";
        std::cin >> duracion;
        std::cin.ignore();
        
        std::cout << "Ingrese el curso: ";
        std::getline(std::cin, curso);

        int numeroAsignaturas;
        std::cout << "Ingrese el número de asignaturas: ";
        std::cin >> numeroAsignaturas;
        std::cin.ignore();

        asignaturas.clear(); 

        for (int i = 1; i <= numeroAsignaturas; ++i) {
            std::string asignaturaOrigen, asignaturaDestino;

            std::cout << "Ingrese el ID y nombre de la asignatura " << i << " de la universidad de origen: ";
            std::getline(std::cin, asignaturaOrigen);

            std::cout << "Ingrese el ID y nombre de la asignatura " << i << " de la universidad de destino: ";
            std::getline(std::cin, asignaturaDestino);

            asignaturas.push_back({asignaturaOrigen, asignaturaDestino});
        }

        archivoSalida << id << "-" << numeroPlazas << "\n";
        archivoSalida << universidadOrigen << "-" << universidadDestino << "\n";
        archivoSalida << facultadOrigen << "-" << facultadDestino << "\n";
        archivoSalida << carrera << "-" << duracion << " " << curso << "\n";

        for (const auto& asignatura : asignaturas) {
            archivoSalida << asignatura.first << " - " << asignatura.second << ". ";
        }

        archivoSalida << "\n\n";

        archivoSalida.close();
        std::cout << "Plan de convalidación guardado correctamente.\n";
        return true;
    } else {
        std::cerr << "Error al abrir el archivo.\n";
        return false;
    }
}


std::string formatearLinea(const std::string& titulo, const std::string& valor) {
    std::ostringstream oss;
    oss << std::left << std::setw(35) << titulo << ": " << valor << "\n";
    return oss.str();
}


bool Inscripcion::crearInscripcion(const std::string& archivoPlanes, std::string credencial) {
    std::string idPlan;
    std::cout << "Ingrese el ID del plan al que desea inscribirse: ";
    std::getline(std::cin, idPlan);

    std::ifstream archivoEntrada(archivoPlanes);
    if (!archivoEntrada.is_open()) {
        std::cerr << "Error al abrir el archivo de planes de convalidación." << std::endl;
        return false;
    }

    std::string linea;
    bool planEncontrado = false;
    std::string idLeido, numeroPlazas;
    std::string universidadOrigen, universidadDestino;
    std::string facultadOrigen, facultadDestino;
    std::string carrera, duracion, curso;
    std::string asignaturas;

    while (std::getline(archivoEntrada, linea)) {
        if (linea.empty()) continue;

        size_t guionPos = linea.find('-');
        if (guionPos != std::string::npos) {
            idLeido = linea.substr(0, guionPos);
            numeroPlazas = linea.substr(guionPos + 1);

            if (idLeido == idPlan) {
                planEncontrado = true;

                std::getline(archivoEntrada, linea);
                size_t dashPos = linea.find('-');
                universidadOrigen = linea.substr(0, dashPos);
                universidadDestino = linea.substr(dashPos + 1);

                std::getline(archivoEntrada, linea);
                dashPos = linea.find('-');
                facultadOrigen = linea.substr(0, dashPos);
                facultadDestino = linea.substr(dashPos + 1);

                std::getline(archivoEntrada, linea);
                dashPos = linea.find('-');
                carrera = linea.substr(0, dashPos);
                duracion = linea.substr(dashPos + 1);

                asignaturas.clear();
                while (std::getline(archivoEntrada, linea) && !linea.empty()) {
                    asignaturas += linea + "\n";
                }

                break;
            }
        }
    }

    archivoEntrada.close();

    if (!planEncontrado) {
        std::cerr << "No se encontró el plan con el ID especificado." << std::endl;
        return false;
    }

    std::string dni, nombreCompleto;
    std::cout << "Ingrese el DNI del alumno: ";
    std::getline(std::cin, dni);
    std::cout << "Ingrese el nombre completo del alumno: ";
    std::getline(std::cin, nombreCompleto);

    std::string nombreArchivoInscripcion = idLeido + credencial + "_inscripcion.txt";
    std::ofstream archivoSalida(nombreArchivoInscripcion);

    if (archivoSalida.is_open()) {
        archivoSalida << "===============================================\n";
        archivoSalida << "                INSCRIPCIÓN DE ALUMNO          \n";
        archivoSalida << "===============================================\n\n";

        archivoSalida << "DNI                                : " << dni << "\n";
        archivoSalida << "Credencial Universitaria           : " << credencial << "\n";
        archivoSalida << "Nombre Completo                    : " << nombreCompleto << "\n\n";

        archivoSalida << "===============================================\n";
        archivoSalida << "                DETALLES DEL PLAN              \n";
        archivoSalida << "===============================================\n\n";

        archivoSalida << "ID del Plan                        : " << idLeido << "-" << numeroPlazas << "\n";
        archivoSalida << "Universidades                      : " << universidadOrigen << " - " << universidadDestino << "\n";
        archivoSalida << "Facultades                         : " << facultadOrigen << " - " << facultadDestino << "\n";
        archivoSalida << "Carrera y Duración                 : " << carrera << " - " << duracion << "\n";
        archivoSalida << "Asignaturas                        : \n" << asignaturas << "\n";

        archivoSalida.close();
        std::cout << "Inscripción creada y guardada en " << nombreArchivoInscripcion << std::endl;
    } else {
        std::cerr << "Error al crear el archivo de inscripción." << std::endl;
        return false;
    }
    
    std::time_t now = std::time(nullptr);
    char fecha[20];
    std::strftime(fecha, sizeof(fecha), "%Y-%m-%d", std::localtime(&now));
    std::string nombreArchivoHistorial = credencial + "_historial.txt";
    std::ofstream archivoHistorial(nombreArchivoHistorial, std::ios::app);
    
    if(archivoHistorial.is_open()){
    	archivoHistorial << "Código de plan: " << idLeido << "\n";
    	archivoHistorial << "Fecha de inscripción: " << fecha << "\n";
    	archivoHistorial << "-----------------------------------------------\n";
    	archivoHistorial.close();
    	std::cout << "Historial actualizado";
        return true;
    }
     else { std::cerr << "Error al actualizar el historial de inscripciones.";
        return false;    
    }

}


bool PlanesDeConvalidacion::imprimirPlanesDeConvalidacion(const std::string& archivo) {
    std::ifstream archivoEntrada(archivo);
    if (archivoEntrada.is_open()) {
        std::string linea;
        while (std::getline(archivoEntrada, linea)) {
            std::cout << linea << std::endl;
        }
        archivoEntrada.close();
        std::cout << "\nPlanes de convalidación mostrados correctamente." << std::endl;
        return true;
    } else {
        std::cerr << "Error al abrir el archivo para lectura." << std::endl;
        return false;
    }
}