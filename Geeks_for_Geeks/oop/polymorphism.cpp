/*
Polymorphism: more than one forms - ability of a message to be displayed in more than one form.
eg: man at the same time: husband, father, employee, etc...
two types -- compile time poly (function overloading || operator overloading)/ run time poly (function overriding)
*/

/*
// Function Overloading concept - Compile time polymorphism 
# include <iostream>
using namespace std;
class Geeks
{
public:
	void func(int x)
	{
		cout << "Value of x: " << x << endl;
	}
	void func(int x, int y)
	{
		cout << "Value of x and y: " << x << " " << y << endl;
	}
	void func(double x)
	{
		cout << "Value of x: " << x << endl;
	}
};

int main()
{
	Geeks obj1;
	obj1.func(5);
	obj1.func(3.5);
	obj1.func(5,6);
	return 0;
}
*/

/*
// Operator overloading concept - Compile time polymorphism
#include <iostream>
using namespace std;
class Complex
{
private:
	int real, imag;
public:
	Complex(int r=0, int i =0)
	{
		real = r;
		imag = i;
	}
	Complex operator + (Complex const &obj)
	{
		Complex res;
		res.real = real + obj.real;
		res.imag = imag + obj.imag;
		return res;
	}
	void print()
	{
		cout << real << "+ i" << imag << endl; 
	}
};

int main()
{
	Complex obj1(10,5);
	Complex obj2(2,4);
	Complex obj3 = obj2 + obj1;
	obj3.print();
	return 0;
}
*/
/*
// Runtime (actually not, since virtual functions are not used) polymorphism - Function overriding (the case when parent and base classes have the same functions)
#include <iostream>
using namespace std;
class Parent
{
public:
	void print()
	{
		cout << "Parent class" << endl; 
	}
};

class Base : public Parent
{
public:
	void print()
	{
		cout << "Base class " << endl;  
	}
};

int main()
{
	Parent p1;
	Base b1;
	b1.print();
	p1.print();
}
*/

/*
// Does overloading work with inheritance?
If we have a function in base class and a function with same name in derived class, can the base class function be called from derived class object?

#include <iostream>
using namespace std;
class Base
{
public:
    int f(int i)
    {
        cout << "f(int): ";
        return i+3;
    }
};
class Derived : public Base
{
public:
    double f(double d)
    {
        cout << "f(double): ";
        return d+3.3;
    }
};
int main()
{
    Derived* dp = new Derived;
    cout << dp->f(3) << '\n'; //6.3
    cout << dp->f(3.3) << '\n'; //6.6
    delete dp;
    return 0;
}


Overloading doesn’t work for derived class in C++ programming language. There is no overload resolution between Base and Derived. 
The compiler looks into the scope of Derived, finds the single function “double f(double)” and calls it. 
It never disturbs with the (enclosing) scope of Base. In C++, there is no overloading across scopes – derived class scopes are not an exception to this general rule.
*/

/* Does overloading work for the main function? 
- If both mains are in the most external part of the program, the compiler will not know which main to choose as the driver. So, error. 
// this gives error: 

#include <iostream>
using namespace std;
int main(int a)
{
    cout << a << "\n";
    return 0;
}
int main(char *a)
{
    cout << a << endl;
    return 0;
}
int main(int a, int b)
{
    cout << a << " " << b;
    return 0;
}
int main()
{
    main(3);
    main("C++");
    main(9, 6);
    return 0;
}

- But, if there is a main in the external scope and there are mains inside a class, then main can be overloaded. 
// like this:  
#include <iostream>
using namespace std;
class Test
{
public:
    int main(int s)
    {
        cout << s << "\n";
        return 0;
    }
    int main(char *s)
    {
        cout << s << endl;
        return 0;
    }
    int main(int s ,int m)
    {
        cout << s << " " << m;
        return 0;
    }
};
int main()
{
    Test obj;
    obj.main(3);
    obj.main("I love C++");
    obj.main(9, 6);
    return 0;
}

- Note that main is not reserved word in programming languages like C, C++, Java and C#. For example, we can declare a variable whose name is main:

#include <iostream>
int main()
{
    int main = 10;
    std::cout << main;
    return 0;
}


*/

/* Function overloading and float in C++

#include <iostream> // this gives an error because 3.5 & 5.6 are considered double and not float. Hence, compiler gets confused; should it convert the numbers to int/ float? 
using namespace std; // can be resolved by using test(3.5f, 5.6f)

void test(float s,float t)
{
    cout << "Function with float called ";
}
void test(int s, int t)
{
    cout << "Function with int called ";
}
int main()
{
    test(3.5, 5.6);
    return 0;
}

*/
