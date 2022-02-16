#include<iostream>
#include<memory>
#include<string.h>
using namespace std;

class test
{
public:
	test():_ip{nullptr}, _cp{nullptr} { }

	test(int i, const char *str = nullptr) {
	        _ip = new int(i);	
		_cp = new char[strlen(str)+1];
		strcpy(_cp, str);
	}

	test(const test& obj) {
		cout<<"Copy ctor"<<endl;
		_ip = new int(*obj._ip);
		_cp = new char[strlen(obj._cp)+1];
		strcpy(_cp, obj._cp);
	}

	test& operator= (const test& obj) {
		cout<<"Assignment operator"<<endl;
		if(!_ip) 
			_ip = new int(0);
		*_ip = *(obj._ip);
		return *this;
	}

	void show() {
		cout<<"Value="<<*_ip<<endl;
		cout<<"String="<<_cp<<endl;
	}

	~test() {
		cout<<"Dtor"<<endl;
		delete _ip;
		delete [] _cp;
	}
private:
	int* _ip;
	char* _cp;
	int size{0};
};

int main()
{
	test t1(10, "abc");
	test t2 = t1;
	t1.show();
	t2.show();

	test t3;
	t3 = t2;
	t2.show();	
	return 0;
}

