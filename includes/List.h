#ifndef __LIST_H__
#define __LIST_H__

#include<string>
#include<sstream>
#include<vector>

#include "Entry.h"

class List
{
        private:
                std::vector<Entry*> mList;
        public:
                List();
                ~List();
                bool addEntry(Entry* obj);
                Entry* getEntry(int aId);
                bool deletEntry(int aId);
		std::string toString();
                int getSize();
};

#endif
