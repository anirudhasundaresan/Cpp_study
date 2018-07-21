/*
Inheritance: one class (derived/ sub-class) can inherit from base/super-class.

Modes of inheritance: public, private, protected
Types of inheritance: single, multiple, multilevel, hierarchical inheritance, hybrid/ virtual inheritance

Public: public member of base class becomes public in the derived class and protected becomes protected in the derived class.
Protected: public and protected members of the base class becomes protected in the derived class. 
Private: public and protected members of the base class become protected in the derived class.

By default: the derived class inherits publicly ; in structs, the derived struct inherits privately. 
NOTE: A struct can also inherit from a base class. So, by default, this would be public.
The private members of the base class cannot be directly accessed in the derived class. But these derived classes contain the private members in the base class but, just not accessible.
*/
/*
class A
{
public:
	int x;
private:
	int y;
protected:
	int z;
};

class B : public class A
{
	// x is public, z is protected and y is not accessible from B
};
class C: protected class A
{
	// x and z are protected, y is not accessible from C
};
class D: private class A
{
	// x and z are private, y is not accessible from D 
};

*/
// Types of inheritance: 

#include <iostream>
using namespace std;
class Vehicle
{
public:
	Vehicle()
	{
		cout << "This is a vehicle" << endl; 
	}
};

class Jeep : public Vehicle // direct inheritance
{
public:
	Jeep()
	{
		cout << "Jeep constructor" << endl; 
	}
};
class Scooter : public Vehicle, public Jeep  // sort of hierarchical inheritance issues a warning: direct base 'vehicle' inaccessible in 'scooter' due to ambiguity.
{
public:
	Scooter()
	{
		cout << "Scooter constructor" << endl;
	}
};

int main()
{	
	Scooter s1;
	cout << "Hello" << "Checking git" 
	return 0;
}
