# Nombre del compilador
CXX = g++
# Flags de compilación
CXXFLAGS = -std=c++17 -Wall -I.

# Directorio de construcción
BUILD_DIR = build

# Nombre del ejecutable
TARGET = $(BUILD_DIR)/main

# Archivos fuente
SOURCES = main.cpp funcion_planes.cpp

# Archivos objeto
OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

# Archivo de datos necesario en la ejecución
DATA_FILE = planes_convalidacion.txt

# Regla principal
all: $(BUILD_DIR) $(TARGET) copy_data

# Crear la carpeta build si no existe
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compilar el ejecutable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilar archivos objeto
$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Copiar archivo de datos al directorio build
copy_data: $(DATA_FILE)
	cp $(DATA_FILE) $(BUILD_DIR)/

# Limpiar los archivos generados
clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)

# Ejecutar el programa
run: $(TARGET)
	./$(TARGET)

