#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <windows.h>
#include <math.h>
#include "group.h"

using namespace std;

FILE *file;
vector<string> fileBuffer;
string filename = "inputFile.txt";

vector<int> array;

vector<string>	inputName;
string outputName;
vector<vector<int>	>_inputData;
vector<vector<vector<int>	>	>inputData;
vector<int> __combination;
vector<int>	outputData;

vector<vector<int>	> termCombination;
vector<vector<int>	> term;

void loadFile();
void sort();
void compare();
void simplify();


void compare_column(int col1,int col2,int &res, int &counter);
void compare_row(vector<int> row1, vector<int> row2,vector<int> &res);

//Group group;

vector<vector<Group>	> groupList;

int main()
{
	/*vector<int> combi;
	vector<int> num;
	Combination combination;
	combination.combinationNumber(1);
	combination.combinationBin(0);
	combination.combinationBin(1);
	combination.combinationBin(0);
	combination.combinationBin(1);
	
	group.add(combination);
	
	for(int b=0; b<group.size(); b++)
	{
		cout << "number: ";
		for(int a=0; a<group.get(b).getCombinationNumber().size(); a++)
		{
			cout<< to_string(group.get(b).getCombinationNumber()[a]) + ",";
		}
		cout<< "\tbin:";
		for(int a=0; a<group.get(b).getCombinationBin().size(); a++)
		{
			if(group.get(b).getCombinationBin()[a] == -1)
			{
				cout<<"-";
			}
			else
			{
				cout<< to_string(group.get(b).getCombinationBin()[a]);
			}
		}
	}
	getchar();*/
	/*while(true)
	{
		for(int a=0; a<rand()%100; a++)
		{
			array.push_back(a);
			cout << "save: " + to_string(array[array.size()-1])+"\n";
		}
		if(array.size() >= 100)
		{
			for(int a=0; a<array.size()-10; a++)
			{
				cout << "delete: " + to_string(array[array.size()-1])+"\n";
				array.pop_back();
			}
		}
		int size = array.size();
	}*/
	loadFile();
	sort();
	compare();
	simplify();
	while(true){}
	return 0;
}

void loadFile()
{
	fileBuffer = vector<string>();
    file = fopen(filename.c_str(),"r");
    if(!file)
    {
        printf("file: %s konnte nicht geoeffnet oder gefunden werden",filename.c_str());
        return;
    }
    else
    {
        char inBuff[255];
        while(!feof(file))
        {
           for(int a=0; a<255; a++)
           {inBuff[a] = NULL;}
            fgets(inBuff,255,file);
            fileBuffer.push_back(inBuff);
        }
        fclose(file);
    }
	
	//a|b|c|d|=|x|
	cout << "inputs: ";
	while(fileBuffer[0].find("|") != -1)
	{
		inputName.push_back(fileBuffer[0].substr(0,fileBuffer[0].find("|")));
		fileBuffer[0] = fileBuffer[0].substr(fileBuffer[0].find("|")+1,fileBuffer[0].size());
		cout  << inputName[inputName.size()-1] + "\t";
		if(fileBuffer[0].find("=|") == 0)
		{
			fileBuffer[0] = fileBuffer[0].substr(fileBuffer[0].find("=|")+2,fileBuffer[0].size());
			outputName = fileBuffer[0].substr(0,fileBuffer[0].find("|"));
			cout << "output:\t" + outputName;
			break;
		}
	}
	cout << "\nData\n";
	for(int a=1; a<fileBuffer.size(); a++)
	{		
		_inputData.push_back(vector<int>());
		for(int b=0; b<inputName.size(); b++)
		{
			int tmpData = atoi(fileBuffer[a].substr(0,fileBuffer[a].find("|")).c_str());
			//cout<<fileBuffer[a].substr(0,fileBuffer[a].find("|"))+"\t";
			fileBuffer[a] = fileBuffer[a].substr(fileBuffer[a].find("|")+1,fileBuffer[a].size());
			_inputData[_inputData.size()-1].push_back(tmpData);
			cout << to_string(_inputData[_inputData.size()-1][b]) + "\t";
		}
		fileBuffer[a] = fileBuffer[a].substr(fileBuffer[a].find("=|")+2,fileBuffer[a].size());
		outputData.push_back(atoi(fileBuffer[a].substr(0,fileBuffer[a].find("|")).c_str()));
		cout << "output:\t"+to_string(outputData[outputData.size()-1])+"\n";
	}
}
void sort()
{
	vector<vector<int>	> new_inputData1;
	vector<vector<vector<int>	>	> new_inputData2;
	for(int a=0; a<outputData.size(); a++)
	{
		if(outputData[a] == true)
		{
			new_inputData1.push_back(_inputData[a]);
		}
	}
	
	vector<int>	anzZero;
	for(int a=0; a<new_inputData1.size(); a++)
	{
		int zeroCounter = 0;
		for(int b=0; b<new_inputData1[a].size(); b++)
		{
			if(new_inputData1[a][b] == false)
			{
				zeroCounter++;
			}
		}
		anzZero.push_back(zeroCounter);
	}
	
	while(true)
	{
		int sortCounter = 0;
		for(int a=1; a<new_inputData1.size(); a++)
		{
			if(anzZero[a-1] < anzZero[a])
			{
				int tmpZero = anzZero[a-1];
				vector<int>	tmpInput = new_inputData1[a-1];
				
				anzZero[a-1] 		= anzZero[a];
				new_inputData1[a-1] 	= new_inputData1[a];
				anzZero[a] 			= tmpZero;
				new_inputData1[a] 	= tmpInput;
			}
			else
			{
				sortCounter++;
			}
		}
		if(sortCounter >= new_inputData1.size()-1)
		{
			break;
		}
	}
	cout << "sorted Data\n";
	for(int a=0; a<new_inputData1.size(); a++)
	{
		for(int b=0; b<new_inputData1[a].size(); b++)
		{
			cout << to_string(new_inputData1[a][b]) + "\t";
		}
		cout << "\n";
	}
	int _anzZero = anzZero[0];
	cout << "*************Combination*************************\n";
	new_inputData2.push_back(vector<vector<int>	>());
	for(int a=0; a<new_inputData1.size(); a++)
	{
		if(_anzZero != anzZero[a])
		{
			new_inputData2.push_back(vector<vector<int>	>());
			_anzZero = anzZero[a];
			cout << "-----------\n";
		}
		new_inputData2[new_inputData2.size()-1].push_back(new_inputData1[a]);
		int __combinationSum = 0;
		for(int b=0; b<new_inputData2[new_inputData2.size()-1][new_inputData2[new_inputData2.size()-1].size()-1].size(); b++)
		{
			__combinationSum+=new_inputData2[new_inputData2.size()-1][new_inputData2[new_inputData2.size()-1].size()-1][b] * pow(2,new_inputData2[new_inputData2.size()-1][new_inputData2[new_inputData2.size()-1].size()-1].size()-(1+b));
			cout << to_string(new_inputData2[new_inputData2.size()-1][new_inputData2[new_inputData2.size()-1].size()-1][b]) +"\t";
		}
		__combination.push_back(__combinationSum);
		cout << "__combination: "+to_string(__combinationSum)+"\n";
	}
	cout << "**********************************************\n";
	inputData = new_inputData2;
	
	groupList.push_back(vector<Group>());
	for(int a=0; a<inputData.size(); a++)
	{
		Group tmpGroup;
		
		for(int b=0; b<inputData[a].size(); b++)
		{
			Combination tmpCombination;
			int __combinationSum = 0;
			for(int c=0; c<inputData[a][b].size(); c++)
			{
				__combinationSum+=inputData[a][b][c] * pow(2,inputData[a][b].size()-(1+c));
				//cout << to_string(new_inputData2[new_inputData2.size()-1][new_inputData2[new_inputData2.size()-1].size()-1][b]) +"\t";
			}
			vector<int> tmpComNr(1,__combinationSum);
			tmpCombination.set(tmpComNr,inputData[a][b]);
			tmpGroup.add(tmpCombination);
		}
		groupList[0].push_back(tmpGroup);
	}
	cout << "GROUPLIST:\n";
	for(int a=0; a<groupList[0].size(); a++)
	{
		groupList[0][a].print();
	}
}
void compare()
{
	cout << "GROUPLIST 1:\n";
	for(int a=0; a<groupList[0].size(); a++)
	{
		groupList[0][a].print();
	}
	for(int a=1; a<groupList[0].size(); a++)
	{
		Group newGroup;
		Group::compare(groupList[0][a-1],groupList[0][a],newGroup);
	}
	cout << "GROUPLIST 2:\n";
	
	
	/*vector<vector<vector<vector<int>	>	>	>secondList;
	secondList.push_back(inputData);
	int counter = 0;
	
	while(true)
	{
		for(int a=1; a<secondList[counter].size(); a++)
		{
			secondList[secondList.size()-1].push_back(vector<vector<int>	>());
			for(int b=0; b<secondList[counter][a].size(); b++)
			{
				for(int c=0; c<secondList[counter][a-1].size(); c++)
				{
					int changes = 0;
					for(int d=0; d<secondList[counter][a-1][c].size(); d++)
					{
						//			x           !=          y        
						if(secondList[counter][a-1][c][d] != secondList[counter][a][b][d])
						{
							changes++;
						}
					}
					if(changes == 1)
					{
						vector<int>	newRow;
						for(int d=0; d<secondList[counter][a-1][c].size(); d++)
						{
							if(secondList[counter][a-1][c][d] != secondList[counter][a][b][d])
							{
								newRow.push_back(-1);
							}
							else
							{
								newRow.push_back(secondList[counter][a-1][c][d]);
							}
						}
						secondList[secondList.size()-1][secondList[secondList.size()-1].size()-1].push_back(newRow);
					}
					else
					{
						
					}
				}
			}
		}
		counter++;
	}
	int res = 0;
	int counter2 = 0;
	compare_column(0,0,res,counter2);*/
}
void simplify()
{
	
}


void compare_column(int col1,int col2,int &res, int &counter)// Spalte vergleichen
{
	if(col1 != col2)
	{
		res  = -1;
		counter++;
	}
}
void compare_row(vector<int> row1, vector<int> row2,vector<int> &res)
{
	int counter = 0;
	
	for(int a=0; a<row1.size(); a++)
	{
		compare_column(row1[a],row2[a],res[a],counter);
	}
}

