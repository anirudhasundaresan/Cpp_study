/*
Direct member access operator: '.' (the dot operator)

Public: Public data members are accessible by all, inside and outside the class. Data members and member functions of public can be accessed by other classes too.
Private: Private data members are accessible only by member functions inside the class. No function or object (except friend) can access the private data members outside the class.
Protected: Protected data members are similar to private data members in that they are inaccessible from outside the class but are accessible by derived classes.

/*
// C++ program to show public
#include <iostream> // no.h
using namespace std;
class Circle
{
public:
	double radius;
	double area_calc()
	{
		return 3.14*radius*radius;
	}
};

int main()
{
	Circle c1;
	c1.radius = 5; // radius is public and hence can be accessed outside the function.
	cout << c1.area_calc() << endl;
	return 0;
}


// To do the same above with a private radius...
#include <iostream>
using namespace std;
class Circle
{
private:
	double radius;
public:
	double area_calc(double r)
	{
		radius = r;
		cout << "The radius is: " << radius;
		cout << "The area is: " << 3.14*radius*radius;
	}
};

int main()
{	
	Circle c1;
	// c1.radius = 5.5; // will throw a compile time error.
	c1.area_calc(5.5);
	return 0;
}
*/

// Protected access modifiers:
#include <iostream>
using namespace std;
class Parent
{
protected:
	int id_protected;
	void protected_func()
	{
		cout << "Protected function" << endl;
	}
};
class Child : public Parent // single colon : not :: --> scope resolution operator
{
public:
	void setId(int id)
	{
		id_protected = id;
		protected_func(); // it is successfully called
	}
	void display()
	{
		cout << "ID protected: " << id_protected << endl;
	}
};

int main()
{	
	Parent obj2; 
	// obj2.id_protected = 5; // does not work 
	Child obj1;
	obj1.setId(5);
	obj1.display();
}