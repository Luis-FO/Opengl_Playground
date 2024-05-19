TARGET = meu_programa

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

CXX = g++
CXXFLAGS = -std=c++17 -I $(INC_DIR) -Wall

LIBS = -lGL -lGLU -lglut

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# src/RotatingSquare.cpp src/Shapes.cpp

OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
# obj/RotatingSquare.o obj/Shapes.o

all: $(TARGET)

$(TARGET): $(OBJS)
# g++ -o meu_programa obj/RotatingSquare.o obj/Shapes.o -lGL -lGLU -lglut
	$(CXX) -o $@ $^ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
# g++ -std=c++17 -I include -Wall -c src/RotatingSquare.cpp -o obj/RotatingSquare.o
# g++ -std=c++17 -I include -Wall -c src/Shapes.cpp -o obj/Shapes.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)
