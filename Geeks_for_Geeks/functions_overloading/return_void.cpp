/*
We do not need to return from void functions. 
But, for readability, it is better to have a return statement. 
*/

#include <iostream>
using namespace std;

void work()
{
	cout << "hello from work" << endl; 
}
void func()
{
	cout << "hello" << endl; 
	// return; // or no statement here 
	// return work();
	return (void)5; // returns 5 type-casted (?) to void type...
}

int main()
{
	func();
	return 0; 
}