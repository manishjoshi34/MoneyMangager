#ifndef __DATABASE_H__

#define __DATABASE_H__

#include<string>

#define MAXENTRYTYPE 18 

class Date
{
        private:
                int mDD;
                int mMM;
                int mYY;
        public:
                Date();
                Date(const int&,const int&,const int&);
                ~Date();

                int getDD();
                int getMM();
                int getYY();

                void setDD(const int&);
                void setMM(const int&);
                void setYY(const int&);

                std::string toString();

                friend bool operator < (const Date& obj1, const Date& obj2);
};

class Value
{
        private:
                Date* mDate;
                vector< vector<Entry*> > mEntries(MAXENTRYTYPE);
        public:
                Value();
                ~Value();
                vector<Entry*>* getEntryVector(const EntryType* aType);

};

class Database
{
	private :
		map<Date,Value>* mMap;
	public :
		Database();
		~Database();
		bool AddEntry(const Date&,const Entry&);
		const vector<Entry*>* getEntry(const Date&,const EntryType&);
		bool DeletEntry(const Data&,const int&);

		std::string showEntry(const Date&,const Date&);
}

#endif
