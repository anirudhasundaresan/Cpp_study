/* There are 4 main ways of using static keyword in C++. Whatever is static, space for it gets allocated till the end of the program. 
1) declare static variable in a function 
In this case, the init happens only once and the value of the variable is stored for future function call

// C++ program to demonstrate 
// the use of static Static 
// variables in a Function
#include <iostream>
#include <string>
using namespace std;
 
void demo()
{ 
    // static variable
    static int count = 0;
    cout << count << " ";
     
    // value is updated and
    // will be carried to next
    // function calls
    count++;
}
 
int main()
{
    for (int i=0; i<5; i++)    
        demo();             /// output: 0 1 2 3 4
    return 0;
}

2) declare static objects of a class
Note that the object is alive till the end of program even if it is created in an if construct/ any other scope. 

// CPP program to illustrate
// when not using static keyword
#include <iostream>
using namespace std;
 
class GfG
{
    int i;
    public:
        GfG()
        {
            i = 0;
            cout << "Inside Constructor\n";
        }
        ~GfG()
        {
            cout << "Inside Destructor\n";
        }
};
 
int main()
{
    int x = 0;
    if (x==0)
    {
        static GfG obj; // without static, Inside cons, inside dec, end of main
        // with static, inside cons, end of main, inside dec...object is killed at the end of the program only.
    }
    cout << "End of main\n";
}


3) declare static data member of a class (static variables in a class):
These variables are shared by the object. There cannot be multiple copies of the same static variables for different objects. Thus, because of this, static variables can't be init using constructors. 

// C++ program to demonstrate static
// variables inside a class
 
#include<iostream>
using namespace std;
 
class GfG
{
   public:
     static int i;
     
     GfG()
     {
        // Do nothing
     };
};

int GfG::i = 1 // give this first

int main()
{
  GfG obj1;
  // GfG obj2;
  // obj1.i =2; 
  // obj2.i = 3; // will give error since we are trying to change the value of the static variable.
  
  cout << obj.i
   
  // prints value of i
  // cout << obj1.i<<" "<<obj2.i;   
}

4) declare static functions of the class
Static member functions are not dependent on the object of the class. Recommended to use obj.func_name to call but it is better to use GfG::func_name() to call. 
***Very imp: Static member functions are allowed to access only the static data members or other static member functions, they can not access the non-static data members or member functions of the class.

// C++ program to demonstrate static
// member function in a class
#include<iostream>
using namespace std;
 
class GfG
{
   public:
     
    // static member function
    static void printMsg()
    {
        cout<<"Welcome to GfG!";
    }
};
 
// main function
int main()
{
    // invoking a static member function
    GfG::printMsg();
}