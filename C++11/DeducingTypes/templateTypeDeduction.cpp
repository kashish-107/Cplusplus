/*
 * Paramtype is a pointer or reference
 * Paramtype is a universal reference
 * Paramtype is Neither a Pointer nor a Reference
 */

#include<iostream>

template<typename T>
void f1(T& param)    //param is a refrence
{
}

template<typename T>
void f2(const T& param)
{
	//Assuming that param is a reference-to-const, 
	//there's no longer a need for const to be deduced as part of T
}

template<typename T>
void f3(T* param)	//param is a pointer
{
}

template<typename T>
void f4(T&& param)	//param is now a universal reference
{
	//Although Paramtype is declared using the syntax for an rvalue reference
	//its deduced type is an lvalue reference
	//when universal references are in use, type deduction distinguishes btw lvalue and rvalue
}

template<typename T>
void f5(T param)	//param is now passed by value
{
	/* 
	 * expr's constness is ignored when deducing a type for param:
	 * just beacause expr can't be modified doesn't mean that a copy of it can't be
	 * const is ignored only for by-value parameter. For parameters that are references-to- or pointer-to-const,
	 * the constness of expr is preserved during type deduction
	 */
}

int main()
{
	int x = 27;
	const int cx = x;	//cx is const int
	const int& rx = x;	//rx is reference to x as a const int
	
	//Parameter type is reference
	f1(x);	//T is an int, param's type is int&
	f1(cx);	//T is const int, param's type is const int&
	f1(rx);	//T is const int, param's type is const int&

	//Parameter type is const T&
	f2(x);	//T is an int, param's type is const int&
	f2(cx);	//T is an int, param's type is const int&
	f2(rx);	//T is an int, param's type is const int&

	//Parameter type is pointer
	const int* px = &x;
	f3(&x);	//T is an int, param's type is int*
	f3(px);	//T is an const int, param's type is const int*

	//Parameter type is now a Universal reference
	f4(x);	//x is lvalue, T is a int&, param's type is int&
	f4(cx);	//x is lvalue, T is a const int&, param's type is const int&
	f4(rx);	//x is lvalue, T is a const int&, param's type is const int&
	f4(12);	//rvalue, T is a int, param's type is int&&
	
	//Parameter is now passed by value
	f5(x);	//T and param's types are both int
	f5(cx);	//T and param's types are both int
	f5(rx);	//T and param's types are both int

	const char* const ptr = "Fun with pointer";
	//Pointer itself(ptr) will be passed by value, so the constness of ptr will be ignored
	f5(ptr); //param's type will be const char* i.e, a modifiable pointer to const char*

	//Array arguments
	const char name[] = "abc";
	const char *ptrtoName = name; //array decays to pointer
	f5(name);	//name is array, but T deduced as a const char*
	f1(name);	//T is the actual type of array const char[13], the type of f1 param's is const char (&)[13]

	return 0;
}

