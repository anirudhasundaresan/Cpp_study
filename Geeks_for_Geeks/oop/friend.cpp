/*
Friend function/ class in C++:
- Should not be used a lot, since if used a lot, it will lessen the value of encapsulation 
- Friendship is not mutual. If class A is a friend of B, then class B need not be a friend of A.
- Friendhsip is not inherited.
- Not in JAVA
*/
/*
// Friend class: A friend class can access private and protected members of other classes in which it is declared as friend.
class Node
{
private:
	int key;
	Node *next;

	friend class LinkedList; // This LL class can now access private members of Node.
};

// Friend function: Like friend class, a friend function can be given access to the private members of a class. This function can be a global function / member function of another class.

class Node 
{
	int key;
	Node *next;

	friend int LinkedList::search();
};
*/

/*
// To show inheritance with friendship // 
#include <iostream>
#include <typeinfo>

using namespace std;

class Base
{ 
private:
    int data;
protected:    
    int val;
    
public:
    Base():val(3), data(33)
    {
        cout << "\nBase ctor called\n";
    }
    friend void BaseFriendFunc();
    
};

class Derived: public Base 
{
private:
    double data1;
protected:
    char dval;
public:
    int yeppi;
    Derived():dval('a'), data1(33.333), yeppi(0)
    {
        cout << "\nDerived ctor called\n";
    }
    friend void DerivedFriendfunc();
};

// friend of Base
void BaseFriendFunc()
{
    Derived dummy; // or access via Base dummy (object);
    cout << "BaseFriendFunc Base private " << dummy.data;
    cout << "\nBaseFriendFunc Base protected " << dummy.val;
    cout << "\nBaseFriendFunc Derived public " << dummy.yeppi;
    // can't access cout << "\nDerived protected " << dummy.dval;
    // can't access Derived private -> dummy.data1;
}

// friend of Derived
void DerivedFriendfunc()
{
    Derived dummy;
    cout << "\nDerivedFriendfunc Derived private " << dummy.data1;
    cout << "\nDerivedFriendfunc Derived protected " << dummy.dval;
    cout << "\nDerivedFriendfunc Base protected " << dummy.val; // since inherited in Derived and becomes protected
    // can't access Base's private dummy.data; as private data never gets inherited in Derived
}

int main()
{
    BaseFriendFunc();
    DerivedFriendfunc();
    
    return 0;
}
*/


/*
// To demonstrate friend class
#include <iostream>
using namespace std;
class A
{
private:
	int a;
public:
	A()
	{
		a = 5;
	}
	friend class B;
};

class B
{
private:
	int b;
public:
	void show (A& x)
	{
		cout << "Private member of A: " << x.a << endl; 
	}
};

int main()
{
	A a;
	B b;
	b.show(a);
	return 0;
}
*/


/*
// To demonstrate friend function of another class
#include <iostream>
using namespace std; 
class B; // need to declare

class A
{
public:
    void showB(B&); // need to declare
};
 

class B
{
private:
    int b;
public:
    B()  {  b = 0; }
    friend void A::showB(B& x); // Friend function can access private members of B.
};
 
void A::showB(B& x)
{
    // Since show() is friend of B, it can
    // access private members of B
    std::cout << "B::b = " << x.b;
}
 
int main()
{
    A a;
    B x;
    a.showB(x);
    return 0;
}
*/

// To demonstrate friend global function 
#include <iostream>
using namespace std;
class A
{
    int a;
public:
    A() {a = 0;}
    friend void showA(A&); // global friend function
};
 
void showA(A& x) {
    // Since showA() is a friend, it can access
    // private members of A
    std::cout << "A::a=" << x.a;
}
 
int main()
{
    A a;
    showA(a);
    return 0;
}
