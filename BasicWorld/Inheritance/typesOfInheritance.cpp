#include<iostream>
using namespace std;

class base1 { };

class base2 { };

class single : public base1 { };

class multiple : public base1, public base2 { };

class multilevel : public single { };

class hierarchical : public base1 { /* More than one class is inherited from base1 class */ };

class hybrid_MultiPath : public single, public hierarchical { };

int main()
{
	return 0;
}
