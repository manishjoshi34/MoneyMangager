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
	private:
		string mFirstName;
		string mMiddleName;
		string mLastName;
	public:
		NameElement();
		NameElement(const string& aFirst,const string& aMiddle,const string& aLast);
		~NameElement();
		const string getFullName();
		const string getFirstName();
		const string getLastName();
		const string getMiddleName();
		void SetFirstName(const string&);
		void SetMiddleName(const string&);
		void SetLastName(const string&);
		const string toString();
		friend ostream & operator << (ostream&, const NameElement& name);

};

NameElement::NameElement()
{
	mFirstName.assign(FIRST);
	mLastName.assign(LAST);
	mMiddleName.assign(MIDDLE);
}
NameElement::NameElement(const string& aFirst,const string& aMiddle, const string& aLast)
{
	mFirstName.assign(aFirst);
	mMiddleName.assign(aMiddle);
	mLastName.assign(aLast);
}
NameElement::~NameElement()
{

}
const string NameElement::getFirstName()
{
	return mFirstName;
}
const string NameElement::getMiddleName()
{
	return mMiddleName;
}
const string NameElement::getLastName()
{
	return mLastName;
}
const string NameElement::getFullName()
{	
	string full(mFirstName);
	full = full + " " + mMiddleName + " " +mLastName;
	return full;
		
}
void NameElement::SetFirstName(const string& aFirst)
{
	mFirstName.assign(aFirst);
}
void NameElement::SetMiddleName(const string& aMiddle)
{
	mMiddleName.assign(aMiddle);
}
void NameElement::SetLastName(const string& aLast)
{
	mLastName.assign(aLast);
}
const string NameElement::toString()
{
	return (mFirstName + " " + mMiddleName + " " + mLastName); 
}
ostream & operator << (ostream& out,const NameElement& name)
{
	string Name;
	Name ="FirstName:  "+name.mFirstName+"\n"+
	      "MiddleName: "+name.mMiddleName+"\n"+
	      "LastName:   "+name.mLastName+"\n";
	out << Name;
		     
}

#endif
