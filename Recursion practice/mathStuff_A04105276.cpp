/* mathStuff_xxxxxx.cpp

by Firdaus Botirzoda
 
 
*/

#include <iostream>
#include <fstream>
#include <math.h>


using namespace std;

//**********  Function Prototypes  ******************

//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//
 

bool isPrime (int number);


void FactorHelper(int number, int START_DIVISOR);
 
bool CheckPrime (int number,int divisor);

//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n. 

void printPrimes (int n);


//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0 
//Fib(1) -> 1 
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n);


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number);


//******************  MAIN  *****************************

int main () {
    
    char continu;
    int testNum;
   
while ( continu != 'n' && continu != 'N')
   {
    
    //test for the isPrime function
    cout << "Enter a test number - ";
    cin >> testNum;
    cout << endl;
    
    if (isPrime(testNum))
       cout << testNum << " is prime." << endl;
    else
       cout << testNum << " is not prime." << endl;
       
    cout << endl;
	    
    //test for printing primes
    cout << "Enter n to print the prime numbers between 1 and n: ";
    cin >> testNum;
    cout << endl;
    
    printPrimes(testNum);
    
    cout << endl << endl; 
    
    //test for Fibonacci number finder
    cout << "Which Fibonacci number? ";
    cin >> testNum;
    cout << endl;
    
    cout << "The " << testNum << " Fibonacci number is : " << findFibo(testNum) << endl;
    
    cout << endl;
    
    //test for prime factors
    cout << "Factor what number: ";
    cin >> testNum;
    cout << endl;
    
    findFactors(testNum);
    
    cout << endl; 
    cout << "Continue ? enter y for yes, n for no: ";
    cin >> continu;
    cout << endl; 
    }
  
    return 0;
}




//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//
bool isPrime(int number)
{
	if (number == 1)
	{
		return false; 
	}
	
	int const START_DIVISOR = 2;
	return (( CheckPrime(number, START_DIVISOR)));
 
}


//function CheckPrime is a helper to the isPrime function 
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//
bool CheckPrime (int number,int divisor) {
  //const int START_DIVISOR = 1; //HINT: You may want a helper function
 
   //YOUR CODE GOES HERE
   //cout << number << helper_Increment(START_DIVISOR) << endl;
	if( number %  divisor==0 && number > divisor )
	{
	 return false;
	}
	else
	{  
	 	if (divisor == number)
		{
			return true; 
		}
		else
		{
		
		 CheckPrime(number,divisor+1);
	    }
	
	}
 
}
 
//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n. 

void printPrimes (int n) {

   //YOUR CODE GOES HERE
    if(!(n <=1))
    { 
    	printPrimes(n-1);
    	
    	 if(isPrime(n))
   		{
   		   cout << n << " ";
    
   	 	}
 
    }
  
}  

//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0 
//Fib(1) -> 1 
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n) {
    
   //YOUR CODE GOES HERE
   if (n==0)
   {
   	return 0;
   }
   else if(n==1)
   {
   	return 1;
   }
   else 
   {
   return (findFibo(n-1) + findFibo(n-2));
   }
    
}


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number) {
    const int START_DIVISOR = 2; //HINT: You may want a helper function
     cout << number << "=";
   //YOUR CODE GOES HERE
   if(number < 1)
   {
   	cout << "Invalid number" << endl; 
   }
  else if (isPrime(number))
{
	cout << "prime " << endl ;
}
else
 	{
		FactorHelper(number, START_DIVISOR);
	}	

}
    
    //helper function for factoring
    // input parameter receives two integers 
    // output: prints out prime factors of the given number to the standard output(cout)
void FactorHelper(int number, int START_DIVISOR)
{
	if( number % START_DIVISOR == 0 && START_DIVISOR <= number )
	{
		number = number/START_DIVISOR;
		if (number != 1)
	{

		cout << START_DIVISOR << "*";
	}
	else
	{
		cout << START_DIVISOR << endl;
	}
		FactorHelper(number, START_DIVISOR);
	}
	else
	{
		if ( START_DIVISOR <= number )
		FactorHelper( number, START_DIVISOR+1);
		
	}
 
	
}
