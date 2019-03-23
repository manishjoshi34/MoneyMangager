#include "FinancialInfo.h"
#include "log.h"

typedef long double AmountType;


FinancialInfo::FinancialInfo(){}

FinancialInfo::~FinancialInfo(){}

bool FinancialInfo::update(
		AmountType& aAmount,
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


