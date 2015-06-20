#include <iostream>
#include <fstream>
#include "stats.h"
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(int argc, char * argv[])
{
	Stats example;
	int count=0;
	char buff[6];
	int k=0;
	string holder="";
	ifstream infile(argv[1]);
	//from start of file
	string str;
	do {
		infile >> str;

		// cout << ":test" << str << endl; //for testing
	}
	while (str != "MLO"); // till you find MLO

	//from MLO to End of File

	string line = "";
	//WHILE GET YOU NEW LINE
	while (getline(infile, line)){
		count++;
		//cout << line << '\n';

		//TRYS TO GET YOU THE NUMBER (DOUBLE)
		if(count==1)
		{
			for (int i = 13; i <= line.length(); i++)
			{
				holder+= line[i];
				buff[k]=line[i];
				k++;
			}
			float num = atof(buff);
			example.addVar(num);

		}

		else
		{
			k=0;
			holder="";

			for (int i = 16; i <= line.length(); i++)
			{
				holder+= line[i];
				buff[k]=line[i];
				k++;

			}
			float num = atof(buff);
			example.addVar(num);


		}


	}
	cout<<"Data in the array " << endl;
	example.showData();


	cout<<"Average of values in data is ";
	cout<<example.getAverage() << endl;
	double avg = example.getAverage();

	cout << "Highest number in the data is: ";
	cout << example.findHighest() << endl;

	cout << "Lowest number in the data is: ";
	cout << example.findLowest() << endl;

	cout << "Standard deviation is ";
	cout << example.calcStdDeviation(avg) << endl;

}



