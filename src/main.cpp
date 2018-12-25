#include "Account.h"
#include "Entry.h"
#include "name.h"
#include "log.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

extern void print();

const char* test()
{
	string t = "manish joshi";
	return std::move(t.c_str());
}
class CreatAccount
{
	public:
		void Create()
		{
			NameElement aName;
			aName.SetFirstName("Manish");
        		aName.SetMiddleName("Amrutlal");
        		aName.SetLastName("Joshi");
        		LOG("CreateAccount",__FUNCTION__,"Account Created for: "+aName.toString());
        
		}
};

int main()

{
	InitLogger();
	//const string filename = "logs.mj";
       	//ofstream* obj=new ofstream;

	//obj->open("logs.mj",std::ios_base::binary|std::ios_base::out);
	//if(obj->is_open())
	//{
	//	cout<<"open";
	//}
	(new CreatAccount())->Create();
	return 0;
}

