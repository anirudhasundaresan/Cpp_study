/*
A class declared inside a function is a local class. 
Facts about local classes: 
- Using the class name as type to declare objects and pointers to objects are valid only in the function the class is defined in. Not in main().
- All methods of local classes must be defined inside the class only. 
- No static data members, but static member functions are allowed. 
- Outside the class, data can be accessed by the class only if it is a user-defined (enum) or if it is static. Else, error. 
- Local classes can access global variables, types and functions
- Local classes can access other local classes inside the same function.
*/

#include <iostream>
using namespace std;


int z = 0; // global variable can be accessed by any of the classes inside the function.
void fun()
{
	int x; // cannot be used by the class inside this function. 
	static int y;
	enum {i=1, j=2}; // these can be used within the class

	class Test
	{	
		// static int i; --> invalid as local class cannot have static data members. It can have static member functions, declared inside the class.  
		public:
			void method() // can be static
			{
				cout << y;
				cout << z; // since global variable, no error
				cout << i; // since they are enum and static
				// cout << x; throws error
				//something here
			}
	};

	class Test2
	{
		Test t1; // local classes can access other classes inside the same function
	public:
		void method1()
		{
			cout << z;
		}
	};

	Test t;
	Test *tp;
	t.method();
	// void Test::method(){} // throws an error
}

int main()
{	
	// Test t; // throws error 
	// Test tp*; // throws error
	fun();
	return 0; 
}