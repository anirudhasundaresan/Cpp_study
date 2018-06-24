// https://www.geeksforgeeks.org/inline-functions-cpp/
/*
Most of the information in the link is useful. I will point out the most important points here: 
- When the inline function is called whole code of the inline function gets inserted or substituted at the point of inline function call. This substitution is performed by the C++ compiler at compile time.
- Remember, inlining is only a request to the compiler, not a command.
- Refer link for advantages and disadvantages.
- All member functions of a class are inline by default. But, in case you want to declare them as inline, it is better to define the function outside the class using :: (like shown below.)
//// http://www.cplusplus.com/doc/tutorial/preprocessor/ very useful
class S
{
public:
    int square(int s); // declare the function
};
 
inline int S::square(int s) // use inline prefix
{
 
}


- C++ compiler checks the argument types of inline functions and necessary conversions are performed correctly. Preprocessor macro is not capable of doing this. 
- One other thing is that the macros are managed by preprocessor and inline functions are managed by C++ compiler.
- Remember: It is true that all the functions defined inside the class are implicitly inline and C++ compiler will perform inline call of these functions, but C++ compiler cannot perform inlining if the function is virtual. 
- The reason is call to a virtual function is resolved at runtime instead of compile time. 
- Virtual means wait until runtime and inline means during compilation, if the compiler doesn’t know which function will be called, how can it perform inlining?
- One other thing to remember is that it is only useful to make the function inline if the time spent during a function call is more compared to the function body execution time. 
- An example where inline function has no effect at all:
inline void show()
{
    cout << "value of S = " << S << endl;
}


The above function relatively takes a long time to execute. 
In general function which performs input output (I/O) operation shouldn’t be defined as inline because it spends a considerable amount of time. 
Technically inlining of show() function is of limited value because the amount of time the I/O statement will take far exceeds the overhead of a function call.

Don’t make every function inline. It is better to keep inline functions as small as possible.
*/


// The following program demonstrates this concept of inline for class member functions:

#include <iostream>
using namespace std;
class operation
{
    int a,b,add,sub,mul;
    float div;
public:
    void get();
    void sum();
    void difference();
    void product();
    void division();
};
inline void operation :: get()
{
    cout << "Enter first value:";
    cin >> a;
    cout << "Enter second value:";
    cin >> b;
}
 
inline void operation :: sum()
{
    add = a+b;
    cout << "Addition of two numbers: " << a+b << "\n";
}
 
inline void operation :: difference()
{
    sub = a-b;
    cout << "Difference of two numbers: " << a-b << "\n";
}
 
inline void operation :: product()
{
    mul = a*b;
    cout << "Product of two numbers: " << a*b << "\n";
}
 
inline void operation ::division()
{
    div=a/b;
    cout<<"Division of two numbers: "<<a/b<<"\n" ;
}
 
int main()
{
    cout << "Program using inline function\n";
    operation s;
    s.get();
    s.sum();
    s.difference();
    s.product();
    s.division();
    return 0;
}
