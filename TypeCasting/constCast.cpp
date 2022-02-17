/*
 * const_cast is used to cast away the constness of variables
 * const_cast can be used to change non-const class members inside a const member function
 * const_cast can be used to pass const data to a function that doesn’t receive const
 * It is undefined behavior to modify a value which is initially declared as const. (const int i=10; const int* ptr)
 * const_cast is considered safer, safer in the sense that the casting won’t happen if the type of cast is not same as original object
 * const_cast can also be used to cast away volatile attribute
 */

#include<iostream>
using namespace std;

class A
{
	public:
		void change() const
		{
			(const_cast<A*>(this))->i=20;
			cout<<this->i<<endl;
		}
	private:
		int i{10};
};

void fun(int *p)
{
	*p = *p + 1;
}

int main()
{
	A obj;
	obj.change();

	const int i=10;
	const int* ptr=&i;
	fun(const_cast<int*>(ptr));
	cout<<i<<endl;

	char c = 'a';
	char *cp = &c;
//	int *ip = const_cast<int*>(cp);	//Compilation error

	int a1 = 20;
	//typeid of b1 is PVKi (pointer to a volatile and constant integer) and typeid of c1 is Pi (Pointer to integer)
	const volatile int* b1 = &a1;
	cout<<"typeid of b1 "<<typeid(b1).name()<<endl;
	int *c1 = const_cast<int*>(b1);
	cout<<"typeid of c1 "<<typeid(c1).name()<<endl;
	return 0;
}
