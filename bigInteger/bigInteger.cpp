// bigInteger.cpp : Defines the entry point for the console application.
//

#include"stringMath.h"

#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;


int main()
{
	using namespace sMath;
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << subString(s1,s2) << endl;
	}
    return 0;
}

