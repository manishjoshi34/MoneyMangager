#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "Entry.h"

#include<cstring>
#include<queue>

using namespace std;

class Account{
	private:
		static long int mNumberOfAccounts;
	private:
		string* mPancardNo;
		string* mName;
		string* mEmail;
		string* mPhone;
		string* mMobile;

		AmountType mBalance;
		AmountType mTotalTax;
		AmountType mTaxPaid;
		AmountType mTaxExcemtedAmount;

		queue<Entry*> mEntries;

	public:
	       	Account();
		virtual ~Account();
		AmountType GetMyBalance();
		AmountType GetMyRemainingTax();
		void showAllEntries();

		string GetName();
		string GetEmailId();
		string GetMobileNo();
		string GetPhoneNo();
		string GetPancardNo();
		string GetMyBalance();
		string GetMyTotalTax();
		string GetMyPaidTax();
		string GetRemainingTax();

		void SetName(string*);
		void SetPancardNo(string*);
		void SetEmailId(string*);
		void SetMobileNo(string*);
		void SetPhoneNo(string*);
};

static Account::mNumberOfAccounts = 0;


