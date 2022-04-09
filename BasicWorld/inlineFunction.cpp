/*
 * When the program executes the function call instruction the CPU stores the memory address of the instruction following the function call, copies the arguments of the function on the stack and finally transfers control to the specified function. The CPU then executes the function code, stores the function return value in a predefined memory location/register and returns control to the calling function
 
 * This can become overhead if the execution time of function is less than the switching time from the caller function to called function (callee).
 
 *  This overhead occurs for small functions because execution time of small function is less than the switching time.

 *  Inline function is a function that is expanded in line when it is called

 *  When the inline function is called whole code of the inline function gets inserted or substituted at the point of inline function call. This substitution is performed by the C++ compiler at compile time.

 *  Inline function may increase efficiency if it is small.

 *  Remember, inlining is only a request to the compiler, not a command. Compiler can ignore the request for inlining. Compiler may not perform inlining in such circumstances like:
1) If a function contains a loop. (for, while, do-while)
2) If a function contains static variables.
3) If a function is recursive.
4) If a function return type is other than void, and the return statement doesn’t exist in function body.
5) If a function contains switch or goto statement.

 *  Inline function disadvantages:
1) when inline function body is substituted at the point of function call, total number of variables used by the function also gets inserted. So the number of register going to be used for the variables will also get increased. So if after function inlining variable numbers increase drastically then it would surely cause an overhead on register utilization.
2) If you use too many inline functions then the size of the binary executable file will be large, because of the duplication of same code.
3) Too much inlining can also reduce your instruction cache hit rate, thus reducing the speed of instruction fetch from that of cache memory to that of primary memory.
4) Inline function may increase compile time overhead if someone changes the code inside the inline function then all the calling location has to be recompiled because compiler would require to replace all the code once again to reflect the changes, otherwise it will continue with old functionality.
5) Inline functions may not be useful for many embedded systems. Because in embedded systems code size is more important than speed.
6) Inline functions might cause thrashing because inlining might increase size of the binary executable file. Thrashing in memory causes performance of computer to degrade.

 * All the functions defined inside the class are implicitly inline
 
 * If you need to explicitly declare inline function in the class then just declare the function inside the class and define it outside the class using inline keyword
*/

#include<iostream>

using namespace std;

inline void func() {
}

class S
{
	public:
		int square(int s);
};

inline int S::square(int s) {
	return s*s*s;
}

int main()
{
	func();
	return 0;
}
