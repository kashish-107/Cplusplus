/*
 * Copy elision (or Copy omission) is a compiler optimization technique that avoids unnecessary copying of objects
 * RVO can still apply even when the function has several return statements, as long as the returned objects are created on the return statements
 *  if we still want to ensure that the compiler doesn’t elide the call to copy constructor [disable the copy elision], we can compile the program using “-fno-elide-constructors” option with g++
 *  most of the C++ compilers avoid such overheads of creating a temporary object & then copying it
 */

#include<iostream>
using namespace std;

class base
{
	public:
		base(int i=0) { cout<<"Default Ctor"<<endl; }
		base(const base& obj) { cout<<"Copy Ctor"<<endl; }
};

base rvo()
{
	return base();
}

base nrvo()
{
	base b;
	return b;
}

base fun(int cond)
{
	if(cond) {
		base b;
		return b;
	}
	else {
		return base();	//RVO applied as object is created on return statement
	}
}

int main()
{
	base b1 = rvo();
	base b2 = nrvo();
	base b3 = 1;	//base b3(1); //direct initialization
	base b4 = fun(1);
	return 0;
}
