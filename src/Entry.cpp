#include "Entry.h"


std::string ENTRYTYPES[] = {
        "HEALTH CARE",
        "SHOPPING",
        "BILLS",
        "CABLE",
        "ELECTRONICS",
        "EMI",
        "ENTERTAINMENT",
        "FOOD AND DRINKS",
        "FUEL",
        "GROCERIES",
        "RENT",
        "TRANSFER",
        "TRAVEL",
        "SALARY",
        "GIFT",
        "LOAN",
        "OTHER"
};

int Entry::IDS = 1;

int Entry::getId()
{
        return mId;
}

AmountType Entry::getAmount()
{
        return mAmount;
}
void Entry::SetAmount(const AmountType& obj)
{
        mAmount = obj;
}
void Entry::SetEntryType(const EntryType& aType)
{
        mType = aType;
}
EntryType Entry::getEntryType()
{
        return mType;
}
Entry::Entry()
{
        mId = IDS++;
        mAmount = 0.0;
}
Entry::Entry(
        AmountType aAmount,
        EntryType aType):
        mAmount(aAmount),
        mType(aType)
{
        mId = IDS++;
}
Entry::~Entry()
{
}
std::string Entry::toString()
{
	std::ostringstream out;

	out << mId <<"  " << ENTRYTYPES[mType] << " " << mAmount << std::endl;

	return out.str();
}
