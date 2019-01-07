#include "List.h"

List::List()
{
}
List::~List()
{
        if(mList.size())
        {
                int size = mList.size();
                for(int i=0;i<size;i++)
                {
                        Entry* temp = mList[i];
                        delete temp;
                        mList.erase(mList.begin()+i);
                        temp=NULL;
                }

        }
}
bool
List::addEntry(Entry* obj)
{
        if(obj)
        {
                mList.push_back(obj);
                return true;
        }
        return false;
}
Entry*
List::getEntry(int aId)
{
        int size = mList.size();
        for(int i=0;i<size;i++)
        {
                if(mList[i]->getId() == aId) return mList[i];
        }
        return NULL;
}
bool
List::deletEntry(int aId)
{
        int size = mList.size();
        for(int i=0;i<size;i++)
        {
                if(mList[i]->getId() == aId)
                {
                        Entry* temp = (Entry*)mList[i];
                        delete temp;
                        mList.erase(mList.begin()+i);
                        temp=NULL;
                        return true;
                }
        }
        return false;
}
std::string
List::toString()
{
        std::ostringstream out;
	
        //out<< "ID" <<"\t" <<"ENTRY TYPE" << "\t" << "AMOUNT" <<"\n";
        int size = mList.size();
        for(int i = 0;i< size ;i++)
        {
                out << mList[i]->toString();
        }
        return out.str();
}

