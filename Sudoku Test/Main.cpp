#include "SudokuPuzzle.h"
#include "Cell.h"
#include <iostream>
#include <fstream>

int main(int args, char **argv) {
	SudokuPuzzle puzzle;
	Cell cell;
	puzzle.solve("sudoku_puzzle.txt");

	return 0;
}
