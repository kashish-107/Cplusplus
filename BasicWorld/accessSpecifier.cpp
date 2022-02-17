/*
1. Public: Will be avaible to everyone.
	Public members of a class can be accessed from anywhere in the program using the direct member access operator (.) with the object of that class. 
2. Private: They are not allowed to be accessed directly by any object or function outside the class. 
	Only the member functions or the friend functions are allowed to access the private data members of a class. 
3. Protected: Protected access modifier is similar to private access modifier in the sense that it can’t be accessed outside of it’s class 
	unless with the help of friend class, the difference is that the class members declared as Protected can be accessed by any subclass(derived class) of that class as well.  
*/

#include<iostream>
using namespace std;


class test
{
public:
	int i=10;
	void show() { cout<<j<<" "<<k<<endl; }
private:
	int j=20;
protected:
	int k;
};

class derived : public test
{
	int a1;
public:
	void show() { 
		k = 15;
		cout<<k<<endl;
		k = 25; 
	}
};

int main()
{
	test t;

	derived d;

	cout<<"Size of base "<<sizeof(t)<<endl;	
	cout<<"Size of derived "<<sizeof(d)<<endl;	
		
	cout<<d.i<<endl;
	d.show();
	cout<<t.i<<endl;
	t.show();

	
	return 0;
}
