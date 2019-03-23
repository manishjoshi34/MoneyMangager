#ifndef __FINANCIAL_INFO_H__
#define __FINANCIAL_INFO_H__

class Entry;

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

#endif

