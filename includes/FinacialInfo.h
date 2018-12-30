#ifndef __FINANCIAL_INFO_H__
#define __FINANCIAL_INFO_H__

#include "log.h"


typedef long double AmountType;

class FinancialInfo
{
        private:
                AmountType mBalance;
                AmountType mExpence;
                AmountType mInvestment;
                AmountType mTaxsavingInvestment;
                AmountType mRemainingTax;
	public:
                FinancialInfo();
                ~FinancialInfo();

                AmountType getBalance(){return mBalance;}
                AmountType getExpence(){return mExpence;}
                AmountType getInvestment(){return mInvestment;}
                AmountType getTaxsavingInvestment(){return mTaxsavingInvestment;}
                AmountType getRemainingTax(){return mRemainingTax;}
};

FinancialInfo::FinancialInfo(){}
FinancialInfo::~FinancialInfo(){}
#endif

