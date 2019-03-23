#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<stdlib.h>

#include "log.h"
#include "name.h"

using namespace std;


string Menu[] = {
	"CREATE ACCOUNT",
	"LOGIN",
	"ADD ENTRY",
	"SHOW ENTRY",
	"DELETE ENTRY",
	"PERSONAL DETAIL",
	"FIANCIAL DETAIL",
	"SHOW PROFILE",
	"EDIT PROFILE",
	"EXIT",
	};

const int menu_items = 10;
bool while_condition = true;

void print_header()
{	std::ostringstream HEADER_STRING;
	HEADER_STRING << "************************************************"<<"\n"
		<<"****		WELCOME TO MYSOFT		*******\n"
		<<"****	This Software is to help you manage 	*******\n"
		<<"****	your personal expences and calculate	*******\n"
		<<"****	Tax. I hope you enjoy this software	*******\n"
		<<"*******************************************************\n"
		<<"*******************************************************\n";
	cout<<HEADER_STRING.str();
}
void print_menu()
{
	const char* MENU_STRING = 
			"Hello!\nPlease Select Menu option and press Enter\n";
	cout<<MENU_STRING;
	
	for(int i=1;i<=menu_items;i=i+2)
	{
		cout<<i<<") "<< Menu[i-1].c_str()<<"\t\t\t"<<i+1<<") "<<Menu[i]<<endl;
	}

}
void CreateAccount()
{

	string FirstName,MiddleName,LastName;
	cout<<"--> Enter Your First Name : ";
	cin>>FirstName;
	cout<<"--> Enter Your Middle Name : ";
	cin>>MiddleName;
	cout<<"--> Enter Your Last Name : ";
	cin>>LastName;

	NameElement* name = new NameElement(FirstName,MiddleName,LastName);	   cout<<"Your full Name is : "<<name->getFullName()<<endl;

}
void Login(){}

void AddEntry(){}

void ShowEntry(){}

void DeletEntry(){}

void Exit(){

	while_condition =false;
	cout<<"Exiting.........."<<endl;

}


int main()

{
	system("clear");
	print_header();	
	print_menu();	
	while(while_condition)
	{
		
		int option;
		cin>>option;

		switch (option)
		{
			case 1:
		 	      CreateAccount();
			      break;
			case 2:
			      Login();
			      break;
			case 3:
			      AddEntry();
			      break;
			case 4:
			      ShowEntry();
			      break;
			case 5:
			      DeletEntry();
			      break;
			case 10:
			      Exit();
			      break;
			default :
			      cout<<"ENTER VALID OPTION\n";
			      break;		
		}

	}

}




