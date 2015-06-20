// By Firdaus Botirzoda

#include <iostream>
#include <fstream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

const int MAX_SIZE = 25;
struct coor
{
	int row;
	int col;
		
}; 

void pixel (char current_Color, char position[MAX_SIZE][MAX_SIZE], coor xy, char user_Color, coor original_Array_Dimensions);
 
 
int main (int argc, char * argv[]) {

	ifstream inputFile;
	string line;
 
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
	int user_Col=0;					 
	char user_Color;
 
	char current_Color;
 while (user_Col!= -1 && user_Row != -1)
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
 
 		coor original_Array_Dimensions;
 		original_Array_Dimensions.row = row_Number;
 		original_Array_Dimensions.col = col_Number;
 
 		cout << endl;
     	pixel (current_Color,position,xy,user_Color,original_Array_Dimensions);
     
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
 
void pixel (char current_Color, char position[MAX_SIZE][MAX_SIZE], coor xy, char user_Color, coor original_Array_Dimensions)
{
 	
	int row_Number = original_Array_Dimensions.row;
	int col_Number = original_Array_Dimensions.col; 
 
	coor temp1;
    temp1.row = xy.row;
	temp1.col = xy.col;
    position[temp1.row][temp1.col] = user_Color;
 
			if(temp1.col>0)
			{

				if (position[temp1.row][temp1.col-1] == current_Color)			//checks left side of the position	
				{
					coor temp;
					temp.row = temp1.row;
					temp.col=temp1.col;


					temp.col = temp.col-1; 
					pixel(current_Color, position, temp, user_Color, original_Array_Dimensions);
	 
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
					pixel(current_Color, position, temp, user_Color, original_Array_Dimensions);
		 
				}
			}
 
			if(temp1.col < col_Number)
			{

				if(position[temp1.row][temp1.col+1] == current_Color)  	// checks right side of the position
				{

					coor temp;
					temp.row = temp1.row;
					temp.col=temp1.col;

					temp.col = temp.col+1;
					pixel(current_Color, position, temp, user_Color, original_Array_Dimensions);
 
				}

			}
 
			if(temp1.row < row_Number)
			{

				if(position[temp1.row+1][temp1.col] == current_Color)	// checks below the position
				{
					coor temp;
					temp.row = temp1.row;
					temp.col=temp1.col;


					temp.row ++;
					pixel(current_Color, position, temp, user_Color, original_Array_Dimensions);
	 
				}
 
			}
 
			if(temp1.row>0 && temp1.col >0 )
			{

				if (position[temp1.row-1][temp1.col-1] == current_Color)	// checks upper left diagonal
				{
					coor temp;
					temp.row = temp1.row;
					temp.col=temp1.col;


					temp.row--;
					temp.col--; 
					pixel(current_Color, position, temp, user_Color, original_Array_Dimensions);
 
				}

			}
 
			if(temp1.row >0 && temp1.col >0 )
			{
				if(position[temp1.row+1][temp1.col-1] == current_Color)	// checks lower left diagonal
				{
					coor temp;
					temp.row = temp1.row;
					temp.col=temp1.col;


					temp.row++;
					temp.col--;
				    pixel(current_Color, position, temp, user_Color, original_Array_Dimensions);
 
				}
			}

		 
			if(temp1.row> 0 && temp1.col < col_Number)
			{
 
				if(position[temp1.row-1][temp1.col+1] == current_Color)	// checks upper right diagonal
				{

					coor temp;
					temp.row = temp1.row;
					temp.col=temp1.col;


					temp.col++;
					temp.row--; 
				    pixel(current_Color, position, temp, user_Color, original_Array_Dimensions);
				 
				}

			}
			 
			if(temp1.row < row_Number  && temp1.col < col_Number)
			{

				if(position[temp1.row+1][temp1.col+1] == current_Color)	// checks lower right diagonal

				{
					coor temp;
					temp.row = temp1.row;
					temp.col=temp1.col;


					temp.row++;
					temp.col++;
				    pixel(current_Color, position, temp, user_Color, original_Array_Dimensions);
			 
				}
			}
	}    
 
