/*
- Has a relationship
Uses:
	1. Empty base class optimization
	2. An object that's derived privately can't
	be accessed through a base class pointer (a private base class is referred to as an inaccessible
	base, and an attempt to cast a derived class pointer to the base class will fail)
*/

#include<iostream>

using namespace std;

class Empty
{
public:
	void useful_functions();
};

class Derived: private Empty
{
	int i;
};

class Derived2: public Empty
{
	int i;
};

class Composed
{
	int i;
	Empty e;
};

class Base 
{
public:
	virtual void f() { std::cout << "Base::f()" << std::endl; }
	void g() { f(); }
};

class Derived_2 : private Base 
{
public:
	virtual void f() { std::cout << "Derived::f()" << std::endl; }
 	void h() { g(); }
};

int main()
{
	cout<<"Size of Empty: "<<sizeof(Empty)<<endl;
	cout<<"Size of Derived: "<<sizeof(Derived)<<endl;
	cout<<"Size of Derived2: "<<sizeof(Derived2)<<endl;
	cout<<"Size of Composed: "<<sizeof(Composed)<<endl;

	//Base* bPtr = new Derived_2();
	Derived_2 d;
	d.h();

	Base b;
	b.g();
	return 0;
}
