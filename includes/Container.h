#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include<string>
#include<sstream>

#include"Entry.h"
#include"List.h"
#include"Date.h"

class Container
{
        private:
                        List* mEntries;
                        Date* mDate;
        public:
                        Container();
                        Container(Date*);
                        ~Container();
                        bool addEntry(Entry*);
                        Entry* getEntry(EntryType,int);
			List* getEntryList(EntryType);
                        bool deletEntry(EntryType,int);
			std::string toString();
};
#endif
