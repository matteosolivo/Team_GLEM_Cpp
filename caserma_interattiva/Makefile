CXX = g++

CXXFLAGS = -std=c++17 -Wall -Iinclude
# Directory per i file sorgente
SRC_DIR = src
# Directory per i file oggetto
OBJ_DIR = obj
# Directory per i file binari
BIN_DIR = bin

# TARGET é il nostro eseguibile
TARGET = $(BIN_DIR)/caserma

# Creazione delle nostre variabili SRC

# Spazio per aggiungere altri file sorgente
SRC = $(wildcard $(SRC_DIR)/*.cpp) main.cpp

# Trasformazione dei file sorgente in file oggetto
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
# target di default
all: setup $(TARGET)

#mkdir -p crea la cartella solo se non esiste (e crea anche le sottocartelle)
setup:
	@mkdir -p $(OBJ_DIR)/$(SRC_DIR)
	@mkdir -p $(BIN_DIR)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilazione
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

#'rm -rf' è il comando standard per rimuovere cartelle e file forzatamente e ricorsivamente
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

#'./' davanti se il percorso è relativo o per chiarezza
run: all
	./$(TARGET)
