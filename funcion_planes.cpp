#include <iostream>
#include <fstream>
#include "funcion_planes.h"

void PlanesDeConvalidacion::agregarPlanConvalidacion(const std::string& archivo, PlanesDeConvalidacion plan) {
    std::ofstream archivoSalida(archivo, std::ios::app);
    if (archivoSalida.is_open()) {
        archivoSalida << plan.getId() << " " << plan.getNumeroPlazas() << "\n";
        archivoSalida << plan.getUniversidadOrigen() << " " << plan.getUniversidadDestino() << "\n";
        archivoSalida << plan.getFacultadOrigen() << " - " << plan.getFacultadDestino() << "\n";
        archivoSalida << plan.getCarrera() << " " << plan.getDuracion() << " " << plan.getCurso() << "\n";
        for (const auto& asignatura : plan.getAsignaturas()) {
            archivoSalida << asignatura.first << "-" << asignatura.second << ". ";
        }
        archivoSalida << "\n\n";

        archivoSalida.close();
        std::cout << "Plan de convalidación guardado correctamente." << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo." << std::endl;
    }
}

void PlanesDeConvalidacion::imprimirPlanesDeConvalidacion(const std::string& archivo) {
    std::ifstream archivoEntrada(archivo);
    if (archivoEntrada.is_open()) {
        std::string linea;
        while (std::getline(archivoEntrada, linea)) {
            std::cout << linea << std::endl;
        }
        archivoEntrada.close();
        std::cout << "\nPlanes de convalidación mostrados correctamente." << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo para lectura." << std::endl;
    }
}