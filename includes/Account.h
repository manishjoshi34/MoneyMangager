#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "Entry.h"
#include "mQueue.h"

#include<string>

class Account{
	private:
		static long int mNumberOfAccounts;
	private:
		std::string* mPancardNo;
		std::string* mName;
		std::string* mEmail;
		std::string* mPhone;
		std::string* mMobile;

		AmountType mBalance;
		AmountType mTotalTax;
		AmountType mTaxPaid;
		AmountType mTaxExcemtedAmount;

		mQueue<Entry*> mEntries;

	public:
	       	Account();
		virtual ~Account();
		AmountType GetMyBalance();
		AmountType GetMyRemainingTax();
		void showAllEntries();

		std::string GetName();
		std::string GetEmailId();
		std::string GetMobileNo();
		std::string GetPhoneNo();
		std::string GetPancardNo();
		std::string GetBalance();
		std::string GetMyTotalTax();
		std::string GetMyPaidTax();
		std::string GetRemainingTax();

		void SetName(std::string*);
		void SetPancardNo(std::string*);
		void SetEmailId(std::string*);
		void SetMobileNo(std::string*);
		void SetPhoneNo(std::string*);
};

long int Account::mNumberOfAccounts = 0;

#endif
