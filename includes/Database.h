#ifndef __DATABASE_H__

#define __DATABASE_H__

#include<string>
#include<vector>
#include<map>

#include "Date.h"
#include "Container.h"
#include "Entry.h"

using namespace std;


class Database
{
	private :

		map<Date,Container*> mDateToEntryContainerMap;

		map<int,Entry*> mIdToEntryMap;

	public :

		Database();

		~Database();

		bool addEntry(Date* ,Entry*);

		const Entry* getEntry(int&,EntryType);

		List* getEntryList(Date&,EntryType);

		bool DeletEntry(Date&,int&,EntryType);

		void showEntry(Date&,Date&,vector<Container*>);

		
};


#endif
