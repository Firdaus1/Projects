#include <iostream>
#include <fstream>
#include "queue_3358.h"
#include "bst_3358.h"
#include <stdlib.h> 
#include <cstdlib>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
 
string temp;
int tempInt;
int rand4;

	Queue_3358<int> q;     //  it will assign the deafult size , 1000
 
 	BST_3358<int> tree;
	BST_3358<int> tree2;
 
	
	int index = 10;
	while (index != 0)
	{
		rand4 = rand() % 100;
		q.enQueue(rand4);
  		tree.insertItem(rand4);
  		index--;
	}
  
      Queue_3358<int> q2;
    
      
   cout << "Testing in order traversal of the binary tree: " << endl; 
   tree.inOrderTraversal();
   cout << endl << endl; 
   
	cout << "Testing pre ordered traversal of the binary tree: " << endl; 
   tree.preOrderTraversal();
   cout << endl << endl; 
   
   cout << "Testing post ordered traversal of the binary tree: " << endl; 
   tree.postOrderTraversal();
   cout << endl << endl; 
   
   int random = rand() % 100;
   cout << "Inserting " << random << " to the binary tree" << endl;
   tree.insertItem(random);
   
	cout << "In order traversal of the binary tree after insert" << endl;
   tree.inOrderTraversal();
   cout << endl << endl; 
   
   cout << "Testing delete an item from the binary tree " << endl;
   cout << "Deleting " << random << " from the binary tree" << endl; 
   tree.deleteItem(random);
   
   cout << "In order traversal of the binary tree after removing " << random <<endl;
	tree.inOrderTraversal();
	cout << endl << endl; 

   random = rand() % 100;
   cout << "Inserting " << random << " to the binary tree" << endl;
   tree.insertItem(random);
   
   cout << "In Order traversal of the binary tree after insert" << endl; 
   tree.inOrderTraversal();
   cout << endl << endl; 
   cout << "Testing Breadth First Search, looking for " << random;
   cout << endl; 
   
 
	if (tree.breadthFirstSearch(random))
	{
		cout << "Found the Item in the tree!" << endl;
	}
	else
	{
		cout << "Didn't found the item!" << endl;
		
	}
	cout << endl;
	
	cout << "Testing the copy constructor for binary search tree:(In order traversal)" << endl;
	tree2=tree;
	tree2.inOrderTraversal();
	cout << endl << endl; 
	
	q2 = q;
	cout << "Testing copy constructor for Queue " << endl; 
	
	   		if(!q2.isEmpty())
				{
					while(!q2.isEmpty())
					{
		 
						cout << q2.deQueue()<< " ";
						cout << endl; 
				
					}		
				}
				else
				{
					cout << "Queue is empty \n\n";
				}
				
				
	cout << endl;
   int random2;
	random = rand() % 100;
	random2 = rand() % 100;
	cout << "Testing insert for Queue , inserting two random numbers: " << random <<" "<< random2 << endl;
	q.enQueue(random);
   q.enQueue(random2);
   
   cout << "testing dequeue by printing out all the items from the queue"<< endl;
   while(!q.isEmpty())
   {
   	
   	cout << q.deQueue() << endl;  
		  	
	}
      
   return 0;
}
