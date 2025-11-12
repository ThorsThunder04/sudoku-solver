CXX=g++
FLAGS=-Wall
TARGETS=main
OBJECTS=main.o solver.o

all: $(TARGETS)

main: $(OBJECTS)
	$(CXX) $? -o $@

solver.o: solver.cpp solver.h
	$(CXX) $(FLAGS) -c solver.cpp

main.o: main.cpp main.h solver.h
	$(CXX) $(FLAGS) -c main.cpp


winclean:
	del *.o
	del *.exe

clean:
	rm *.o
