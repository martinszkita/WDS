######GPT GENERATED######
SRC_DIR := src
INC_DIR := inc
OBJ_DIR := obj
OUTPUT_DIR := .

# Ta linijka używa funkcji wildcard, 
# aby znaleźć wszystkie pliki źródłowe (.cpp) w katalogu określonym przez zmienną SRC_DIR
# i przypisuje je do zmiennej CPP_FILES.
CPP_FILES := $(wildcard $(SRC_DIR)/*.cpp) 

# Ta linijka używa funkcji patsubst, 
# aby wygenerować listę plików obiektowych z listy plików źródłowych. 
# Podstawia ona ścieżkę katalogu obiektowego ($(OBJ_DIR)) 
# za katalog źródłowy ($(SRC_DIR)) oraz zmienia rozszerzenie pliku na .o
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(CPP_FILES))

output: $(OBJ_FILES)
# Ta linijka jest regułą kompilacji dla pliku wyjściowego. 
# $^ oznacza listę zależności (pliki obiektowe), a $@ oznacza nazwę celu (plik wyjściowy). 
# Ten wiersz kompiluje pliki obiektowe do pliku wyjściowego output
	g++ $^ -o $(OUTPUT_DIR)/output

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(OUTPUT_DIR)/output
