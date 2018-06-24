/*

Function declaration: Tells compiler about number of params a function takes, return type and type of parameters. Parameter names are optional in function declaration, but for sure must be in function definition. 
int max(int, int);
int fun(char, int);
Function declaration a.k.a function prototype also tells you the order in which you get the arguments. (a.k.a signature of the function). 

What happens when there is no specification of the function prototype? 
Compiler might assume that the return type is int and might raise a warning.

Always declare a function before using it.

Parameters in the function call statement - actual parameters
Parameters in the function definition statement - formal parameters

Passing by value - value is passes and no changes made to the actual params
Passing by reference - address is passed and changes made to the params inside the function will reflect in the main program.

*/

// passing by reference: 

#include <iostream>
using namespace std;

void func(int *p) // * to show that it is a pointer variable
{
	*p = 30; // changing the value
	cout << "The address: " << p;
}


int main()
{
	int a = 5;
	func(&a);
	cout << a; 
	return 0;
}
