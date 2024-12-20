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

// Prueba para formatear una línea
TEST(PlanesDeConvalidacionTest, FormatearLinea) {
    std::string titulo = "Universidad de origen";
    std::string valor = "Universidad Nacional";
    std::string resultado = formatearLinea(titulo, valor);
    std::string esperado = "Universidad de origen              : Universidad Nacional\n"; // Ajusta el formato esperado
    EXPECT_EQ(resultado, esperado);
}

// Prueba para inscripción con un plan existente
TEST(InscripcionTest, InscripcionPlanExistente) {
    Inscripcion inscripcion;
    std::string archivoPlanes = "planes_test.txt";
    std::string credencial = "123456789";
    EXPECT_TRUE(inscripcion.crearInscripcion(archivoPlanes, credencial));

    std::ifstream archivoInscripcion("02123456789_inscripcion.txt"); // Ajusta el nombre del archivo según los datos de prueba
    EXPECT_TRUE(archivoInscripcion.is_open());
    archivoInscripcion.close();
}

// Prueba para inscripción con un plan no existente
TEST(InscripcionTest, InscripcionPlanNoExistente) {
    Inscripcion inscripcion;
    std::string archivoPlanes = "planes_test.txt";
    std::string credencial = "987654321";
    EXPECT_FALSE(inscripcion.crearInscripcion(archivoPlanes, credencial));
}

// Prueba para leer planes de convalidación
TEST(PlanesDeConvalidacionTest, LeerPlanesDeConvalidacion) {
    PlanesDeConvalidacion plan;
    std::string archivo = "planes_test.txt";
    EXPECT_TRUE(plan.imprimirPlanesDeConvalidacion(archivo));
}

// Prueba para verificar historial de inscripciones
TEST(InscripcionTest, HistorialDeInscripciones) {
    Inscripcion inscripcion;
    std::string archivoPlanes = "planes_test.txt";
    std::string credencial = "123456789";

    EXPECT_TRUE(inscripcion.crearInscripcion(archivoPlanes, credencial));

    std::ifstream archivoHistorial("123456789_historial.txt"); // Ajusta el nombre del archivo según los datos de prueba
    ASSERT_TRUE(archivoHistorial.is_open()) << "No se pudo abrir el archivo de historial.";

    bool encontradoHistorial = false;
    std::string linea;
    while (std::getline(archivoHistorial, linea)) {
        if (linea.find("Inscripción realizada") != std::string::npos) {
            encontradoHistorial = true;
            break;
        }
    }
    archivoHistorial.close();
    EXPECT_TRUE(encontradoHistorial);
}

// Función principal
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}