/*
Arithmetic operators: (+, -, *, /, %,++,–).
- Two types: Unary (++ , –) and Binary (+ , – , * , /). 
Relational operators: (==, > , = , <= ).
Logical operators: returns boolean value either true or false. -- &&, ||, !; False = 0 and True != 0
Bitwise operators: The operands are first converted to bit-level and then calc is performed on the operands. All arithmetic opers can be done in the bit-level for faster processing. 
Assignment operators: (=, +=, -=, *=, /=).
Other operators:
- sizeof() -- compile time unary operator used to find the size of the operand;  Result is unsigned integral type - usually denoted by size_t. 
- comma operator -- lowest precedence; binary operator that evaluates its first operand and discards the result, it then evaluates the second operand and returns this value (and type).
- conditional operator --  Expression1 ? Expression2 : Expression3; evaluate Expression 2 and return it if exp1 is true, else eval exp3 and return it. 
- scope resolution operator 
- Pre-increment and post-increment as l-values
Casting operators: const_cast, static_cast, dynamic_cast, reinterpret_cast

Note the operator precedence chart here: 
https://www.geeksforgeeks.org/operators-c-c/
*/


/*
Understanding unary increment and decrements: 

#include <stdio.h>
int main()
{
    int a = 10, b = 4, res;
 
    // post-increment example:
    // res is assigned 10 only, a is not updated yet
    res = a++;
    printf("a is %d and res is %d\n", a, res); //a becomes 11 now
 
 
    // post-decrement example:
    // res is assigned 11 only, a is not updated yet
    res = a--;
    printf("a is %d and res is %d\n", a, res);  //a becomes 10 now
 
 
    // pre-increment example:
    // res is assigned 11 now since a is updated here itself
    res = ++a;
    // a and res have same values = 11
    printf("a is %d and res is %d\n", a, res);
 
 
    // pre-decrement example:
    // res is assigned 10 only since a is updated here itself
    res = --a;
    // a and res have same values = 10
    printf("a is %d and res is %d\n",a,res); 
 
    return 0;
}

Output: 
a is 11 and res is 10
a is 10 and res is 11
a is 11 and res is 11
a is 10 and res is 10
*/

/* Short-circuiting in Logical Operators:
Short circuit evaluation isn't about true or false. 
It's about not evaluating part of an expression if you can predict the result without it. Since false && whatever() returns false regardless of whatever() you don't need to call whatever().
An efficient way to avoid unneeded work, and as a way to control flow.

if (foo != null && foo->isValid()) {
    foo->doStuff();
}

foo->isValid() would dereference a null and cause undefined behavior if foo is null. Here, short circuit evaluation prevents that by simply not calling foo->isValid(). 
*/

/* Some facts about sizeof(): 
- When operand is a data type, it returns the size (according to the compiler and bit version of your system)
- When operand is an expression, it returns the size of the expression after evaluation
-- Used to find the length of an array: sizeof(arr)/sizeof(arr[0])
-- To allocate block of memory dynamically: int *ptr = malloc(10*sizeof(int));
*/

/* Bitwise operators facts: 
- The left shift and right shift operators should not be used for negative numbers If any of the operands is a negative number, it results in undefined behaviour.
- The bitwise operators should not be used in place of logical operators.
- The left-shift and right-shift operators are equivalent to multiplication and division by 2 respectively.
- The & operator can be used to quickly check if a number is odd or even. (x & 1)? printf("Odd"): printf("Even");
- The ~ operator should be used carefully. The result of ~ operator on a small number can be a big number if the result is stored in an unsigned variable.
And result may be negative number if result is stored in signed variable (assuming that the negative numbers are stored in 2’s complement form where leftmost bit is the sign bit).
- Main:The bitwise XOR operator is the most useful operator from technical interview perspective.
*/

/*
Comma - can be used as an operator or as a separator. 

/* comma as an operator */
// int i = (5, 10);  // /* 10 is assigned to i*/
// int j = (f1(), f2()); //   /* f1() is called (evaluated) first followed by f2(). 
                      // The returned value of f2() is assigned to j */

/* comma as a separator */
// int a = 1, b = 2;
// void fun(x, y);

/*
Scope resolution operator vs this pointer.

// In a member function of a class, if the argument is the same name as that of a data member of a class, then shadowing of the class variable by the function variable..

// C++ program to show that local parameters hide
// class members
#include<iostream>
using namespace std;
class Test
{
    int a;
public:
    Test() { a = 1; }
 
    // Local parameter 'a' hides class member 'a'
    void func(int a)  { cout << a; }
};
 
int main()
{
    Test obj;
    int k = 3 ;
    obj.func(k);
    return 0;
}

// This is where this pointer comes in handy. A statement like “cout << this->a” instead of “cout << a" can simply output the value 1 as this pointer points to the object from whom func is called.

// We could also use Scope Resolution operator, but: it can be used only when the variable is of static type.

// Scope resolution operator is for accessing static or class members and this pointer is for accessing object members when there is a local variable with same name.

// pre-increment (or pre-decrement) can be used as l-value, but post-increment (or post-decrement) can not be used as l-value.
#include <stdio.h>
 
int main()
{
  int a = 10;
  ++a = 20; // works but a++ = 20; // error 
  printf("a = %d", a); // prints a = 20
  getchar();
  return 0;
}

/* Casting operators: 
