#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <queue>
#include <stdlib.h>

#include "log.h"
#include "ContactInfo.h"
#include "LoginDetail.h"
#include "Account.h"
#include "NameElement.h"

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
	HEADER_STRING << "******************************************************"<<"\n"
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
		cout<<setw(5);
		cout<<i<<") "<< Menu[i-1].c_str()<<"\t\t\t"<<i+1<<") "<<Menu[i]<<endl;
	}

}
void CreateAccount(map<string,Account>& myMap)
{
	
	LOG("main","CreateAccount");

	string FirstName,MiddleName,LastName;
	cout<<"--> Enter Your First Name : ";
	cin>>FirstName;
	cout<<"--> Enter Your Middle Name : ";
	cin>>MiddleName;
	cout<<"--> Enter Your Last Name : ";
	cin>>LastName;

	NameElement* name = new NameElement(
			FirstName,
			MiddleName,
			LastName);
	cout<<"Your full Name is : "<<name->getFullName()<<endl;

	string aAddress,aEmail,aMob;
	cout<<"--> Enter Your Address: ";
	getchar();
	getline (cin, aAddress);
	cout<<"--> Enter Your EmailId: ";
	getline (cin, aEmail);
	cout<<"--> Enter Your Mobile Number: ";
	getline (cin, aMob);

	ContactInfo* info = new ContactInfo(aAddress,aEmail,aMob);

	cout<<"Your Contact Detail is: "<<info->toString()<<endl;

	string pancard,password,tempPassword;

	cout<<"--> Enter Your Pancard Number: ";
	getline (cin, pancard);
	
	bool getpass;
	do{
		getpass = false;
		cout<<"--> Enter Your Password: ";
		getline (cin, password);

		cout<<"--> Confirm your Password: ";
		getline (cin, tempPassword);
		
		if(password.compare(tempPassword) != 0)
		{
			cout<<"Both password is different!"
				<<" Please try again"<<endl;
			getpass = true;
		}

	}while(getpass);

	LoginDetail* login = new LoginDetail();
	login->SetLoginDetail(pancard,password);

	Account* aAccount = new Account(name,login,info);
	
	myMap.insert(make_pair(pancard,*aAccount));

	cout<<"Congratulation! "<<name->getFullName()<<endl;
	cout<<"Your Account is Open"<<endl;

}
void Login(map<string,Account>& myMap){

	LOG("main","Login");

	string pancard,password;
	cout<<"--> Enter pancard Number: ";
	getchar();
	getline (cin, pancard);

	cout<<"--> Enter Password: ";
	getline (cin, password);

	auto itr = myMap.find(pancard);

	Account* aAccount;

	if(itr != myMap.end())
	{
		aAccount = &(itr->second);
		if(aAccount->CheckPassword(password))
		{
			cout<<" Welcome "<<aAccount->getFullName()<<endl;
		}
		else
		{
			cout<<" Please check your password"<<endl;
			return;
		}
	}
	else
	{
		cout<<"This Pancard is not in database"<<endl;
	}


}

void save(map<string,Account>& myMap)
{

}

void AddEntry(){}

void ShowEntry(){}

void DeletEntry(){}

void Exit(){

	while_condition =false;
	cout<<"Exiting.........."<<endl;

}


int main()

{	map<string, Account> aAccountData;
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
		 	      CreateAccount(aAccountData);
			      break;
			case 2:
			      Login(aAccountData);
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




