/*A+B Problem
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 301418		Accepted: 165278
Description

Calculate a+b
Input

Two integer a,b (0<=a,b<=10)
Output

Output a+b
Sample Input

1 2
Sample Output

3
Hint

Q: Where are the input and the output? 

A: Your program shall always read input from stdin (Standard Input) and write output to stdout (Standard Output). For example, you can use 'scanf' in C or 'cin' in C++ to read from stdin, and use 'printf' in C or 'cout' in C++ to write to stdout. 

You shall not output any extra data to standard output other than that required by the problem, otherwise you will get a "Wrong Answer". 

User programs are not allowed to open and read from/write to files. You will get a "Runtime Error" or a "Wrong Answer"if you try to do so. 

Here is a sample solution to problem 1000 using C++/G++: 
*/
#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    cout << a+b << endl;
    return 0;
}
//It's important that the return type of main() must be int when you use G++/GCC,or you may get compile error. 