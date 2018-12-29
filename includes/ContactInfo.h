#ifndef __CONTACT_INFO_H__
#define __CONTACT_INFO_H__
#include<string>
class ContactInfo
{
        private:
                std::string mAddress;
                std::string mEmail;
                std::string mMobile;
        public:
                ContactInfo();
		ContactInfo(
				const std::string& aAddress,
				const std::string& aEmail,
				const std::string& aMobile);
                ~ContactInfo();

                std::string getAddress() {return mAddress;}
                std::string getEmail() {return mEmail;}
                std::string getMobile() {return mMobile;}

                void setAddress(const std::string& aAddress) { mAddress.assign(aAddress);}
                void setEmail(const std::string& aEmail) {mEmail.assign(aEmail);}
                void setMobile(const std::string& aMobile) {mMobile.assign(aMobile);}

                std::string toString();
};
#endif
