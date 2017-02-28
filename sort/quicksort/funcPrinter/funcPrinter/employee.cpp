#include"employee.h"
#include<memory>
//Employee.c
Person* new_Employee(const char* const pFirstName, const char* const pLastName,
	const char* const pDepartment,
	const char* const pCompany, int nSalary)
{
	Employee* pEmpObj;
	//calling base class construtor
	Person* pObj = new_Person(pFirstName, pLastName);
	//allocating memory
	pEmpObj =(Employee*)malloc(sizeof(Employee));
	if (pEmpObj == nullptr)
	{
		pObj->Delete(pObj);
		return nullptr;
	}
	pObj->pDerivedObj = pEmpObj; //pointing to derived object

								 //initialising derived class members
	pEmpObj->pDepartment =(char *)malloc(sizeof(char)*(strlen(pDepartment) + 1));
	if (pEmpObj->pDepartment == nullptr)
	{
		return nullptr;
	}
	strcpy(pEmpObj->pDepartment, pDepartment);
	pEmpObj->pCompany =(char *)malloc(sizeof(char)*(strlen(pCompany) + 1));
	if (pEmpObj->pCompany == nullptr)
	{
		return nullptr;
	}
	strcpy(pEmpObj->pCompany, pCompany);
	pEmpObj->nSalary = nSalary;

	//Changing base class interface to access derived class functions
	//virtual destructor
	//person destructor pointing to destrutor of employee
	pObj->Delete = delete_Employee;
	pObj->Display = Employee_DisplayInfo;
	pObj->WriteToFile = Employee_WriteToFile;
	return pObj;
}
void delete_Employee(Person* const pPersonObj)    //destructor
{
	delete_Person(pPersonObj);
}

void Employee_DisplayInfo(Person* const pPersonObj)
{
	Person_DisplayInfo(pPersonObj);
	Employee* pEmpObj = (Employee*)(pPersonObj->pDerivedObj);
	printf("department is %s\n", pEmpObj->pDepartment);
	printf("company is %s\n", pEmpObj->pCompany);
	printf("salary is %d\n", pEmpObj->nSalary);
}
void Employee_WriteToFile(Person* const pPersonObj, const char* const pFileName)
{
	;
}