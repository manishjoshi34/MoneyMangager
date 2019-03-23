#ifndef __NAME_H__
#define __NAME_H__

#include<string>
#include<iostream>

#define FIRST "FirstName"
#define LAST "LastName"
#define MIDDLE "MiddleName"

using namespace std;

class NameElement
{
	protected:
		string mFirstName;
		string mMiddleName;
		string mLastName;
	public:
		NameElement();
		NameElement(const string& aFirst,const string& aMiddle,const string& aLast);
		~NameElement();
		string getFullName();
		string getFirstName();
		string getLastName();
		string getMiddleName();
		void SetFirstName(const string&);
		void SetMiddleName(const string&);
		void SetLastName(const string&);
		string toString();
		friend ostream & operator << (ostream&, const NameElement& name);

};


#endif
