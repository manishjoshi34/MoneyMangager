#include "Database.h"
#include "Entry.h"
#include "Container.h"
#include<sstream>


using namespace std;

Database::Database()
{
}
Database::~Database()
{
}
const Entry* Database::getEntry(int& aId,EntryType aType)
{
	auto itr = mIdToEntryMap.find(aId);

	if(itr!=mIdToEntryMap.end())
	{
		return itr->second;
	}

	return NULL;
}	
bool Database::addEntry(Date& aDate,Entry& aEntry)
{
	auto itr = mDateToEntryContainerMap.find(aDate);

	if(itr != mDateToEntryContainerMap.end())
	{
		itr->second->addEntry(&aEntry);
		
	}
	else
	{	
		
		Container* container = new Container(&aDate);	
		container->addEntry(&aEntry);
		mDateToEntryContainerMap.insert(
				std::pair<Date,Container*>(aDate,container));
		mIdToEntryMap.insert(
				std::pair<int,Entry*>(aEntry.getId(),&aEntry));

	}

	return true;
}
List* Database::getEntryList(Date& aDate,EntryType aType)
{
	List* temp = NULL;
	auto itr = mDateToEntryContainerMap.find(aDate);
	if(itr != (mDateToEntryContainerMap.end()))
	{
		temp = itr->second->getEntryList(aType);
	}
	return temp;
}
bool Database::DeletEntry(Date& aDate,int& aId,EntryType aType)
{
	auto itr = mDateToEntryContainerMap.find(aDate);
	bool status  = false;
	if(itr != mDateToEntryContainerMap.end())
	{
		status = itr->second->deletEntry(aType,aId);
		status = mIdToEntryMap.erase(aId);
	}

	return status;
}
std::string Database::showEntry(Date& fromDate,Date& toDate)
{
	stringstream out;
	
	if(fromDate.compare(toDate))
	{
		auto itr = mDateToEntryContainerMap.find(toDate);
                if(itr != mDateToEntryContainerMap.end())
                	out << itr->second->toString();

	}
	else if(fromDate < toDate)
	{
		auto itrFrom = mDateToEntryContainerMap.lower_bound(fromDate);
		Date temp = Date::nextDate(toDate);
		while(
			!itrFrom->first.compare(temp) && 
			itrFrom!=mDateToEntryContainerMap.end()
		     )
		{
			out << itrFrom->second->toString();
			itrFrom++;
		}
	}

	return out.str();
}

