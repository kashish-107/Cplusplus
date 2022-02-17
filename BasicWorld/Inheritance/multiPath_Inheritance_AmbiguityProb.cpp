/*
- Avoiding ambiguity using scope resolution operator. Still, there are two copies of ClassA in ClassD.
- Avoiding ambiguity using virtual base class
*/

#include<iostream>
using namespace std;

class A
{
public:
	int x=10;
};

class B : virtual public A
{
public:
	int y=10;
};

class C : virtual public A
{
public:
	int z=20;
};

class D : public B, public C
{
public:
	int i=30;
};

int main()
{
	D obj;
	//obj.x=20; //error

	//Work with virtual base class
	cout<<obj.x<<endl;
	
	cout<<obj.B::x<<endl;
	return 0;
}
