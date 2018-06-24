// Default arguments can be given for any function:

/*
#include <iostream>
using namespace std;
 
// A function with default arguments, it can be called with 
// 2 arguments or 3 arguments or 4 arguments.
int sum(int x, int y, int z=0, int w=0)
{
    return (x + y + z + w);
}
 
int main()
{
    cout << sum(10, 15) << endl;
    cout << sum(10, 15, 25) << endl;
    cout << sum(10, 15, 25, 30) << endl;
    return 0;
}

// Invalid because z has default value, but w after it 
// doesn't have default value
int sum(int x, int y, int z=0, int w)
*/


#include <iostream>
using namespace std;
 
void print(int i) {
  cout << " Here is int " << i << endl;
}
void print(double  f) {
  cout << " Here is float " << f << endl;
}
void print(char* c) {
  cout << " Here is char* " << c << endl;
}
 
int main() {
  print(10);
  print(10.10);
  print("ten"); // char* c = "ten" = arr = &arr[0], where char arr[3] = {'t','e','n'} // not sure...need to check
  return 0;
}