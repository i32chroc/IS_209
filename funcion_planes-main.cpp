#include <iostream>
#include "funcion_planes.h"

int main() {
    // Crear un objeto de la clase PlanesDeConvalidacion y asignar valores
    PlanesDeConvalidacion plan;

  
    plan.setId("12345");
    plan.setNumeroPlazas(30);
    plan.setUniversidadOrigen("Universidad A");
    plan.setUniversidadDestino("Universidad B");
    plan.setFacultadOrigen("Facultad de Ciencias");
    plan.setFacultadDestino("Facultad de Ingeniería");
    plan.setCarrera("Ingeniería Informática");
    plan.setDuracion(4);
    plan.setCurso("2024-2025");
    plan.setAsignaturas({{"Matemáticas I", "Mathematics I"}, {"Programación", "Programming"}});

    // Llamar al método para agregar un plan de convalidación
    plan.agregarPlanConvalidacion("planes_convalidacion.txt", plan);
    plan.imprimirPlanesDeConvalidacion("planes_convalidacion.txt");

    return 0;
}