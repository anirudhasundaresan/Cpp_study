/*
https://www.geeksforgeeks.org/c-classes-and-objects/

class ClassName
{

	Access specifier: // can be public, private, protected
	Data members; // variables to be used
	Member functions(){} // methods to access data members

}; // note the semicolon


// Public data members are allowed to be accessed by the object, but not the private data members. Accessing a data member depends solely on the access control of the data member.

ClassName ObjectName;

*/

// Classes are blueprints of the object - user defined data type
/*
#include <bits/stdc++.h>
using namespace std;
class Geeks
{
public:
	string geekname;
	void printid(); 
	void printname() // member function declared inside the class
	{
		cout << "Geekname is: " << geekname;
	}
};

void Geeks::printid() // member function declared outside the class 
{
	cout << "Geekname is : ";
}

int main(){
	Geeks obj1;
	// Objects is an instance of the class and mem is allocated when obj is created.
	obj1.geekname = "Anirudha";
	obj1.printid();
	cout << endl;
	obj1.printname();
	return 0;
}
*/
// Can define a member function either inside classes or outside
// Any function declared inside the class is by default inline, but the functions outside can also be made inline by using the keyword 'inline'. 

// Inline functions are actual functions, which are copied everywhere during compilation, like pre-processor macro, so the overhead of function calling is reduced.

// Declaring a 'friend' function can let non-member functions access private stuff.

/*
#include <bits/stdc++.h> // needed for cout
// Constructors
using namespace std;
class Geeks
{
public:
	int id;
	Geeks() // default constructor
	{
		cout << "The constructor is called" << endl;
		id = -1; 
	}
	Geeks(int x)
	{
		cout << "The parameterized constructor is called: " << endl;
		id = 1;
	}
};

int main()
{
	Geeks obj1;
	Geeks obj2(5); // don't give Geeks obj1(5) again...
	cout << "Object 1 id: " << obj1.id << endl; // id is a public data member, hence accessible.
	cout << "Object 2 id: " << obj2.id << endl;
	return 0;	
}

*/

// Copy constructors: This creates a new object which is an exact copy of an existing object. Compiler provides a default copy constructor to all the classes.

// Destructors: Called by compiler when the scope of the object ends.

#include <iostream> // #include <bits/stdc++.h>
using namespace std;
class Geeks // note: no paranthesis here 
{
public:
	int id;
	~Geeks()
	{
		cout << "Destructor is called for id: " << id << endl;
	}
};

int main()
{	
	Geeks obj1;
	obj1.id = 2;
	Geeks obj2;
	obj2.id = 3;
	int i = 0;
	while (i<5)
	{
		Geeks obj3;
		obj3.id=i;
		i++;
	} // scope of obj3 ends here and so obj3 is created 5 times
	// print order would be: obj3, obj2, obj1...why? it's like on a stack, the lifo scope.
	return 0;
}