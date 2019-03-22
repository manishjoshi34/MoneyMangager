#ifndef __ENTRY_H__

#define __ENTRY_H__

typedef long double AmountType;

#include<string>
#include<sstream>


enum EntryType
{
        HealthCare = 0,
        Shopping,
        Bills,
        Electronics,
        EMI,
        Entertainment,
        FoodDrinks,
        Fuel,
        Groceries,
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
		static int IDS;
	private:
		int mId;
		AmountType mAmount;
		EntryType mType;

	public:
		Entry();
		~Entry();
		Entry(AmountType, EntryType);

		AmountType getAmount();
		EntryType getEntryType();
		int getId();

		void SetEntryType(const EntryType& aType);
		void SetAmount(const AmountType&);

		std::string toString();

};
#endif
