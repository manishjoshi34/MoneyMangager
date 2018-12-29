
#include "LoginDetail.h"
#include "log.h"

LoginDetail::LoginDetail()
{
	mPancardNumber.assign("");
	mPassword.assign("");
}
LoginDetail::~LoginDetail()
{
}
bool LoginDetail::SetLoginDetail(const std::string& aPancard,const std::string& aPassword)
{
	mPassword.assign(aPassword);
	mPancardNumber.assign(aPancard);
	LOG("LoginDetail","SetLoginDetail","UserName: "+mPancardNumber);
	return true;
}
bool LoginDetail::UpdatePassword(const std::string& aPassword)
{
	mPassword.assign(aPassword);
	LOG("LoginDetail","UpdatePassword","PasswordUpdated");
	return true;
}
bool LoginDetail::CheckPassword(const std::string& aPassword)
{
	 if(mPassword.compare(aPassword)==0) return true;
	 LOG("LoginDetail","CheckPassword");
	 return false;
}
