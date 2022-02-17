/*
 * Used to convert a pointer of some data type into a pointer of another data type, even if the the data types before and after conversion are different
 * It does not check if the pointer type and data pointed by the pointer is same or not.
 * It doesn’t have any return type. It simply converts the pointer type.
 * reinterpret_cast is a very special and dangerous type of casting operator
 * It is used when we want to work with bits.
 * If we use this type of cast then it becomes a non-portable product. So, it is suggested not to use this concept unless required.
 * It is only used to typecast any pointer to its original type.
 */
 

#include<iostream>

using namespace std;

struct abc {
	int i;
	int j;
	char c;
	bool b;
};

int main()
{
	abc s{10,20,'c',true};
	
	int *p = reinterpret_cast<int*>(&s);
	cout<<*p<<endl;

	p++;
	cout<<*p<<endl;

	p++;

	char *c = reinterpret_cast<char*>(p);
	cout<<*c<<endl;

	c++;

	bool *b = reinterpret_cast<bool*>(c);
	cout<<*b<<endl;

	return 0;
		
}
