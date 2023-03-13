#pragma once
#include <vector>
using namespace std;

// Add your code here

class Cell {
public:
	Cell(void);
	~Cell(void);

	int SetValue(int sValue);
	int GetValue();
	bool SetIsGiven(bool sGiven);
	bool GetIsGiven();
	void AddCandidateList(int sCandidateNumber);
	void RemoveCandidateList(int sCandidateNumber);
	bool CheckIfInCandidateList(int sCandidateNumber);
	int GetCandidateListSize();
	vector<int> GetCandidateList();
private:
	vector<int> m_candidateList;
	int m_value;
	bool m_given;

};