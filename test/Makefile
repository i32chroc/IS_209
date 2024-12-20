# Nombre del compilador
CXX = g++
# Flags de compilación
CXXFLAGS = -std=c++17 -Wall -I/usr/include/gtest -I.

# Flags de linkeo
LDFLAGS = -lgtest -lgtest_main -lpthread

# Directorio de construcción
BUILD_DIR = build

# Nombre del ejecutable
TARGET = $(BUILD_DIR)/test

# Archivos fuente
SOURCES = test.cpp funcion_planes.cpp

# Archivos objeto
OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

# Regla principal
all: $(BUILD_DIR) $(TARGET)

# Crear la carpeta build si no existe
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compilar el ejecutable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Compilar archivos objeto
$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar los archivos generados
clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)

# Ejecutar las pruebas
run: $(TARGET)
	./$(TARGET)

