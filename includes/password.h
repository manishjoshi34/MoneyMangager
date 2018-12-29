#ifndef __PASSWORD_H__
#define __PASSWORD_H__

#include<string>

class Password
{
	private:
		std::string mPassword;
	public:
		Password();
		Password(std::string& aPassword);
		~Password();
		bool setPassword(std::string& aPassword); 
		bool checkPassword(std::string& aPassword);
};
inline Password::Password()
{
	mPassword.assign("");
}
inline Password::Password(std::string& aPassword)
{
	mPassword.assign(aPassword);
}
inline bool Password::setPassword(std::string& aPassword)
{
	mPassword.assign(aPassword);
	return true;
}
inline bool Password::checkPassword(std::string& aPassword)
{
	if(mPassword.compare(aPassword)==0)return true;
	
	return false;
}
~Password::Password()
{
}

