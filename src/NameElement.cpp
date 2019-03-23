#include "NameElement.h"

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
string NameElement::getFirstName()
{
        return mFirstName;
}
string NameElement::getMiddleName()
{
        return mMiddleName;
}
string NameElement::getLastName()
{
        return mLastName;
}
string NameElement::getFullName()
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
string NameElement::toString()
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

