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
# Trova tutti i .cpp in src/ e aggiunge main.cpp
SRC = $(wildcard $(SRC_DIR)/*.cpp) main.cpp

# Trasformazione dei file sorgente in file oggetto
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

# target di default
all: setup $(TARGET)

# mkdir -p crea la cartella solo se non esiste
setup:
	@mkdir -p $(BIN_DIR)
# La cartella obj viene creata dinamicamente durante la compilazione, 
# ma se vuoi crearla qui per sicurezza:
	@mkdir -p $(OBJ_DIR)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilazione
# La regola generica gestisce sia main.cpp che src/*.cpp
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

run: all
	./$(TARGET)