a.out: main.o StackType.o
	g++ -g -Wall main.o StackType.o

main.o: main.cpp StackType.hpp
	g++ -c -std=c++20 main.cpp

StackType.o: StackType.cpp
	g++ -c -std=c++20 StackType.cpp

clean:
	rm -f *.o core a.out