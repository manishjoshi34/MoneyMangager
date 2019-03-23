#include "Account.h"
#include "ContactInfo.h"
#include "Date.h"
#include "Database.h"
#include "Entry.h"
#include "FinancialInfo.h"
#include "LoginDetail.h"
#include "name.h"
#include "log.h"

using namespace std;

typedef long double AmountType;


Account::Account():
	mName(NULL),
	mLoginData(NULL),
	mContactInfo(NULL),
	mFinacialInfo(NULL),
	mDatabase(NULL)
{
	mNumberOfAccounts++;
	LOG("Account Created with no information",mNumberOfAccounts);
}

Account::Account(
		NameElement* name,
		LoginDetail* loginDetail,
		ContactInfo* contactInfo):
	mName(name),
	mLoginData(loginDetail),
	mContactInfo(contactInfo),
	mFinacialInfo(NULL),
	mDatabase(NULL)
{
	mNumberOfAccounts++;
	LOG("Account Created with information",mNumberOfAccounts);

}

Account::~Account()
{
}

bool Account::AddEntry(
		const AmountType& aAmount,
		const EntryType& aEntry,
		Date& aDate)
{
	LOG("Account::AddEntry");

	if(mDatabase == NULL)
		mDatabase =  new Database();
	Entry* entry = new Entry(aAmount, aEntry);
	mDatabase->addEntry(static_cast<Date*>(&aDate), entry);
	return true;	
}
string Account::getFullName()
{
	return mName->getFullName();
}

string Account::getFirstName()
{
	return mName->getFirstName();
}
string Account::getLastName()
{
	return mName->getLastName();
}
string Account::getMiddleName()
{
	return mName->getMiddleName();
}
string Account::getEmailId()
{
	return mContactInfo->getEmail();
}
string Account::getMobileNo()
{ 
	return mContactInfo->getMobile(); 
}

string Account::getAddress()
{ 
	return mContactInfo->getAddress(); 
}

string Account::getPancardNo()
{ 
	return mLoginData->getPancard(); 
}

void Account::SetFullName(string& FullName)
{
	string array[3];
	string delim = " ";

	int start,end = 0,i = 0;

	while((start = FullName.find_first_not_of(delim,end)) != string::npos)
	{
		end  = FullName.find(delim,start);
	       array[i]	= FullName.substr(start,end-start);
	}

	mName->SetFirstName(array[0]);
	mName->SetMiddleName(array[1]);
	mName->SetLastName(array[2]);
}	
void Account::SetFirstName(string& name)
{ mName->SetFirstName(name); }

void Account::SetMiddleName(string& name)
{ mName->SetMiddleName(name); }

void Account::SetLastName(string& name)
{ mName->SetLastName(name); }

void Account::SetPancardNo(string& cardNo)
{
	mLoginData->SetpancardNo(cardNo);
}
void Account::SetEmailId(string& id)
{
	mContactInfo->setEmail(id);
}
void Account::SetMobileNo(string& no)
{
	mContactInfo->setMobile(no);
}
void Account::SetAddress(string& add)
{
	mContactInfo->setAddress(add);
}

AmountType Account::GetBalance()
{
	return mFinacialInfo->getBalance();
}

AmountType Account::GetTaxSavingInvestment()
{
	return mFinacialInfo->getTaxsavingInvestment();
}
AmountType Account::GetInvestment()
{
	return mFinacialInfo->getInvestment();
}
AmountType Account::GetTotalTax()
{

}
AmountType Account::GetPaidTax()
{

}
AmountType Account::GetRemainingTax()
{

}
AmountType Account::GetTotalExpence()
{

}
AmountType Account::GetExpenceMonth()
{

}
AmountType Account::GetExpenceDay()
{

}
AmountType Account::GetExpenceYear()
{

}
AmountType Account::GetExpenceCustome(Date* from,Date* to)
{

}
