#ifndef __FINANCIAL_INFO_H__
#define __FINANCIAL_INFO_H__

#include "log.h"
#include "Entry.h"


typedef long double AmountType;

class FinancialInfo
{
        private:
                AmountType mBalance;
                AmountType mExpence;
                AmountType mInvestment;
                AmountType mTaxsavingInvestment;
                AmountType mRemainingTax;
		AmountType mPaidTax;

		AmountType mExpenceInHealth;
		AmountType mExpenceInShopping;
		AmountType mExpenceInBills;
		AmountType mExpenceInElectronics;
		AmountType mExpenceInEMI;
		AmountType mExpenceInEntertainment;
		AmountType mExpenceInFoodDrinks;
		AmountType mExpenceInFuel;
		AmountType mExpenceInGroceries;
		AmountType mExpenceInRent;
		AmountType mExpenceInTrasfer;
		AmountType mExpenceInTravel;
		AmountType mCreditFromSalary;
		AmountType mCreditFromGift;
		AmountType mCreditFromLoan;
		AmountType mExpenceInOther;
	public:
                FinancialInfo();
                ~FinancialInfo();

                AmountType getBalance(){return mBalance;}
                AmountType getExpence(){return mExpence;}
                AmountType getInvestment(){return mInvestment;}
                AmountType getTaxsavingInvestment(){return mTaxsavingInvestment;}
                AmountType getRemainingTax(){return mRemainingTax;}
		bool Update(EntryType &, AmountType &,bool&);
		bool update(AmountType& aAmount,AmountType& type, bool& st);

};

FinancialInfo::FinancialInfo(){}
FinancialInfo::~FinancialInfo(){}

bool FinancialInfo::update(AmountType& aAmount,
		AmountType& type, 
		bool& st)
{
	if(st)
		type+=aAmount;
	else
		type-=aAmount;
}

bool FinancialInfo::Update(EntryType &aType, AmountType &aAmount,bool &st)
{
	switch (aType)
	{
		case EntryType::HealthCare :
			update(aAmount,mExpence,st);
			update(aAmount,mExpenceInHealth,st);
			break;
		case EntryType::Shopping :
			update(aAmount,mExpence,st);
			update(aAmount,mExpenceInShopping,st);
			break;
		case EntryType::Bills :
			update(aAmount,mExpence,st);
			update(aAmount,mExpenceInBills,st);
			break;
		case EntryType::Electronics :
			update(aAmount,mExpence,st);
			update(aAmount,mExpenceInElectronics,st);
			break;
	}
}
#endif

