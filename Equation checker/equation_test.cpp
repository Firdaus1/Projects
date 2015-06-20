//stack_test.cpp
//CS3358
//tests a very simple cursor based Stack ADT

#include <iostream>
#include<fstream>
#include "stack_3358_LL.h"

using namespace std;

template <typename itemType>
void showStack(Stack_3358 <itemType> & myStack);

int main (int argc, char * argv[]) {
	char temp;
	char temp2;
	char temp3;
	int tru = 1;
	ifstream inputFile;
	string line;
	 Stack_3358<int> myStack;
	Stack_3358<int> myStack2;
	inputFile.open(argv[1]);
	while(getline(inputFile,line ))
	{
		for (int i =0; i <= line.length(); i++)
	{
		cout << line[i];
		if( line[i] == '('  || line[i] == '['  || line[i] == '<' )
 	
		myStack.push(line[i]);
	}
	

	for (int i = line.length(); i > 0; i--)
	{
		if( line[i] == ')'  || line[i] == ']'  || line[i] == '>' )
 
		
		myStack2.push(line[i]);
	}
 
	tru = 1;
while(!myStack.isEmpty() && !myStack2.isEmpty() )
 
 {
 	
  
		temp = myStack.pop();
		temp2 = myStack2.pop();
 	
	
		
			
		
		if ( temp == '(')
		{
			if (temp2 != ')')
			{
			 cout << " == Missing )" <<endl;
			tru = 0;
			break;
		    }
			
		}
		
		if ( temp == '[')
		{
			if (temp2 != ']')
			{
			cout << " == Missing ]" <<endl;
			tru = 0;
			break;
			}
			
		}
		
		if ( temp == '<')
		{
			if (temp2 != '>')
			{
			cout << " == Missing  >" <<endl;
			tru = 0;
		   break;
		   }
			
		}
		
		
}


	if(myStack.isEmpty() && !myStack2.isEmpty())
		{
			
		cout << " === Invalid Equation " << endl; 
		tru =0;
	
		}
	else if(!myStack.isEmpty() && myStack2.isEmpty())
	{
		cout << " === Invalid Equation" << endl; 
		tru = 0;
	}
	
	
	if(tru == 1)
		{
			cout << " == Equation is valid" << endl; 
		}



	    myStack.makeEmpty();
	    myStack2.makeEmpty();
		
	}
 	   
	inputFile.close();
	}    
   
   



