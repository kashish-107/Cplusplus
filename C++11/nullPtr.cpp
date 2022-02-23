/*
 * Using nullptr instead of 0 or NULL avoids overload resoltion surprises
 * Improve code clarity, especially when auto variables are involved
 */

#include<iostream>

using namespace std;

void f(int) {
	cout<<"f(int)"<<endl;
}

void f(bool) { 
	cout<<"f(bool)"<<endl;
}

void f(void*) { 
	cout<<"f(void*)"<<endl;
}

int main()
{
	f(0);
	//f(NULL);	//might not compile, but typically calls f(int). Never calls f(void*)
	f(nullptr);

	auto result = find_records(/* arguments */);
	//if(result == 0)	//Not clear whether result is a pointer type or an integral type
	//if(result == nullptr)	//No ambiguity: result must be a pointer type

	return 0;	
}
