GameOfLife: main.o Cell_t.o Board_t.o 
	g++ main.o Cell_t.o Board_t.o  -o GameOfLife

main.o: src/main.cc
	g++ -c src/main.cc

Cell_t.o: src/Cell_t.cc inc/Cell_t.h
	g++ -c src/Cell_t.cc

Board_t.o: src/Board_t.cc inc/Board_t.h
	g++ -c src/Board_t.cc


clean:
	rm *.o GameOfLife

