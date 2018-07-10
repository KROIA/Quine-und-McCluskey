#ifndef GROUP_H
#define GROUP_H



#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <windows.h>
#include <math.h>
#include "combination.h"

using namespace std;

class Group
{
	public:
		
		Group();
		~Group();
		
		void add (Combination com);
		void setNum (unsigned int index,vector <int> Numlist);
		void setBin (unsigned int index,vector <int> Binlist);
		void setMark (unsigned int index, bool marked);
		Combination &get (unsigned int index);
		unsigned int size();
		
		void print();
		
		static void compare(Group &group1,Group &group2,Group &outGroup);

		
	private:
		vector<Combination> combinationList;
		
};

#endif