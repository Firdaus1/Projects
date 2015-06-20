/*
 * SortedInt.h
 *
 *  Created on: Jan 28, 2015
 *      Author: Firdaus
 */
/*
 * CONSTANT
 * 	  static const in MAX_SIZE = ____
 * 	  MAX_SIZE is the highest # of entries that can
 * 	  be accommodated
 * CONSTRUCTOR
 *    Stats()
 *       Pre:(None)
 *       Post: clearData() is called and numVars is set
 *       equal to zero
 * bool addVar(double var)
 * 		 The function adds one variable to the array
 * 		 Pre: numVars < MAX_SIZE
 * 		 Post: numVars = numVars + 1  and
 * 		 var has been added to class
 * void showData()
 * 		 The function prints data to the console output
 * 		 Pre: (None)
 * 		 Post: data is printed to the console output
 * double getAverage()
 * 		 The function gets an average of data
 * 		 Pre: (None)
 * 		 Post: returns calculated average of data
 * double finHighest()
 * 		 The function simply find the highest value
 * 		 of the data
 * 		 Pre: (None)
 * 		 Post: returns lowest value from vars array
 * double findLowest()
 * 		 The function simply finds the lowest value from data
 * 		 Pre: (None)
 * 		 Post: lowest value is returned from var array
 * double calcStdDeviation()
 * 	     The function will tell you how closely your samples are located to the mean.
 * 	     Usually, approximately 68% of all the samples will fall inside one standard deviation from the mean.
 *       Pre: Needs to receive the average
 *       Post: returns the standard deviation

 *
 */


#ifndef SORTEDINT_H_
#define SORTEDINT_H_
/*
 * TemporaryHeader.h
 *
 *  Created on: Jan 28, 2015
 *      Author: Firdaus
 */
using namespace std;


class Stats {

   static const int MAX_SIZE = 10000;
   private:
      int numVars;
      double vars[MAX_SIZE];

   public:
      Stats();

      void clearData() {
         numVars = 0;
      }


      //This function adds one variable to the array in the class.
      //The function returns false if the variable is not successfully added to the class.
      //pre: numVars < MAX_SIZE
      //post: numVars = numvars + 1 and var has been added to the class
      bool addVar(double var);
      void showData();
      double getAverage();
      double findHighest();
      double findLowest();
      double calcStdDeviation(double avg);
      int getNumVars() {
         return numVars;
      }

      static int getMaxSize() {
         return MAX_SIZE;
      }

};

#endif /* SORTEDINT_H_ */
