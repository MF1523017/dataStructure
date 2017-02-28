#include"person.h"
#include<memory>
//Person.c
//construction of Person object
Person* new_Person(const char* const pFirstName, const char* const pLastName)
{
	Person* pObj = nullptr;
	//allocating memory
	pObj = (Person*)malloc(sizeof(Person));
	if (pObj == nullptr)
	{
		return nullptr;
	}
	//pointing to itself as we are creating base class object
	pObj->pDerivedObj = pObj;
	pObj->pFirstName =(char*)malloc(sizeof(char)*(strlen(pFirstName) + 1));
	if (pObj->pFirstName == nullptr)
	{
		return nullptr;
	}
	strcpy(pObj->pFirstName, pFirstName);

	pObj->pLastName = (char*)malloc(sizeof(char)*(strlen(pLastName) + 1));
	if (pObj->pLastName == nullptr)
	{
		return nullptr;
	}
	strcpy(pObj->pLastName, pLastName);

	//Initializing interface for access to functions
	//destructor pointing to destrutor of itself
	pObj->Delete = delete_Person;
	pObj->Display = Person_DisplayInfo;
	pObj->WriteToFile = Person_WriteToFile;

	return pObj;
}
void delete_Person(Person* const pPersonObj)    //destructor
{
	free(pPersonObj->pLastName);
	free(pPersonObj->pFirstName);
	free(pPersonObj->pDerivedObj);
}
void Person_DisplayInfo(Person* const pPersonObj)
{
	printf("firstName is %s\n", pPersonObj->pFirstName);
	printf("lastName is %s\n", pPersonObj->pLastName);
}
void Person_WriteToFile(Person* const pPersonObj, const char* const pFileName)
{
	;
}

