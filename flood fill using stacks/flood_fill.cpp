#include <iostream>
#include <fstream>
#include "stack_3358_LL.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main (int argc, char * argv[]) {

	ifstream inputFile;
	string line;


	Stack_3358<coor> myStack;
	inputFile.open(argv[1]);
	int row_Number = 0;	
	int col_Number = 0;



	char position[MAX_SIZE][MAX_SIZE];
	while(getline(inputFile,line ))
	{


		for (int i =0; i <line.length(); i++)
		{


			position[row_Number][i] = line[i];

		}
		row_Number ++;
		col_Number = line.length();

	}

	for (int k = 0 ; k < row_Number; k++ )
	{
		for (int f = 0; f < col_Number; f++)
		{
			cout << position[k][f];	
		}
		cout << endl;
	}
	cout << endl;

	int user_Row=0;
	int user_Col=0;						//SHOULD I ADD ERROR CHEKER???
	char user_Color;



	char current_Color;


	while(user_Row != -1)
	{

		cout << "Enter a row: "; 
		cin >> user_Row;
		if(user_Row > row_Number-1)
		{
			cout << endl;
			cout << "Invalid input. Range for row is 0 - " << row_Number-1 << endl; 
			cout << "Enter a row: ";
			cin >> user_Row;
		}
		cout << "Enter a column: ";
		cin >> user_Col;
		if(user_Col > col_Number-1)
		{   
			cout << endl;
			cout << "Invalid input. Range for column is 0 - " << col_Number-1 << endl; 
			cout << "Enter a column: ";
			cin >> user_Col;
		}
		cout << "Enter a color: "; 
		cin >> user_Color;

		current_Color = position[user_Row][user_Col];

		coor xy;
		xy.row = user_Row;
		xy.col = user_Col;
		myStack.push(xy);



		while(!myStack.isEmpty())
		{    
			coor temp1 = myStack.pop();

			position[temp1.row][temp1.col] = user_Color;

			if(temp1.col>0)
			{

				if (position[temp1.row][temp1.col-1] == current_Color)			//checks left side of the position	
				{
					coor temp;
					temp.row = temp1.row;
					temp.col=temp1.col;


					temp.col = temp.col-1; 
					myStack.push(temp);
				}
			}


			if(temp1.row>0)
			{
				if(position[temp1.row-1][temp1.col] == current_Color)	// checks above the position
				{
					coor temp;
					temp.row = temp1.row;
					temp.col=temp1.col;


					temp.row = temp.row-1;
					myStack.push(temp);
				}
			}

			//	if(temp1.col < col_Number-1)
			if(temp1.col < col_Number)
			{

				if(position[temp1.row][temp1.col+1] == current_Color)  	// checks right side of the position
				{

					coor temp;
					temp.row = temp1.row;
					temp.col=temp1.col;

					temp.col = temp.col+1;

					myStack.push(temp);
				}

			}

			//	if(temp1.row < row_Number-1)
			if(temp1.row < row_Number)
			{

				if(position[temp1.row+1][temp1.col] == current_Color)	// checks below the position
				{
					coor temp;
					temp.row = temp1.row;
					temp.col=temp1.col;


					temp.row ++;
					myStack.push(temp);
				}


			}


			//  cout << " row and col before checking upper left diag " << temp1.row << " " << temp1.col << endl;

			if(temp1.row>0 && temp1.col >0 )
			{

				if (position[temp1.row-1][temp1.col-1] == current_Color)	// checks upper left diagonal
				{
					coor temp;
					temp.row = temp1.row;
					temp.col=temp1.col;


					temp.row--;
					temp.col--; 
					myStack.push(temp);	
				}

			}



			//  if(temp.row< row_Number-1 && temp.col >0 )
			//if(temp1.row< row_Number && temp1.col >0 )
			if(temp1.row >0 && temp1.col >0 )
			{
				if(position[temp1.row+1][temp1.col-1] == current_Color)	// checks lower left diagonal
				{
					coor temp;
					temp.row = temp1.row;
					temp.col=temp1.col;


					temp.row++;
					temp.col--;
					myStack.push(temp);	
				}
			}

			//  if(temp.row> 0 && temp.col < col_Number-1  )
			if(temp1.row> 0 && temp1.col < col_Number)
			{


				if(position[temp1.row-1][temp1.col+1] == current_Color)	// checks upper right diagonal
				{

					coor temp;
					temp.row = temp1.row;
					temp.col=temp1.col;


					temp.col++;
					temp.row--; 
					myStack.push(temp);
				}

			}
			//	if(temp.row < row_Number-1  && temp.col < col_Number-1  )
			if(temp1.row < row_Number  && temp1.col < col_Number)
			{

				if(position[temp1.row+1][temp1.col+1] == current_Color)	// checks lower right diagonal

				{
					coor temp;
					temp.row = temp1.row;
					temp.col=temp1.col;


					temp.row++;
					temp.col++;
					myStack.push(temp);	
				}
			}

		}

		cout << endl; 
		for (int k = 0 ; k < row_Number; k++ )
		{
			for (int f = 0; f < col_Number; f++)
			{
				cout << position[k][f];	
			}
			cout << endl; 
		}
			cout << endl; 

	}     

	inputFile.close();


}


