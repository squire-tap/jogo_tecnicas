CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

BIN     := bin
SRC     := src
INCLUDE := include

LIBRARIES   := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
EXECUTABLE  := main


#LDFLAGS := "-L/home/luis/SFML-2.5.1/lib"
#CPPFLAGS := "-L/home/luis/SFML-2.5.1/include"

all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I $(INCLUDE) $^ -o $@ $(LIBRARIES)


clean:
	-rm $(BIN)/*