/*
1. Private mode- Has-a relationship. Both public member and protected members of the base class will become Private in derived class.
2. Protected mode- Both public member and protected members of the base class will become protected in derived class.
3. Public mode- Is-a relationship. Public member of the base class will become public in the derived class and protected members of the base class will become protected in derived class.
*/

#include<iostream>
using namespace std;

class base
{
public:
	int i=1;
protected:
	int j=2;
private:
	int k=3;
};
 
class prvDerived : private base
{
    	// i is private
    	// j is private
    	// k is not accessible from prvDerived
public:
	void show() {
		cout<<"Public data of base"<<i<<endl;
		cout<<"Protected data of base"<<j<<endl;
	//	cout<<"Private data of base"<<k<<endl;
	}
};

class proDerived : protected base
{
    	// i is protected
    	// j is protected
    	// k is not accessible from proDerived
public:
	void show() {
		cout<<"Public data of base"<<i<<endl;
		cout<<"Protected data of base"<<j<<endl;
	//	cout<<"Private data of base"<<k<<endl;
	}

};

class pubDerived : public base
{
    	// i is public
    	// j is protected
    	// k is not accessible from pubDerived
public:
	void show() {
		cout<<"Public data of base"<<i<<endl;
		cout<<"Protected data of base"<<j<<endl;
	//	cout<<"Private data of base"<<k<<endl;
	}

};

int main()
{
	base b;
	cout<<b.i<<endl;

	prvDerived prvD;
	//cout<<prvD.i<<endl; //error
	prvD.show();

	proDerived proD;
	//cout<<proD.i<<endl;
	proD.show();

	pubDerived pubD;
	cout<<pubD.i<<endl;
	pubD.show();

	cout<<sizeof(prvDerived);

	return 0;
}
