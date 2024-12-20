#ifndef FUNCION_PLANES_H
#define FUNCION_PLANES_H

#include <string>
#include <vector>

class PlanesDeConvalidacion {
private:
    std::string id;
    int numeroPlazas;
    std::string universidadOrigen;
    std::string universidadDestino;
    std::string facultadOrigen;
    std::string facultadDestino;
    std::string carrera;
    int duracion;
    std::string curso;
    std::vector<std::pair<std::string, std::string>> asignaturas;

public:

    std::string getId() const { return id; }
    int getNumeroPlazas() const { return numeroPlazas; }
    std::string getUniversidadOrigen() const { return universidadOrigen; }
    std::string getUniversidadDestino() const { return universidadDestino; }
    std::string getFacultadOrigen() const { return facultadOrigen; }
    std::string getFacultadDestino() const { return facultadDestino; }
    std::string getCarrera() const { return carrera; }
    int getDuracion() const { return duracion; }
    std::string getCurso() const { return curso; }
    std::vector<std::pair<std::string, std::string>> getAsignaturas() const { return asignaturas; }

    void setId(const std::string& nuevoId) { id = nuevoId; }
    void setNumeroPlazas(int nuevoNumero) { numeroPlazas = nuevoNumero; }
    void setUniversidadOrigen(const std::string& universidad) { universidadOrigen = universidad; }
    void setUniversidadDestino(const std::string& universidad) { universidadDestino = universidad; }
    void setFacultadOrigen(const std::string& facultad) { facultadOrigen = facultad; }
    void setFacultadDestino(const std::string& facultad) { facultadDestino = facultad; }
    void setCarrera(const std::string& nuevaCarrera) { carrera = nuevaCarrera; }
    void setDuracion(int nuevaDuracion) { duracion = nuevaDuracion; }
    void setCurso(const std::string& nuevoCurso) { curso = nuevoCurso; }
    void setAsignaturas(const std::vector<std::pair<std::string, std::string>>& nuevasAsignaturas) { asignaturas = nuevasAsignaturas; }

    bool agregarPlanConvalidacion(const std::string& archivo);
    bool imprimirPlanesDeConvalidacion(const std::string& archivo);
};

class Inscripcion {
private:
    std::string dni;
    std::string credencialUniversitaria;
    std::string nombreCompleto;
    PlanesDeConvalidacion plan;

public:
    bool crearInscripcion(const std::string& archivoPlanes, std::string credencial);
};

#endif // FUNCION_PLANES_H
