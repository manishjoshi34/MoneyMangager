#include "Database.h"
#include "Entry.h"
#include "Container.h"
#include "log.h"
#include<sstream>


using namespace std;

Database::Database()
{
	LOG("Database created\n");
}
Database::~Database()
{
	LOG("Database deleted\n");
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
bool Database::addEntry(Date* aDate,Entry* aEntry)
{
	auto itr = mDateToEntryContainerMap.find(*aDate);

	if(itr != mDateToEntryContainerMap.end())
	{
		itr->second->addEntry(aEntry);
		
	}
	else
	{	
		
		Container* container = new Container(aDate);	
		container->addEntry(aEntry);
		mDateToEntryContainerMap.insert(
				std::pair<Date,Container*>(*aDate,container));
		mIdToEntryMap.insert(
				std::pair<int,Entry*>(aEntry->getId(),aEntry));

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
void Database::showEntry(
		Date& fromDate,
		Date& toDate,
		std::vector<Container*> aEntryList)
{
	
	if(fromDate.compare(toDate))
	{
		auto itr = mDateToEntryContainerMap.find(toDate);
                if(itr != mDateToEntryContainerMap.end())
                	aEntryList.push_back(itr->second);

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
			aEntryList.push_back(itrFrom->second);
			itrFrom++;
		}
	}

}

//Database* _database = 0;

Database*
Database::getDatabase() {
	static Database* database = new Database();
	return database;
}

void 
Database::clearDatabase()
{
	Database* database = Database::getDatabase();
	delete database;
	database = 0;
}

void
Database::saveDatabase()
{}

