#include "LoginDetail.h"
#include "ContactInfo.h"
#include "log.h"
#include "Database.h"
#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<stdlib.h>

using namespace std;



string Menu[] = {
	"CREATE ACCOUNT",
	"LOGIN",
	"ADD ENTRY",
	"SHOW ENTRY",
	"DELETE ENTRY",
	"EXIT",
	"PERSONAL DETAIL",
	"FIANCIAL DETAIL",
	"EDIT PROFILE"
};

const int menu_items = 8;
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
	
	for(int i=1;i<=menu_items;i++)
	{
		cout<<i<<") "<< Menu[i-1].c_str()<<endl;
	}

}
void CreateAccount()
{

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
			      system("clear");
			      print_header();
			      print_menu();
			      break;
			case 2:
			      Login();
			      system("clear");
			      print_header();
			      print_menu();
			      break;
			case 3:
			      AddEntry();
			      system("clear");
			      print_header();
			      print_menu();
			      break;
			case 4:
			      ShowEntry();
			      system("clear");
			      print_header();
			      print_menu();
			      break;
			case 5:
			      DeletEntry();
			      system("clear");
			      print_header();
			      print_menu();
			      break;
			case 6:
			      Exit();
			      system("clear");
			      print_header();
			      break;
			default :
			      cout<<"ENTER VALID OPTION\n";
			      system("clear");
			      print_menu();
			      break;		
		}

	}

}




