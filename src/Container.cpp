#include "Container.h"

#define MAXENTRYTYPE 18

Container::Container():
                mEntries(NULL),
                mDate(NULL)
{
}
Container::Container(Date* aDate):
                mDate(aDate)
{
	mEntries = new List[MAXENTRYTYPE];
}
Container::~Container()
{
        if(mEntries!=NULL)
        {
                delete[] mEntries;
        }
        mEntries = NULL;
        if(mDate !=NULL)
        {
                delete mDate;
        }
        mDate = NULL;
}
List*
Container::getEntryList(EntryType aType)
{
        return &mEntries[aType];
}
bool
Container::addEntry(Entry* aEntry)
{
        return mEntries[aEntry->getEntryType()].addEntry(aEntry);
}
bool
Container::deletEntry(EntryType aType,int aId)
{
        return mEntries[aType].deletEntry(aId);
}
Entry*
Container::getEntry(EntryType aType, int id)
{
        return mEntries[aType].getEntry(id);
}
std::string
Container::toString()
{
        std::string out;
        for(int i=0;i<MAXENTRYTYPE;i++)
                out.append(mEntries[i].toString());
        return out;
}

