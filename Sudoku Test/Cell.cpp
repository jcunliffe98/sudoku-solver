#include "Cell.h"
#include <vector>
using namespace std;

Cell::Cell()
{
	for (int x = 1; x <= 9; x++)
	{
		m_candidateList.push_back(x);
	}
}

Cell::~Cell()
{

}

int Cell::GetValue()
{
	return m_value;
}

int Cell::SetValue(int inValue)
{
	return m_value = inValue;
}

bool Cell::SetIsGiven(bool inGiven)
{
	if (inGiven == true)
	{
		return m_given = true;
	}
	else
	{
		return m_given = false;
	}
}

bool Cell::GetIsGiven()
{
	return m_given;
}

void Cell::AddCandidateList(int inCandidateNumber)
{
	m_candidateList.push_back(inCandidateNumber);
}

void Cell::RemoveCandidateList(int inCandidateNumber)
{
	for (int x = 0; x < m_candidateList.size(); x++)
	{
		if (m_candidateList[x] == inCandidateNumber)
		{
			m_candidateList.erase(m_candidateList.begin() + x);
			return;
		}
	}

}

bool Cell::CheckIfInCandidateList(int inCandidateNumber)
{
	for (int x = 0; x < m_candidateList.size(); x++)
	{
		if (m_candidateList[x] == inCandidateNumber)
		{
			return true;
		}
	}
	return false;
}

vector<int> Cell::GetCandidateList()
{
	return m_candidateList;
}

int Cell::GetCandidateListSize()
{
	return m_candidateList.size();
}