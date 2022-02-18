/*
 * template<typename T>
   void f(ParamType param);
 * When a variable is declared using auto,
   	- auto plays a role of T in the template
 	- type specifier for the variable act as ParamType
 * auto type deduction works like template type deduction (with one expection)
 * when the initializer for an auto-declared variable is enclosed in braces {}, the deduced type is a std::initializer_list
 * braced initalization is the only way in which auto type deduction and template type deduction differs
 * auto assume that a braced initializer represents a std::initializer_list, but template type deduction doesn't
 * auto return type that returns a braced initializer won't compile
 */

#include<iostream>

using namespace std;

template<typename T>
void fun(T param)
{
}

template<typename T>
void fun(initializer_list<T> initlist)
{
}

void someFunc(int, double)
{
}

auto createInitList()
{
	//return {1, 2, 3};	//error: can't deduce type
}

int main()
{
	auto x = 27;		//T is auto
	const auto cx = x;	//const auto is a type specifier
	const auto& rx = x;	//const auto& is a type specifier

	auto&& uref1 = x;	//x is int and lvalue, so uref1 type is int&
	auto&& uref2 = cx;	//cx is const int and lvalue, so uref2 type is const int&
	auto&& uref3 = 23;	//23 is int and rvalue, so uref3 type is int&&
	
	//decay into pointers
	const char name[] = "abc";
	auto arr1 = name;	//arr1's type is const char*
	auto& arr2= name;	//arr2's type is const char (&)[3]

	auto func1 = someFunc;	//func1's type is void(*)(int, double)
	auto& func2 = someFunc;	//func2's type is void(&)(int, double)
	
	//Special type deduction rule for auto
	auto x1 = 12;	//type is int
	auto x2(12);	//type is int
	auto x3 = {12};	//type is std::initializer_list<int>
	auto x4{12};	//type is std::initializer_list<int>
	
	//auto x5 = {1, 2.0};	//error! can't deduce T for std::initializer_list<T>

	auto x6 = {10, 12, 5};	//x's type is initializer_list<int>
	fun(x6);	//works
	fun({10, 12});	//error! can't deduce type for T	

	//createInitList();
	//auto lmb = [](const auto& initlist) { };
	//lmb({1, 2, 3});	//error! can't deduce type for {1, 2, 3}

	return 0;
}
