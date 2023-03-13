#pragma once
#include <fstream>
#include <iostream>
#include "Cell.h"
using namespace std;

// Add your code here

class SudokuPuzzle {
public:
	SudokuPuzzle(void);
	~SudokuPuzzle(void);

	void solve(const char filenameIn[]);

	// Add your code here

private:
	void output();

	void readPuzzle(const char filenameIn[]);
	Cell m_grid[9][9];

	// Add your code here

};