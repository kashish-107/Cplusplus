/*
 * Compile time cast
 * Implicit conversion btw types (such as int to float)
 * Use Static_cast when conversion between types is provided through conversion operator or conversion ctor
 * If typecast a particular object into another but its illegal, static_cast will not allow you to do this
 * static_cast performs a tight type checking.
 * So to use static_cast, inherit it as public.
 * Use static_cast to cast ‘to and from’ void pointer.
 * char* to int* is allowed in C but not with static_cast
 * static_cast avoid cast from derived to private base class
 * Use for all upcast, but never use for confused downcast (No runtime check for static_cast)
 * Error found at compile time
 */

#include<iostream>
#include<string>

using namespace std;

class Int {
	public:
		Int(int x):x{x} {
			cout<<"Conversion Ctor called"<<endl;
		}
		operator string () {
			cout<<"Conversion operator called"<<endl;
			return to_string(x);
		}
	private:
		int x;
};

class base {
};

class derived1 : public base {
};

class derived2 : private base {
};

class derived3 : public base {
};

int main()
{
	int a{10};
	char c{'a'};
	int *p = (int*)&c;  //May fail at run time
	//int *q = static_cast<int*>(&c); //Compile time error
	
	Int obj(10);
	string s = obj; //Conversion operator
	obj = 20; //Conversion ctor
	string str = static_cast<string>(obj);
	obj = static_cast<Int>(30);

	derived1 d;
	base *bptr = (base*)&d;  //allowed
	base *bptr1 = static_cast<base*>(&d); 

	derived2 d2;
	base *bptr2 = (base*)&d2; //works
	//base *bptr3 = static_cast<base*>(&d2); //Compilation Error - Private/protected inheritance
	
	int i{10};
	void *v = static_cast<void*>(&i);
	int *ip = static_cast<int*>(v);

	derived1 d1;
	derived3 d3;

	base *bp1 = static_cast<base*>(&d1);
	base *bp2 = static_cast<base*>(&d3);
	
	//Worng downcast
	derived1 *dp1 = static_cast<derived1*>(bp2);
	derived3 *dp2 = static_cast<derived3*>(bp1);
	return 0;
}
