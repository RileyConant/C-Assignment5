/***************************************************************************
 * Name: Riley Conant
 * Date Completed: 10/12/19
 * Function: Use an object and header to create a calculator that can do multiple functions before being cleared and will print 
 * the operations out. 
 * Input: Pre-determined input that is given to us in the main class
 * Output: The different operations with the given inputs from the main. The output will also vary depending on the order of the calls and what inputs are given.
 * Additional Comments:  The expression string variable builds upon itself to create the idea of a calculator storing the whole function 
 * Also this is the obejct class that holds the definitions of the functions that the main will use to make the class work                                                                                                   
 ***************************************************************************/


#include "Calculator.h"
//Default constructor that initializes the variables to initial values
Calculator::Calculator()
{
	result = 0;
	expression = "0.0";
	cleared = true;
}
//Constructor that is used to initialize the values and set result to a specified value
Calculator::Calculator(double num)
{
	result = num;
	expression = std::to_string(num);
	cleared = true;
}
//Add Function
double Calculator::add(double num)
{
	cleared = false;
	//The addition 
	result = result + num;
	//Set the expression equal to the new operation with the rest of the function
	expression =  "(" +expression + ")" + " + " + std::to_string(num);
	return result;
}
//Subtraction function
double Calculator::subtract(double num)
{
	cleared = false;
	//Subtraction 
	result = result - num;
	//Set the expression to the new expression
	expression =  "(" +expression + ")" + " - " + std::to_string(num);
	return result;
}
//Multiplication funciton
double Calculator::multiply(double num)
{
	cleared = false;
	//Multiplication 
	result = result*num;
	//Add the multiplication to the expression
	expression = "(" + expression + ")" + " * " + std::to_string(num);
	return result;
}
//Division function
double Calculator::divide(double num)
{
	cleared = false;
	//Check to make sure the paramter was not zero
	if(num == 0)
	{
		//Print error 
		cout << "Error cannot divide by zero"<< endl;
		return result;
	}
	else
	{
		//Divide the result
	result = result/num;
	//Add division to the expression
	expression = "(" + expression + ")" + " / " + std::to_string(num);
	return result;
	}
}
//power function 
double Calculator::power(int exp)
{
	cleared = false;
	//Set exponent ot another integer so that value can be held for later
	int exp2 = exp;
	//Check to see if the exponent is 0 
	if(exp == 0)
	{
		//Add the power to the expression 
		expression = "pow( " + expression + ")," + std::to_string(exp) + " )"; 
		//set result to 1 
		result = 1.0;
		return result;
	}
	else
	{
		//While loop to get the result of the exponent
		while(exp > 1)
		{
		//Times result by itself to get intended result
			result = result * result;
			exp = exp-1;
		}
		//Add the exponent to the expression 
		expression = "pow( " + expression + ")," + std::to_string(exp2)+ " )";
		return result;
	}
}
//Second power function
double Calculator::power(double num, double exp)
{	
	//Save the exponent value
	double exp2 = exp;
	//Check to see if the exponent is 0 
	if(exp == 0.0)
	{
		//Add the power to the expression 
		expression = "pow( " + expression + ")," + std::to_string(exp)+ " )";
		//Set the result to 1 
		result = 1.0;
		return result;
	}
	
	else if(cleared == true)
	{
		//set the result ot the paramter num
		result = num;
		expression = std::to_string(result);
		//While loop to get the result of the exponent
		while (exp >1)
		{
			//Do the exponential calculation
			result = result * result;
			exp = exp-1;
		}
		//Update the expression
		expression = "pow( " + expression + ")," + std::to_string(exp2)+ " )";
		return result;
	}
	else 
	{
		//If the calculator is not cleared have an error be displayed
		cout << "Error: The calculator was not cleared" << endl;
		expression = "(" + expression;
		return result;
	}
}
//Clear function 
void Calculator::clear()
{
	//set the results to the inital values, clearing the values and sets cleared to true
		result =0;
		expression = "0.0";
		cleared = true;
}
//Print function
void Calculator::print()
{
	//Print the expression
	cout << "Expression evaluated: " << endl;
	cout << expression <<  " =" << endl;
	//Print the result
	cout << "Result: " << result << endl;
}

