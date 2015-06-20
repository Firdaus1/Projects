#include <iostream>
#include <algorithm>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void quickSort(int begin, int j, int array[]);
int const SIZE = 8;


int main(int argc, char** argv) {
	
	int array[] = {3,8,7,6,5,4,3,2,1};
	     
	
	quickSort(0, SIZE-1, array);

	for (int i = 0; i < SIZE; i ++)
	{
		 cout << array[i];
		 cout << "    " ;
		 
	} 
	
	return 0;
}


void quickSort(int begin, int j, int array[])
{
	int k =0;
	int p = array[begin];
	int i = begin +1;
 
  
 if(i+1 == j )
 {
 	if(array[i+1] > array[j])
 	array[j] = array[i+1];
 	
 	else
 	array[i+1] = array[j];
 	 
 	
 }

 else if ( i==j)
 
 {
 	
 
 while (i!=j)
 {
 
	 while ( array[i] < p)
	 {
	 	i++;
	 	cout << " 1st while " << endl; 
	 	
	 }
	 
	 while (array[j] > p)
	 {
	 	j--;
	 }
	 
	 
	
	 swap(array[i],array[j]);
}

if(p!= array[j-1])
swap(array[p], array[j-1]);
}

//left
cout << " before r call " << endl; 

quickSort(0, j-2, array);
//right 

quickSort(j+1, SIZE-1, array);

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
