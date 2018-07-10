#include "combination.h"

Combination::Combination()
{
	marked = false;
}
Combination::~Combination()
{
	_combinationNumber.clear();
	_combinationBin.clear();
}
void Combination::combinationNumber(vector<int> number)
{
	_combinationNumber = number;
}
void Combination::combinationNumber(int number)
{
	_combinationNumber.push_back(number);
}
int Combination::getCombinationNumber(unsigned int pos)
{
	if(pos>= _combinationNumber.size())
	{
		pos = _combinationNumber.size()-1;
	}
	return _combinationNumber[pos];
}
vector<int> Combination::getCombinationNumber()
{
	return _combinationNumber;
}
void Combination::combinationBin(vector<int> bin)
{
	_combinationBin = bin;
}
void Combination::combinationBin(int bin)
{
	_combinationBin.push_back(bin);
}
int Combination::getCombinationBin(unsigned int pos)
{
	if(pos>= _combinationBin.size())
	{
		pos = _combinationBin.size()-1;
	}
	return _combinationBin[pos];
}
vector<int> Combination::getCombinationBin()
{
	return _combinationBin;
}
void Combination::set(vector<int> number,vector<int> bin)
{
	combinationNumber(number);
	combinationBin(bin);
}
void Combination::get(vector<int> &number,vector<int> &bin)
{
	number = getCombinationNumber();
	bin = getCombinationBin();
}
void Combination::marke(bool marked)
{
	this->marked = marked;
}
bool Combination::marke()
{
	return marked;
}
void Combination::print()
{
	cout<<"Nr: ";
	for(int a=0; a<_combinationNumber.size(); a++)
	{
		cout<<to_string(_combinationNumber[a])+",";
	}
	cout<<"\t Bin: ";
	for(int a=0; a<_combinationBin.size(); a++)
	{
		if(_combinationBin[a] == -1)
		{
			cout<<"-";
		}
		else
		{
			cout<<to_string(_combinationBin[a]);
		}
	}
	cout<<"\n";
}



void Combination::compare(Combination &combination1,Combination &combination2,Combination &outCombination)
{
	if(combination1.getCombinationBin().size() == combination2.getCombinationBin().size())
	{
		outCombination.set(vector<int>(),vector<int>());
		Combination tmpCombination;
		unsigned int changeCounter = 0;
		for(int a=0; a<combination1.getCombinationBin().size(); a++)
		{
			if(combination1.getCombinationBin()[a] != combination2.getCombinationBin()[a])
			{
				tmpCombination.combinationBin(-1);
				changeCounter++;
			}
			else
			{
				tmpCombination.combinationBin(combination1.getCombinationBin()[a]);
			}
		}
		if(changeCounter == 1)
		{
			combination1.marke(false);
			combination2.marke(false);
			//tmpCombination.marke(true);
			outCombination = tmpCombination;
		}
		else
		{
			combination1.marke(true);
			combination2.marke(true);
		}
	}
}