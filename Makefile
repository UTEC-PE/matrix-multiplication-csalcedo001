CXX = g++
CXXFLAGS = -std=c++17
SRC = main.cpp

all: run

main: $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@

run: main
	./$<
