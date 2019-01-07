#include "Date.h"

int MAXDAYS[] = {29,31,28,31,30,31,30,31,31,30,31,30,31};

Date::Date()
{
        mDD=0;
        mMM=0;
        mYY=0;
}
Date::Date(const int& aDD,const int& aMM,const int& aYY):
        mDD(aDD),
        mMM(aMM),
        mYY(aYY)
{
}

bool Date::compare(const Date& aDate)const
{
        if(     mDD!=aDate.getDate() ||
                mMM!=aDate.getMonth() ||
                mYY!=aDate.getYear() )
        {return false;
        }
        return true;
}
Date::~Date()
{
}
inline int Date::getDate()const
{
        return mDD;
}
inline int Date::getMonth()const
{       return mMM;
}
inline int Date::getYear()const
{       return mYY;
}
inline void Date::setDate(const int& aDD)
{       mDD = aDD;
}
inline void Date::setMonth(const int& aMM)
{       mMM = aMM;
}
inline void Date::setYear(const int& aYY)
{       mYY = aYY;
}
const std::string Date::toString()
{
        std::stringstream os;
        os << mDD <<"/" << mMM <<"/" << mYY;
        return os.str();
}
bool Date::operator < (const Date& obj2) const
{
        if(this->getYear()==obj2.getYear())
                {
                        if(this->getMonth()==obj2.getMonth())
                        {
                                return (this->getDate() < obj2.getDate());
                        }
                        return (this->getMonth() < obj2.getMonth());
                }
                return (this->getYear() < obj2.getYear());
}
bool Date::CheckLeapYear(int yy)
{
        if(yy % 4 == 0)
        {
                if(yy % 100 == 0)
                {
                        if(yy % 400 ==0)
                                return true;
                        return false;
                }

                return true;

        }
        return false;
}
Date Date::nextDate(const Date& aDate)
{
        Date temp = aDate;
        int dd = temp.getDate();
        int mm = temp.getMonth();
        int yy = temp.getYear();

        if(mm == 2 && Date::CheckLeapYear(yy) && dd >= MAXDAYS[0])
        {
                dd = 1;
                mm++;

                temp.setDate(dd);
                temp.setMonth(mm);

        }
        else if(mm<12 && dd>=MAXDAYS[mm])
        {
                dd =1;
                mm++;

                temp.setDate(dd);
                temp.setMonth(mm);
        }
	else if(mm==12 && dd>=MAXDAYS[mm])
        {
                dd = 1;
                mm = 1;
                yy++;

                temp.setDate(dd);
                temp.setMonth(mm);
                temp.setYear(yy);
        }
        else{
                dd++;
                temp.setDate(dd);
        }
        return temp;
}

