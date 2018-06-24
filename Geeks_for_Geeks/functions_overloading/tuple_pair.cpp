/*
When you need to return more than one value, use std::tuple (for multiple) and std::pair (for a pair of values).
 
Tuple:
A tuple is an object capable of holding a collection of elements (need not be of the same type)
std::tuple - fixed-size collection of heterogeneous values

Pair:
A specific case of tuple with just 2 values (again, need not be same type). // tuple can also be used to return 2 values. 

Look at the code below:
*/

// std::tuple and std::pair 

// NOTE: compile with g++ -std=c++11 tuple_pair.cpp

#include <bits/stdc++.h>
using namespace std;
 
// A Method that returns multiple values using
// tuple in C++.
tuple<int, int, char> foo(int n1, int n2)
{
    // Packing values to return a tuple
    return make_tuple(n2, n1, 'a');             
}
 
// A Method returns a pair of values using pair
pair<int, int> foo1(int num1, int num2)
{
    // Packing two values to return a pair 
    return make_pair(num2, num1);            
}
 
int main()
{
    int a,b;
    char cc;
     
    // Unpack the elements returned by foo
    tie(a, b, cc) = foo(5, 10);      
     
    // Storing  returned values in a pair 
    pair<int, int> p = foo1(5,2);  
     
    cout << "Values returned by tuple: ";
    cout << a << " " << b << " " << cc << endl;
     
    cout << "Values returned by Pair: ";
    cout << p.first << " " << p.second;
    return 0;
}