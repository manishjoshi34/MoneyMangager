#ifndef __DATE_H__
#define __DATE_H__

#include<string>
#include<sstream>

class Date
{
        private:
                int mDD;
                int mMM;
                int mYY;

                //static int MAXDAYS[13];
        public:
                Date();
                Date(const int&,const int&,const int&);
                ~Date();

                static bool CheckLeapYear(int yy);
                static Date nextDate(const Date&);

                int getDate() const ;
                int getMonth() const ;
                int getYear() const ;

                void setDate(const int&);
                void setMonth(const int&);
                void setYear(const int&);

                const std::string toString();

                bool compare(const Date&) const;

                bool operator < (const Date&) const;
};

#endif
