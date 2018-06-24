/*
There are cases when a function cannot be overloaded. 
1) Function declarations that differ only in the return type. 

include<iostream>
int foo() { 
  return 10; 
}
 
char foo() { 
  return 'a'; 
}
 
int main()
{
   char x = foo();
   getchar();
   return 0;
}


2) Member function declarations with the same parameter list and the same name, but one of them is static.

#include<iostream>
class Test {
   static void fun(int i) {}
   void fun(int i) {}   
};
 
int main()
{
   Test t;
   getchar();
   return 0;
}


3) Parameter declarations that differ only in ptr* vs. ptr[]. The array declaration is adjusted to become a pointer declaration. Only the second and subsequent array dimensions are significant in parameter types.

int fun(int *ptr);
int fun(int ptr[]); // redeclaration of fun(int *ptr)


4) Parameter declarations that differ only in that one is a function type and the other is a pointer to the same function type are equivalent. 

void h(int ());
void h(int (*)()); // redeclaration of h(int())


5) Parameter declarations that differ only in the presence or absence of const and/or volatile are equivalent. // this returns a redefinition error.
#include<iostream>
#include<stdio.h>
  
using namespace std;
  
int f ( int x) {
    return x+10;
}
 
int f ( const int x) {
    return x+10;
}
 
int main() {     
  getchar();
  return 0;
}

Only the const and volatile type-specifiers at the outermost level of the parameter type specification are ignored in this fashion; const and volatile type-specifiers buried within a parameter type specification 
are significant and can be used to distinguish overloaded function declarations. In particular, for any type T, “pointer to T,” “pointer to const T,” and “pointer to volatile T” are 
considered distinct parameter types, as are “reference to T,” “reference to const T,” and “reference to volatile T.”

6) Two parameter declarations that differ only in their default arguments are equivalent.

#include<iostream>
#include<stdio.h>
  
using namespace std;
  
int f ( int x, int y) {
    return x+10;
}
 
int f ( int x, int y = 10) {
    return x+y;
}
 
int main() {     
  getchar();
  return 0;
}

*/


