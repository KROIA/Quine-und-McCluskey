#ifndef Combination_H
#define Combination_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <windows.h>
#include <math.h>

using namespace std;

class Combination
{
	public:
		
		Combination();
		~Combination();
		
		void combinationNumber(vector<int> number);
		void combinationNumber(int number);
		int getCombinationNumber(unsigned int pos);
		vector<int> getCombinationNumber();
		
		void combinationBin(vector<int> bin);
		void combinationBin(int bin);
		int getCombinationBin(unsigned int pos);
		vector<int> getCombinationBin();
		
		void set(vector<int> number,vector<int> bin);
		void get(vector<int> &number,vector<int> &bin);
		
		void marke(bool marked);
		bool marke();
		
		void print();
	
		static void compare(Combination &combination1,Combination &combination2,Combination &outCombination);
	
		
	private:
		vector<int> _combinationNumber;
		vector<int> _combinationBin;
		bool marked;
};
#endif