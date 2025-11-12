# === Makefile per progetto "Caserma" ===

# Compilatore
CXX = g++

# Flag di compilazione
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

# Cartelle
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Nome dell'eseguibile finale
TARGET = $(BIN_DIR)/caserma_app

# Tutti i file sorgente (.cpp)
SRCS = $(wildcard $(SRC_DIR)/*.cpp) main.cpp

# Da ogni sorgente genera un oggetto corrispondente in obj/
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# === Regole principali ===

# Regola di default: compila tutto
all: $(TARGET)

# Link finale
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilazione dei .cpp in .o
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Pulizia
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Pulizia totale + ricompilazione
rebuild: clean all

# Esegui il programma
run: $(TARGET)
	./$(TARGET)
