/*
 * Braced initialization is called Uniform initialization
 * Only braces can be used everywhere
 * Prohibits implicit narrowing conversions among build-in data types
 * Drawback:
 	* Priority is given to syd::initializer_list<> ctor
	* If there is no way convert the types of the arguments in a braced initializer to the type in a std::initializer_list compiler will fall back on normal overload resolution
	* If we use empty set of braces to contruct an object that supports default ctor and also supports std::initializer_list construction. The rule is that we get default construction. Empty braces mean no argument, not an empty std::initializer_list
	* Choosing between parentheses and braces for object creation inside templates can be challenging	
 */

#include<iostream>
#include<atomic>
#include<initializer_list>

class Widget {
	public:
		Widget() { std::cout<<"default ctor"<<std::endl; }
		Widget(int i) { std::cout<<"ctor"<<std::endl; }
		Widget(int i, double d) { std::cout<<"ctor"<<std::endl; }
		Widget(std::initializer_list<std::string> ilist) { std::cout<<"Initializer list"<<std::endl; }
		//Widget(std::initializer_list<std::bool> ilist) { std::cout<<"Initializer list"<<std::endl; }
	private:
		int x{0};	//fine
		//int y(0);	//Error
		int z=0;	//fine
};

Widget w1{};	//Calls widget ctor with no args
Widget w({});	//Calls std::initializer_list ctor
Widget w2(1);	//call widget ctor with argument 10
Widget w3();	//declares a function names w2 that returns a widget

int main()
{
	Widget w;
	std::atomic<int> ai1{0};
	std::atomic<int> ai2(0);
	//std::atomic<int> ai3=0;	//Error
	
	double x, y;
	int sum1{x + y}; //Error!
	int sum2(x + y); //Doesn't check for narrowing conversions

	Widget w1(10);	//Works
	Widget w2();	//Works
	Widget w3{};	//Works
	Widget w4{2};	//Works but now call std::initializer_list ctor 
	Widget w5{2, 2.3};	//Error! requires narrowing conversions

	vector<int> v1(10,20);	//use non-std::intializer_list ctor: create 10-element std::vector, all elemnt have value of 20
	vector<int> v2{10,20}; 	//use std::initializer_list ctor: crete 2-element std::vector, element values 10 and 20
}
