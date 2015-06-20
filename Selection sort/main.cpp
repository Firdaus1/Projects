#include <iostream>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void sSort(int array[]);

const int size = 10;

using namespace std;
int main(int argc, char** argv) {
	
	
	int array[size] = {3,7,2,12,56,1,42,9,15,6};
	
			cout << "BEFORE SELECTION SORT" << endl;
	for ( int i = 0; i < size; i++)
	{ 
		cout << array[i] << " ";
  
	}
	
cout << "\n";	
	sSort(array);
		
		
		
		cout << "AFTER SELECTION SORT" << endl;
	for ( int i = 0; i < size; i++)
	{
	
		cout << array[i] << " ";
		
		
	}
	
	
	return 0;
}

void sSort(int array[])
{
	for ( int i =0; i < size-1; i++)
	{
		int j = i+1;
		int t = i;
		if ( array[i]> array[j])
		
		{
			swap(array[i], array[j]);
			while ( array[t] < array[t-1] && t > 0)
			{
			  swap( array[t], array[t-1]);
			  t--;
			}
		}
	}  
	
	
	
	
}
