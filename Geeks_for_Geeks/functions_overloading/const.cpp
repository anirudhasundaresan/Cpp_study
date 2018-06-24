#include <iostream>
using namespace std;

// The idea of const functions is not allow them to modify the object on which they are called. 
// It is recommended practice to make as many functions const as possible so that accidental changes to objects are avoided.
// When a function is declared as const, it can be called on any type of object. Non-const functions can only be called by non-const objects.
// -- if getValue is not a const, it cannot be called by a const Test t; object.
/*
class Test {
    int value;
public:
    Test(int v = 0) {value = v;}
     
    // We get compiler error if we add a line like "value = 100;"
    // in this function.
    int getValue() const {return value;}  
};
 
int main() {
    Test t(20);
    cout<<t.getValue();
    return 0;
}

*/

/*
// Const keyword has different ways of using: here, with function; but it can be used with parameters also..
#include <iostream>
using namespace std;
 
class Test
{
protected:
    int x;
public:
    Test (int i):x(i) { }
    void fun() const
    {
        cout << "fun() const called " << endl;
    }
    void fun()
    {
        cout << "fun() called " << endl;
    }
};
 
int main()
{
    Test t1 (10);
    const Test t2 (20);
    t1.fun(); // goes to fun without const
    t2.fun(); // goes to const function
    // C++ allows member methods to be overloaded on the basis of const type. 
    // Overloading on the basis of const type can be useful when a function return reference or pointer. 
    // We can make one function const, that returns a const reference or const pointer, other non-const function, that returns non-const reference or pointer.
    return 0;
}
*/

// Const keywords with parameters (it works only when passing by reference)
// PROGRAM 1 (Fails in compilation) because fun() is redefined; Compiler Error: redefinition of 'void fun(int)' 
// the parameter ‘i’ is passed by value, so ‘i’ in fun() is a copy of ‘i’ in main(). Hence fun() cannot modify ‘i’ of main(). 
// Therefore, it doesn’t matter whether ‘i’ is received as a const parameter or normal parameter. 

/*
#include <iostream>
using namespace std;
 
void fun(const int i)
{
    cout << "fun(const int) called ";
}
void fun(int i)
{
    cout << "fun(int ) called " ;
}
int main()
{
    const int i = 10; // even without this 'const' it is the same error
    fun(i);
    return 0;
}
*/


//When we pass by reference or pointer, we can modify the value referred or pointed, so we can have two versions of a function, one which can modify the referred or pointed value, other which can not.
// PROGRAM 2 (Compiles and runs fine)
/*

#include <iostream>
using namespace std;
 
void fun(char *a)
{
  cout << "non-const fun() " << a;
}
 
void fun(const char *a)
{
  cout << "const fun() " << a; // this is printed
}
 
int main()
{
  const char *ptr = "GeeksforGeeks";
  fun(ptr);
  return 0;
}

*/

#include <iostream>
using namespace std;
 
void fun(const int &i)
{
    cout << "fun(const int &) called "; // this is printed
}
void fun(int &i)
{
    cout << "fun(int &) called " ;
}
int main()
{
    const int i = 10;
    fun(i);
    return 0;
}