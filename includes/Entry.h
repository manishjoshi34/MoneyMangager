#ifndef __ENTRY_H__

#define __ENTRY_H__

typedef long double AmountType;

enum EntryType
{
        HealthCare = 0,
        Shopping,
        Biils,
        cable,
        Electronics,
        EMI,
        Entertainment,
        FoodDrinks,
        Fuel,
        Groceries,
        Health,
        Rent,
        Transfer,
        Travel,
	Salary,
	Gift,
	Loan,
        Other
};


class Entry
{
	private:
		AmountType mAmount;
		EntryType mType;

	public:
		Entry();
		~Entry();
		Entry(const AmountType&, const EntryType&);

		AmountType getAmount();
		EntryType getEntryType();

		void SetEntryType(const EntryType& aType);
		void SetAmount(const AmountType&);

};
AmountType Entry::getAmount()
{
	return mAmount;
}
void Entry::SetAmount(AmountType& obj)
{
	mAmount = obj;
}
void Entry::SetEntryType(EntryType& aType)
{
	mType = aType;
}
EntryType Entry::getEntryType()
{
	return mType;
}
Entry::Entry()
{
	mAmount = 0.0;
}
Entry::Entry(
	const AmountType& aAmount,
       	const EntryType& aType):
	mAmount(aAmount),
	mType(aType)
{
}
Entry::~Entry()
{
}
//.............CreditEntry.................
//
#if 0
class CreditEntry : public Entry
{	
	private:
		CreditType mType;
	public:
		CreditEntry();
		CreditEntry(AmountType);
		virtual ~CreditEntry();
		void SetEntryType()

};
CreditEntry::CreditEntry():
	Entry()
{
}
CreditEntry::CreditEntry(AmountType aAmount):
	Entry(aAmount)
{
}
CreditEntry::~CreditEntry()
{

}

//..............DebitEntry..................

class DebitEntry : public Entry
{	
	private:
		ExpenceType mType;
	public:
		DebitEntry();
		DebitEntry(AmountType);
		virtual ~DebitEntry();

};

DebitEntry::DebitEntry():
	Entry()
{
}
DebitEntry::DebitEntry(AmountType aAmount):
	Entry(aAmount)
{
}
DebitEntry::~DebitEntry()
{
}
#endif
#endif
