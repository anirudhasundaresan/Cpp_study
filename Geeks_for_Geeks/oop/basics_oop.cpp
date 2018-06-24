// https://www.geeksforgeeks.org/basic-concepts-of-object-oriented-programming-using-c/

// Class is a blueprint of the data and the functions in it. Classes take up some memory even though a defined class can have no variables/ functions. This is because the standard does not allow
// objects (and thus, classes) to have 0 mem, else they would point to the same address.

// Objects are run-time entities in an OO system and they are instances of the class
// Classes are user defined data types, like structures and unions in C
// Classes can have public, private or protected also. By default, class variables are private but in structure, the variables are public by default. // main diff btw classes and structures

// Classes help in encapsulation and data hiding. Encapsulation - all data and functions in a single entity called class. Data hiding - none of these variables/ functions can be used outside the class
// in the main program. 

// Data abstraction: classes hide implementation details and thus provides only the needed info to outside program.
// Inheritance: This is not: Objects of one class can be called by another class. This is when the objects of one class can acquire the properties of objects of another class. Re-usability. Improvement 
// of classes. Can add more features without modifying the existing class.

// Polymorphism: function overloading and operator overloading. Polymorphism is heavily used in inheritance. 

// Dynamic binding: Code to be executed in response to a function call is decided at run-time : used in 'virtual functions'

// Message Passing: Objects can communicate with one another. An object can send/ receive messages from another one. A message for an object is a request for execution of 
// a procedure and therefore will invoke a function in the receiving object that generates the desired results. Message passing involves specifying the name of the object, the name of the function and 
// the information to be sent.

/*
Wrapping up of data and functions in a single unit: encapsulation 

Usual way of writing class - encapsulation 

Access specifiers play an important role in implementing encapsulation.
data members - should be private using the private access specifier
member function that manipulates these private datamembers - public using the public access specifier.

How are structures different from classes? 
In structs: all members are public by default
In classes: all members are private by default
*/

/*
class person
{
	char name[20];
	int id;

public:
	void getdetails(){}
};

int main()
{
	person p1; //p1 is an object 
}
*/
// Size of an empty class is not zero. It is 1 byte generally. It is nonzero to ensure that the two different objects will have different addresses. 
/*
#include <iostream>
using namespace std;

class Empty {};

int main()
{
	Empty a,b;
	if (&a == &b)
	{
		cout << "Impossible";
	}
	else
	{
		cout << "Fine";
	}
	return 0;
}
*/

// For the same reason (different objects should have different addresses), “new” always returns pointers to distinct objects.
/*
#include <iostream>
using namespace std;

class Empty {};

int main()
{
	Empty* p1 = new Empty; // p1 is a pointer to a newly created object
	Empty* p2 = new Empty; // Empty in the beginning is the datatype.
	if (p1 == p2) // p1 and p2 are addresses 
	{
		cout << "Impossible";
	}
	else
	{
		cout << "Fine";
	}
	return 0;
}
*/

// The case when a class derives from an empty base class.
// There is an interesting rule that says that an empty base class need not be represented by a separate byte. So compilers are free to make optimization in case of empty base classes.
#include <iostream>
using namespace std;
class Empty {};
class derived : Empty
{
	int a; // private by default since it is a class
};

int main()
{
	derived d1;
	Empty e1;
	cout << sizeof(e1); // 1
	cout << sizeof(d1); // 4 not 4+1 since compiler optimization of empty class being derived.
}