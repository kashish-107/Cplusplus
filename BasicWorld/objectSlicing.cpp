/*
 * In C++, a derived class object can be assigned to a base class object, but the other way is not possible
 * Object slicing happens when a derived class object is assigned to a base class object, additional attributes of a derived class object are sliced off to form the base class object
 * Object slicing doesn’t occur when pointers or references to objects are passed as function arguments since a pointer or reference of any type takes same amount of memory
 * Object slicing can be prevented by making the base class function pure virtual there by disallowing object creation. It is not possible to create the object of a class which contains a pure virtual method.
 */

#include<iostream>

using namespace std;

class Base {
	int x, y;
};

class Derived : public Base {
	int z, w;
};

class Base1 {
	public:
		Base1(int x):i{x} { }
		virtual void display() {
			cout<<"I am base class object, i="<<i<<endl;
		}
	protected:
		int i{0};
};

class Derived1 : public Base1 {
	public:
		Derived1(int x, int y):Base1(x), j{y} {	}
		void display() override {
			cout<<"I am derived class object, i="<<i<<" j="<<j<<endl;
		}
	private:
		int j{0};
};

void somefun(Base1 b)	//Base class object is Passed by value
{
	b.display();
}

void somefun1(Base1& b) //Passed by reference
{
	b.display();
}

void somefun2(Base1* b) //Passed by pointer
{
	b->display();
}

int main()
{
	Derived d;
	Base b = d; //Object slicing, z and w will be sliced off

	Base1 b1(10);
	Derived1 d2(20,30);

	//Pass by value
	somefun(b1);
	somefun(d2); //Object slicing, the member j of d is sliced off

	//Pass by reference
	somefun1(b1);
	somefun1(d2);	// No Object Slicing

	//Pass by pointer
	somefun2(&b1);
	somefun2(&d2);	// No Object Slicing
	return 0;
}
