#include <iostream>
#include <fstream>
#include <string>
#include <gtest/gtest.h>
#include "funcion_planes.h"

// Declaración de la función formatearLinea
std::string formatearLinea(const std::string& titulo, const std::string& valor);

// Prueba para agregar un plan de convalidación
TEST(PlanesDeConvalidacionTest, AgregarPlanConvalidacion) {
    PlanesDeConvalidacion plan;
    std::string archivo = "planes_test.txt";

    // Simula la entrada del usuario
    std::istringstream input("02-3\n30\nUniversidad A\nUniversidad B\nFacultad X\nFacultad Y\nIngeniería\n4\n2024\n2\nMatemáticas I - Matemáticas A\nFísica I - Física A\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_TRUE(plan.agregarPlanConvalidacion(archivo));

    std::ifstream archivoEntrada(archivo);
    ASSERT_TRUE(archivoEntrada.is_open()) << "No se pudo abrir el archivo.";

    std::string linea;
    bool encontrado = false;
    while (std::getline(archivoEntrada, linea)) {
        if (linea.find("02-3") != std::string::npos) { // Ajusta el ID y número de plazas según los datos de prueba
            encontrado = true;
            break;
        }
    }
    archivoEntrada.close();
    EXPECT_TRUE(encontrado);
}

// Prueba para agregar un plan de convalidación a un archivo que no existe y no se puede crear
TEST(PlanesDeConvalidacionTest, AgregarPlanConvalidacionArchivoNoExistente) {
    PlanesDeConvalidacion plan;
    std::string archivo = "/ruta/no/existente/planes_test.txt";

    // Simula la entrada del usuario
    std::istringstream input("02-3\n30\nUniversidad A\nUniversidad B\nFacultad X\nFacultad Y\nIngeniería\n4\n2024\n2\nMatemáticas I - Matemáticas A\nFísica I - Física A\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(plan.agregarPlanConvalidacion(archivo));
}

// Prueba para formatear una línea
TEST(PlanesDeConvalidacionTest, FormatearLinea) {
    std::string titulo = "Universidad de origen";
    std::string valor = "Universidad Nacional";
    std::string resultado = formatearLinea(titulo, valor);
    std::string esperado = "Universidad de origen              : Universidad Nacional\n"; // Ajusta el formato esperado
    EXPECT_EQ(resultado, esperado);
}

// Prueba para leer planes de convalidación
TEST(PlanesDeConvalidacionTest, LeerPlanesDeConvalidacion) {
    PlanesDeConvalidacion plan;
    std::string archivo = "planes_test.txt";
    EXPECT_TRUE(plan.imprimirPlanesDeConvalidacion(archivo));
}

// Prueba para leer planes de convalidación no existente
TEST(PlanesDeConvalidacionTest, LeerPlanesDeConvalidacionNoexistente) {
    PlanesDeConvalidacion plan;
    std::string archivo = "/ruta/no/existente/planes_test.txt";
    EXPECT_FALSE(plan.imprimirPlanesDeConvalidacion(archivo));
}

TEST(PlanesDeConvalidacionTest, FormatearLineaerror) {
    std::string titulo = "Facultad de Ciencias";
    std::string valor = "Universidad Central";
    std::string resultado = formatearLinea(titulo, valor);
    std::string esperado = "Facultad de Ciencias       : Universidad Global\n"; // Se cambian ambos valores
    EXPECT_NE(resultado, esperado); // Compara que los valores sean diferentes
}

// Función principal
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::GTEST_FLAG(output) = "none"; // Desactiva la salida detallada de Google Test
    int result = RUN_ALL_TESTS();
    if (result == 0) {
        std::cout << "Todas las pruebas se han pasado correctamente." << std::endl;
    }
    return result;
}