all: Sudoku.o giveQuestion.o solve.o transform.o
	g++ -o giveQuestion giveQuestion.cpp Sudoku.h Sudoku.cpp
	g++ -o solve solve.cpp Sudoku.h Sudoku.cpp
	g++ -o transform transform.cpp Sudoku.h Sudoku.cpp
Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp
giveQuestion.o: giveQuestion.cpp Sudoku.h
	g++ -c giveQuestion.cpp Sudoku.cpp
solve.o: solve.cpp Sudoku.h
	g++ -c solve.cpp Sudoku.cpp
transform.o: transform.cpp Sudoku.h
	g++ -c transform.cpp Sudoku.cpp
clean:
	rm *.o
