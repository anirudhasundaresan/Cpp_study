// #include <cmath> -- for both ceil and floor

// an object working as a function after initialization of the object parameters..

/*
#include <iostream>
using namespace std;

class Mul
{
	int _val;
public:
	Mul() // can be condensed into Mul() {}
	{

	}
	Mul(int x) // can be condensed into --> Mul (int x): _val{x} {}
	{
		_val = x; 
	}
	int operator () (int val)
	{
		return val*_val; 
	}

};

int main()
{
	Mul mul12(12);
	cout << mul12(2) << " " << mul12(3) << endl; 
	return 0; 
}
*/

// Another example using transform from STL.

#include <iostream>
#include <bits/stdc++.h> // needed for transform
using namespace std;

class increment
{
private:
	int num; 
public:
	increment(int n) // param constructor // another way of writing: increment(int n): num(n) {} -- check? 
	{
		num = n; 
	}
	int operator () (int arr_num) const //const why? 
	{
		return num + arr_num; 
	}
};

int main()
{
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int to_add = 5; 
	increment obj(to_add); //created an object of class increment
	transform(arr, arr+n, arr, obj); // arr to arr+n is passed to the object function 
	// transform (InputIterator first1, InputIterator last1, OutputIterator result, UnaryOperator op)
	for (int i =0; i<n; ++i)
	{
		cout << arr[i] << " "; 
	}
	return 0;
}