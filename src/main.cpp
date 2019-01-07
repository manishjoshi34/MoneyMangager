#include "LoginDetail.h"
#include "ContactInfo.h"
#include "log.h"
#include "Database.h"
#include<iostream>
#include<string>
#include<map>
#include<queue>

using namespace std;


int main()

{
	
	Entry* e1 = new Entry(40,EntryType::Travel);
	Entry* e2 = new Entry(50,EntryType::Travel);
	
	
	Date d1(2,1,2019);
	Date d2(3,4,1993);
	
	Database mDatabase;

	mDatabase.addEntry(d1,*e1);
	mDatabase.addEntry(d1,*e2);
	string data = mDatabase.showEntry(d2,d1);
	cout<<endl<<"Expence: "<<endl;
	cout<<data<<endl;

	return 0;
}

