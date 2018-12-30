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

class Account{
	private:
		static long int mNumberOfAccounts;
	private:
		NameElement* mName;
		LoginDetail* mLoginData;
		ContactInfo* mContactInfo;
		FinancialInfo* mFinacialInfo;
		map<Date,Database>* mMap;

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
