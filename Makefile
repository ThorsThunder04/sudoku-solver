CXX=g++
FLAGS=-Wall
TARGETS=solver

all: $(TARGETS)

solver: solver.o
	$(CXX) $< -o $@

solver.o: solver.cpp solver.h
	$(CXX) $(FLAGS) -c solver.cpp

winclean:
	del *.o
	del *.exe

clean:
	rm *.o
