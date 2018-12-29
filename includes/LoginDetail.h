#ifndef __LOGIN_DETAIL_H__
#define __LOGIN_DETAIL_H__

#include<string>

class LoginDetail
{
	private:
		std::string mPancardNumber;
		std::string  mPassword;
	public:
		LoginDetail();
		~LoginDetail();

		bool SetLoginDetail(const std::string& aPancardNumber,const std::string& aPassword);
		bool  UpdatePassword(const std::string& aPassword);
		bool  CheckPassword(const std::string&);

		std::string GetPancardNumber(){return mPancardNumber}
		

};
#endif
