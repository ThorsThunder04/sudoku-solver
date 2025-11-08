CXX = g++
FLAGS = -Wall


solver: solver.cpp
	$(CXX) $(FLAGS) $@.cpp -o $@

winclean:
	del *.o

clean:
	rm *.o
