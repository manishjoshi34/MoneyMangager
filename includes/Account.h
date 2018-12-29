#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "LoginDetail.h"
#include "ContactInfo.h"
#include "FinacialInfo.h"
#include "Entry.h"
#include "name.h"
#include "ThreadPool.h"

#include<string>
#include<map>
#include<vector>

#define MAXDATE 31
#define MAXMONTH 12
#define MAXYEAR 200

class Date
{
	private:
		int mDD;
		int mMM;
		int mYY;
		vector<Entry*>* mEntries;
	public:
		Date();
		~Date();

		int getDD();
		int getMM();
		int getYY();

		void setDD(const int&);
		void setMM(const int&);
		void setYY(const int&);

		void addEntry(Entry* aEntry);

		vector<Entry*>* getEntryVector();
		
};
class Month 
{
	private:
		vector<Date>* mDates;
	public:
		Month();
		~Month();
		Date* getDate(int& dd);
};
class Year
{
	private:
		vector<Month>* mMonths;
	public:
		Year();
		~Year();
		Date* getMonth(int& MM,int DD);
};
class Calender
{
	private:
		vector<Year*> mYears;
	public:
		Calender();
		~Calender();
		Date* getDate(int& DD,int& MM,int& YY);
};

class Account{
	private:
		static long int mNumberOfAccounts;
	private:
		NameElement* mName;
		LoginDetail* mLoginData;
		ContactInfo* mContactInfo;
		FinancialInfo* mFinacialInfo;
		Calender* mCalender;

	public:
	       	Account();
		~Account();
		
		bool AddEntry(const AmountType& aAmount,const EntryType& aEntry);
		std::string GetFullName();
		std::string GetFirstName();
		std::string GetLastName();
		std::string GetMiddleName();
		std::string GetEmailId();
		std::string GetMobileNo();
		std::string GetPancardNo();

		AmountType GetBalance();
		AmountType GetTaxSavingInvestment();
		AmountType GetInvestment();
		AmountType GetTotalTax();
		AmountType GetPaidTax();
		AmountType GetRemainingTax();
		AmountType GetTotalExpence();
		AmountType GetExpenceMonth();
		AmountType GetExpenceDay();
		AmountType GetExpenceYear();
		AmountType GetExpenceCustome();

		void SetName(const std::string&);
		void SetPancardNo(const std::string&);
		void SetEmailId(const std::string&);
		void SetMobileNo(const std::string&);
		
};

long int Account::mNumberOfAccounts = 0;

#endif
