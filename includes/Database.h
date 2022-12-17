#ifndef __DATABASE_H__

#define __DATABASE_H__

#include "stdHeader.h"
#include "Date.h"
#include "Container.h"
#include "Entry.h"

using namespace std;


class Database
{
	private :

		map<Date,Container*> mDateToEntryContainerMap;

		map<int,Entry*> mIdToEntryMap;

	private:
		Database();

		~Database();

	public :

		bool addEntry(Date* ,Entry*);

		const Entry* getEntry(int&,EntryType);

		List* getEntryList(Date&,EntryType);

		bool DeletEntry(Date&,int&,EntryType);

		void showEntry(Date&,Date&,vector<Container*>);

	public:
		static Database* getDatabase();

		static void saveDatabase();

		static void clearDatabase();
		
};


#endif
