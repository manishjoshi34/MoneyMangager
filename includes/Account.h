#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "Entry.h"
#include "NameElement.h"

#include<string>
#include<map>
#include<vector>

class ContactInfo;
class Date;
class Database;
class Entry;
class FinancialInfo;
class LoginDetail;
class NameElement;

typedef long double AmountType;


class Account{
	private:
		static long int mNumberOfAccounts;
	private:
		NameElement* mName;
		LoginDetail* mLoginData;
		ContactInfo* mContactInfo;
		FinancialInfo* mFinacialInfo;
		Database* mDatabase;


	public:
	    Account();
		Account(NameElement*,LoginDetail*,ContactInfo*);
		~Account();
		
		bool AddEntry(
				const AmountType& aAmount,
				const EntryType& aEntry,
				Date& aDate);
		std::string getFullName();
		std::string getFirstName();
		std::string getLastName();
		std::string getMiddleName();
		std::string getEmailId();
		std::string getMobileNo();
		std::string getPancardNo();
		std::string getAddress();


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
		AmountType GetExpenceCustome(Date*,Date*);

		void SetFullName(std::string&);
		void SetFirstName(std::string&);
		void SetMiddleName(std::string&);
		void SetLastName(std::string&);
		void SetPancardNo(std::string&);
		void SetEmailId(std::string&);
		void SetMobileNo(std::string&);
		void SetAddress(std::string&);
	
		bool CheckPassword(std::string&);	
};


#endif
