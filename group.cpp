#include "group.h"

Group::Group()
{
	
}
Group::~Group()
{
	
}	
void Group::add (Combination com)
{
	combinationList.push_back(com);
}
void Group::setNum (unsigned int index,vector <int> Numlist)
{
	if(index>= combinationList.size())
	{
		index = combinationList.size()-1;
	}
	
	combinationList[index].combinationNumber(Numlist);
}
void Group::setBin (unsigned int index,vector <int> Binlist)
{
	if(index>= combinationList.size())
	{
		index = combinationList.size()-1;
	}
	
	combinationList[index].combinationBin(Binlist);
}
void Group::setMark (unsigned int index, bool marked)
{
	if(index>= combinationList.size())
	{
		index = combinationList.size()-1;
	}
	
	combinationList[index].marke(marked);
}
Combination &Group::get (unsigned int index)
{
	if(index>= combinationList.size())
	{
		index = combinationList.size()-1;
	}
	return combinationList[index];
}
unsigned int Group::size()
{
	return combinationList.size();
}	
void Group::print()
{
	for(int a=0; a<combinationList.size(); a++)
	{
		combinationList[a].print();
	}
	cout<<"----------------------------\n";
}


void Group::compare(Group &group1,Group &group2,Group &outGroup)
{
	Group tmpGroup;
	for(int a=0; a<group1.size(); a++)
	{
		for(int b=0; b<group2.size(); b++)
		{
			Combination tmpCombination;
			Combination::compare(group1.get(a),group2.get(b),tmpCombination);
			if(tmpCombination.marke() == true)
			{
				tmpGroup.add(tmpCombination);
			}
		}
	}
	outGroup = tmpGroup;
}
























