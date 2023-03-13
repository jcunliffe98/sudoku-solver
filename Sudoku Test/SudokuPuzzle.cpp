#include "SudokuPuzzle.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
using namespace std;


SudokuPuzzle::SudokuPuzzle() {
	// Add code to initialise the SudokuPuzzle object
}

SudokuPuzzle::~SudokuPuzzle()
{

}


void SudokuPuzzle::solve(char const * const sudokuGrid) {
	// Read puzzle from text file
	readPuzzle(sudokuGrid);

	// Get start time
	const auto startTime = chrono::high_resolution_clock::now();

	// Add code to solve the puzzle
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (m_grid[x][y].GetValue() != 0)
			{
				continue;
			}
			else
			{
				for (int row = 0; row < 9; row++)
				{
					int currentValue;
					currentValue = m_grid[row][y].GetValue();
					if (currentValue == 0)
					{
						continue;
					}
					else
					{
						if (m_grid[x][y].CheckIfInCandidateList(currentValue) == true)
						{
							m_grid[x][y].RemoveCandidateList(currentValue);
						}
						else
						{
							continue;
						}
					}
				}
				for (int col = 0; col < 9; col++)
				{
					int currentValue;
					currentValue = m_grid[x][col].GetValue();
					if (currentValue == 0)
					{
						continue;
					}
					else
					{
						if (m_grid[x][y].CheckIfInCandidateList(currentValue) == true)
						{
							m_grid[x][y].RemoveCandidateList(currentValue);
						}
						else
						{
							continue;
						}
					}
				}
				int subGridX = (x / 3) * 3;
				int subGridY = (y / 3) * 3;
				int subGridXEnd = subGridX + 3;
				int subGridYEnd = subGridY + 3;
				for (int a = subGridX; a < subGridXEnd; a++)
				{
					for (int b = subGridY; b < subGridYEnd; b++)
					{
						int currentValue;
						currentValue = m_grid[a][b].GetValue();
						if (currentValue == 0)
						{
							continue;
						}
						else
						{
							if (m_grid[x][y].CheckIfInCandidateList(currentValue) == true)
							{
								m_grid[x][y].RemoveCandidateList(currentValue);
							}
							else
							{
								continue;
							}
						}
					}
				}
			}
		}
	}
	bool isSolved;
	do
	{
		isSolved = true;
		for (int y2 = 0; y2 < 9; y2++)
		{
			for (int x2 = 0; x2 < 9; x2++)
			{
				if ((m_grid[x2][y2].GetValue() == 0) && (m_grid[x2][y2].GetCandidateListSize() == 1))
				{
					isSolved = false;
					vector<int> candidateList;
					candidateList = m_grid[x2][y2].GetCandidateList();
					m_grid[x2][y2].SetValue(candidateList[0]);
					for (int row = 0; row < 9; row++)
					{
						if (m_grid[row][y2].CheckIfInCandidateList(candidateList[0]) == true)
						{
							m_grid[row][y2].RemoveCandidateList(candidateList[0]);
						}
					}
					for (int col = 0; col < 9; col++)
					{
						if (m_grid[x2][col].CheckIfInCandidateList(candidateList[0]) == true)
						{
							m_grid[x2][col].RemoveCandidateList(candidateList[0]);
						}
					}
					int subGridX = (x2 / 3) * 3;
					int subGridY = (y2 / 3) * 3;
					int subGridXEnd = subGridX + 3;
					int subGridYEnd = subGridY + 3;
					for (int a = subGridX; a < subGridXEnd; a++)
					{
						for (int b = subGridY; b < subGridYEnd; b++)
						{
							if (m_grid[a][b].CheckIfInCandidateList(candidateList[0]) == true)
							{
								m_grid[a][b].RemoveCandidateList(candidateList[0]);
							}
						}
					}
				}
				else if (m_grid[x2][y2].GetValue() == 0)
				{
					isSolved = false;
					bool occursInList = false;
					int hiddenSingle;
					vector<int> candidateList2;
					candidateList2 = m_grid[x2][y2].GetCandidateList();
					for (int size = 0; size < candidateList2.size(); size++)
					{
						for (int row2 = 0; row2 < 9; row2++)
						{
							if (row2 == x2)
							{
								continue;
							}
							else if (m_grid[row2][y2].CheckIfInCandidateList(candidateList2[size]) == true)
							{
								occursInList = true;
							}
						}
						for (int col2 = 0; col2 < 9; col2++)
						{
							if (col2 == y2)
							{
								continue;
							}
							else if (m_grid[x2][col2].CheckIfInCandidateList(candidateList2[size]) == true)
							{
								occursInList = true;
							}
						}
						int subGridX2 = (x2 / 3) * 3;
						int subGridY2 = (y2 / 3) * 3;
						int subGridXEnd2 = subGridX2 + 3;
						int subGridYEnd2 = subGridY2 + 3;
						for (int a2 = subGridX2; a2 < subGridXEnd2; a2++)
						{
							for (int b2 = subGridY2; b2 < subGridYEnd2; b2++)
							{
								if (a2 == x2 && b2 == y2)
								{
									continue;
								}
								else if (m_grid[a2][b2].CheckIfInCandidateList(candidateList2[size]) == true)
								{
									occursInList = true;
								}
							}
						}
						if (occursInList == false)
						{
							hiddenSingle = candidateList2[size];
							cout << "hidden single: " << hiddenSingle;
						}
					}

				}
				//naked single
			}
		}
	} while (isSolved == false);


	// Get end time
	const auto endTime = chrono::high_resolution_clock::now();
	const auto duration = (endTime - startTime).count();

	// Sample timing output in nanoseconds
	cout << duration << "ns" << endl;

	// Output the solved puzzle
	output();
}


void SudokuPuzzle::readPuzzle(char const * const sudokuGrid) {
	ifstream fin(sudokuGrid);
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			int value;
			fin >> value;
			m_grid[x][y].SetValue(value);
			if (value != 0)
			{
				m_grid[x][y].SetIsGiven(true);
			}
			else
			{
				m_grid[x][y].SetIsGiven(false);
			}
		}
	}
	fin.close();
}


void SudokuPuzzle::output() {
	// Add code to output your solved puzzle
	ofstream fout("sudoku_solution.txt");
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			fout << m_grid[x][y].GetValue();
			fout << " ";
		}
		fout << "\n";
	}
	fout.close();
}