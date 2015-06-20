#include <iostream>
#include <cassert>
#include "stats.h"
#include <math.h>
#include <stdio.h>
using namespace std;

Stats::Stats()
{
	clearData();
}

bool Stats::addVar(double var)
  {
	 if(numVars < MAX_SIZE)
     {	vars[numVars] = var;
        numVars++;
        return true;
     }
	 return false;

  }
void Stats::showData()
{
	for(int i=0; i<numVars;i++)
	{

		cout<<vars[i]<<endl;
	}

}
double Stats::getAverage()
{
	double sum=0.0;
	for(int i=0; i<numVars;i++)
	{

		sum+=vars[i];
	}
	return (sum/numVars);

}
double Stats::findHighest()
{
	double highest=0.0;
	for(int i=0; i<numVars;i++)
	{
		if (highest < vars[i])
		{
			highest = vars[i];
		}
	}
	return highest;
}
double Stats::findLowest()
{
	double lowest = vars[0];
	for(int i=0; i<numVars;i++)
	{
		if (lowest > vars[i])
		{
			lowest = vars[i];
		}
	}
	return lowest;
}
double Stats::calcStdDeviation(double avg)
{
	double variant = 0.0;
	for (int i=0; i<numVars; i++ )
	{
		variant += pow((vars[i] - avg), 2);
	}
	variant = variant / numVars;
	variant = sqrt(variant);

	return variant;
}

