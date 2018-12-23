#ifndef __ENTRY_H__
#define __ENTRY_H__

typedef long double AmountType;

class Entry
{
	private:
		AmountType mAmount;

	public:
		virtual AmountType GetAmount();
		virtual void SetAmount(AmountType);
		Entry();
		Entry(AmountType); 
		virtual ~Entry();

};
AmountType Entry::GetAmount()
{
	return mAmount;
}
void Entry::SetAmount(AmountType obj)
{
	mAmount = obj;
}
Entry::Entry()
{
	mAmount = 0.0;
}
Entry::Entry(AmountType aAmount):
	mAmount(aAmount)
{
}
Entry::~Entry()
{
}
//.............CreditEntry.................
class CreditEntry : public Entry
{	
	public:
		CreditEntry();
		CreditEntry(AmountType);
		virtual ~CreditEntry();
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
