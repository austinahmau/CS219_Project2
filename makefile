operation: main.o converter.o
	g++ main.o converter.o -o operation

main.o: main.cpp
	g++ -c main.cpp

converter.o: converter.cpp converter.h
	g++ -c converter.cpp

clean:
	rm *.o operation
