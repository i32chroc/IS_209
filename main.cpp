#include <iostream>
#include <string>
#include "funcion_planes.h"

int main() {
    PlanesDeConvalidacion plan;
    Inscripcion inscripcion;
    std::string archivoPlanes = "planes_convalidacion.txt";

    // Autenticación y selección de rol
    std::string rol;
    std::string usuario, contrasena, credencial_;

    std::cout << "\n===== AUTENTICACIÓN =====\n";
    std::cout << "Ingrese 'estudiante' o 'administrador': ";
    std::cin >> rol;
    std::cin.ignore();

    if (rol == "administrador") {
        std::cout << "Usuario: ";
        std::cin >> usuario;
        std::cout << "Contraseña: ";
        std::cin >> contrasena;
        if (usuario != "admin" || contrasena != "admin") {
            std::cerr << "Autenticación fallida. Credenciales incorrectas.\n";
            return 1;
        }
    } else if (rol == "estudiante") {
        std::cout << "Ingrese su credencial universitaria: ";
        std::cin >> credencial_;
        std::cin.ignore();
    } else {
        std::cerr << "Rol no válido. Intente nuevamente.\n";
        return 1;
    }

    // Menú principal basado en el rol
    int opcion;
    do {
        if (rol == "estudiante") {
            std::cout << "\n========= MENÚ PARA ESTUDIANTES =========\n";
            std::cout << "1. Imprimir todos los planes de convalidación\n";
            std::cout << "2. Crear una inscripción\n";
            std::cout << "3. Salir\n";
        } else if (rol == "administrador") {
            std::cout << "\n========= MENÚ PARA ADMINISTRADORES =========\n";
            std::cout << "1. Agregar un plan de convalidación\n";
            std::cout << "2. Imprimir todos los planes de convalidación\n";
            std::cout << "3. Salir\n";
        }
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore();

        if (rol == "estudiante") {
            switch (opcion) {
                case 1:
                    plan.imprimirPlanesDeConvalidacion(archivoPlanes);
                    break;
                case 2:
                    inscripcion.crearInscripcion(archivoPlanes, credencial_);
                    break;
                case 3:
                    std::cout << "Saliendo del programa. ¡Hasta luego!\n";
                    break;
                default:
                    std::cout << "Opción no válida. Intente de nuevo.\n";
            }
        } else if (rol == "administrador") {
            switch (opcion) {
                case 1:
                    plan.agregarPlanConvalidacion(archivoPlanes);
                    break;
                case 2:
                    plan.imprimirPlanesDeConvalidacion(archivoPlanes);
                    break;
                case 3:
                    std::cout << "Saliendo del programa. ¡Hasta luego!\n";
                    break;
                default:
                    std::cout << "Opción no válida. Intente de nuevo.\n";
            }
        }
    } while (opcion != 3);

    return 0;
}

