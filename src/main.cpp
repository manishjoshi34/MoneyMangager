#include "LoginDetail.h"
#include "ContactInfo.h"
#include "log.h"
#include<iostream>
#include<string>

using namespace std;

int main()

{
	
	//InitLogger();
	LoginDetail C;
	ContactInfo I;
	I.setAddress("panvalani khadaki");
	I.setEmail("34joshi@gmail.com");
	I.setMobile("8512030810");
	C.SetLoginDetail("ARKPJ2850Q","1234passWORD");
	if(C.CheckPassword("123Password"))
		cout<<"Password is correct\n";
	else
		cout<<"Password is Wrong\n";
	cout<<I.toString()<<endl;

	//DeletLogger();
	return 0;
}

