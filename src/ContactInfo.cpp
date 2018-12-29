#include "ContactInfo.h"
#include "log.h"

#include<string>

ContactInfo::ContactInfo()
{
	mAddress.assign("");
	mEmail.assign("");
	mMobile.assign("");
}

ContactInfo::ContactInfo(
		const std::string& aAddress,
		const std::string& aEmail,
		const std::string& aMobile)
{
	mAddress.assign(aAddress);
        mEmail.assign(aEmail);
        mMobile.assign(aMobile);
}
ContactInfo::~ContactInfo()
{
}
std::string ContactInfo::toString()
{
	std::string info;
	info.assign("Address: "+mAddress+"\t EmailId: "+mEmail+"\t Mobile: "+mMobile);
	LOG(info);
	return info;
}

