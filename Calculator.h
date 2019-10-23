/*****************
 *Name: Riley Conant
 * Date Completed: 10/12/19
 * Function: Use an object and header to create a calculator that can do multiple functions before being cleared and will print 
 * the operations out. 
 * Input: Pre-determined input that is given to us in the main class
 * Output: The different operations with the given inputs from the main. The output will also vary depending on the order of the calls and what inputs are given.
 * Additional Comments:This is the header file that initializes all of functions and member variables so that they can be defined in the object class.
 * **************/

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Calculator  {
	public:
	//Constructors
	Calculator(); //Default Constructor 
	Calculator(double);
	//Functions
	double add(double);
	double subtract(double);
	double multiply(double);
	double divide(double);
	double power(int);
	double power(double,double);
	void clear();
	void print();
	private:
	//Member variables
	double result;
	bool cleared;
	string expression; 
};
