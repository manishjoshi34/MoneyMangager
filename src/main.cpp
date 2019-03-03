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


void print_menu()
{
	const char* MENU_STRING = 
			"Hello!\nPlease Select Menu option and press Enter\n";
	cout<<MENU_STRING;
	
	for(int i=0;i<menu_items;i++)
	{
		cout<<i<<") "<< Menu[i].c_str()<<endl;
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
			case 6:
			      Exit();
			      break;
			default :
			      cout<<"ENTER VALID OPTION\n";
			      break;		
		}

	}

}




