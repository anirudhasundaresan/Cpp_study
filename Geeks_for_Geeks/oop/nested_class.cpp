/*
Nested classes are classes inside other classes. 
The one inside acts as any other member function of the bigger class and thus can access data from the bigger class.
But, the bigger class cannot access the data from the one inside. 
*/

#include <iostream>
 
using namespace std;
 
 /* start of Enclosing class declaration */ 
class Enclosing {      
       
   int x;
    
   /* start of Nested class declaration */ 
   class Nested {
      int y;   
      void NestedFun(Enclosing *e) {
        cout<<e->x;  // works fine: nested class can access 
                     // private members of Enclosing class
      }       
   }; // declaration Nested class ends here
}; // declaration Enclosing class ends here
 
int main()
{
	// don't know what to put here     
}