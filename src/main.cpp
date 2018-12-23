#include "Account.h"
#include "Entry.h"
#include "name.h"
#include<iostream>

using namespace std;

extern void print();

const char* test()
{
	string t = "manish joshi";
	return std::move(t.c_str());
}

int main()
{
	NameElement aName;
	aName.SetFirstName("Manish");
	aName.SetMiddleName("Amrutlal");
	aName.SetLastName("Joshi");
	cout <<aName ;
	return 0;
}
