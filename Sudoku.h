#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Sudoku{
	public:
		Sudoku();
		void giveQuestion();
		void readIn();
		void solve();
		void changeNum(int a,int b);
		void changeRow(int a,int b);
		void changeCol(int a,int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		int checkRow(int sp);
		int checkCol(int sp);
		int checkCell(int sp);
		int check(int sp);
		int getBlank(int i);
		int pop();
		void push(int sp);
		static const int sudokuSize = 81;

	private:
		int map[sudokuSize];
		int pos[sudokuSize];
		int p;
};
