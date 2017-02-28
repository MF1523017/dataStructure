#include"person.h"
#include"employee.h"
#include<iostream>
#include<vector>

void testVectorPushBackError()
{
	int i = 0;
	std::vector<int> test;
	while ( true )
	{
		test.push_back(i);
		++i;
	}
}
class Base
{
public:
	Base(int a) :_a(a) {}
	virtual void func() {
		std::cout << "base" << std::endl;
	}
	virtual void g()
	{
		;
	}
private:
	int _a;
};
class Base1
{
public:
	virtual void f() {};
};
class Derivor:public Base,public Base1
{
public:
	Derivor(int a) :Base(a) {}
	virtual void func()
	{
		std::cout << "Derivor" << std::endl;
	}
	virtual void g()
	{
		;
	}
private:
	int _d;
};
int main(int argc, char **argv)
{
	testVectorPushBackError();
	Derivor d(2);
	Base *p = &d;
	d.func();
	p->func();
	//std::cout << sizeof(d);//结果是12，虚指针在最开始占有四个字节，虚指针指向虚表的地址
	/*
1>  
1>  class Derivor	size(16):
1>  	+---
1>   0	| +--- (base class Base)
1>   0	| | {vfptr}
1>   4	| | _a
1>  	| +---
1>   8	| +--- (base class Base1)
1>   8	| | {vfptr}
1>  	| +---
1>  12	| _d
1>  	+---
1>//两个虚函数表，两个虚指针
1>  Derivor::$vftable@Base@:
1>  	| &Derivor_meta
1>  	|  0
1>   0	| &Derivor::func
1>   1	| &Derivor::g
1>
1>  Derivor::$vftable@Base1@:
1>  	| -8
1>   0	| &Base1::f
1>
*/
	//函数指针实现多态

	Person* PersonObj = new_Person("Anjali", "Jaiswal");
	Person* EmployeeObj = new_Employee("Gauri", "Jaiswal", "HR", "TCS", 40000);

	//accessing person object

	//displaying person info
	PersonObj->Display(PersonObj);
	//writing person info in the persondata.txt file
	PersonObj->WriteToFile(PersonObj, "persondata.txt");
	//calling destructor
	PersonObj->Delete(PersonObj);

	//accessing to employee object

	//displaying employee info
	EmployeeObj->Display(EmployeeObj);
	//writing empolyee info in the employeedata.txt file
	EmployeeObj->WriteToFile(EmployeeObj, "employeedata.txt");
	//calling destrutor
	EmployeeObj->Delete(EmployeeObj);

	return 0;
}