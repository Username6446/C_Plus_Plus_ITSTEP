#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

class Contact {
private:
    char* fullName;
    char* homePhone;
    char* workPhone;
    char* mobilePhone;
    char* additionalInfo;

    char* copyString(const char* source) {
        if (!source) {
            return nullptr;
        }
        char* res = new char[strlen(source) + 1];
        strcpy(res, source);
        return res;
    }

public:
    Contact() : fullName(nullptr), homePhone(nullptr), workPhone(nullptr),
        mobilePhone(nullptr), additionalInfo(nullptr) {
    }

    Contact(const char* name, const char* home = "", const char* work = "",
        const char* mobile = "", const char* info = "") {
        fullName = copyString(name);
        homePhone = copyString(home);
        workPhone = copyString(work);
        mobilePhone = copyString(mobile);
        additionalInfo = copyString(info);
    }

    Contact(const Contact& other) {
        fullName = copyString(other.fullName);
        homePhone = copyString(other.homePhone);
        workPhone = copyString(other.workPhone);
        mobilePhone = copyString(other.mobilePhone);
        additionalInfo = copyString(other.additionalInfo);
    }

    Contact& operator=(const Contact& other) {
        if (this != &other) {
            delete[] fullName;
            delete[] homePhone;
            delete[] workPhone;
            delete[] mobilePhone;
            delete[] additionalInfo;

            fullName = copyString(other.fullName);
            homePhone = copyString(other.homePhone);
            workPhone = copyString(other.workPhone);
            mobilePhone = copyString(other.mobilePhone);
            additionalInfo = copyString(other.additionalInfo);
        }
        return *this;
    }

    ~Contact() {
        delete[] fullName;
        delete[] homePhone;
        delete[] workPhone;
        delete[] mobilePhone;
        delete[] additionalInfo;
    }

    inline const char* getFullName() const
    {
        if (fullName) {
            return fullName;
        }
        else {
            return "";
        }
    }

    inline const char* getHomePhone() const
    {
        if (homePhone) {
            return homePhone;
        }
        else {
            return "";
        }
    }

    inline const char* getWorkPhone() const
    {
        if (workPhone) {
            return workPhone;
        }
        else {
            return "";
        }
    }

    inline const char* getMobilePhone() const
    {
        if (mobilePhone) {
            return mobilePhone;
        }
        else {
            return "";
        }
    }

    inline const char* getAdditionalInfo() const
    {
        if (additionalInfo) {
            return additionalInfo;
        }
        else {
            return "";
        }
    }

    inline void setFullName(const char* name) {
        delete[] fullName;
        fullName = copyString(name);
    }

    inline void setHomePhone(const char* phone) {
        delete[] homePhone;
        homePhone = copyString(phone);
    }

    inline void setWorkPhone(const char* phone) {
        delete[] workPhone;
        workPhone = copyString(phone);
    }

    inline void setMobilePhone(const char* phone) {
        delete[] mobilePhone;
        mobilePhone = copyString(phone);
    }

    inline void setAdditionalInfo(const char* info) {
        delete[] additionalInfo;
        additionalInfo = copyString(info);
    }

    void display() const {
        cout << "Full Name: " << (fullName ? fullName : "") << endl;
        cout << "Home Phone: " << (homePhone ? homePhone : "") << endl;
        cout << "Work Phone: " << (workPhone ? workPhone : "") << endl;
        cout << "Mobile Phone: " << (mobilePhone ? mobilePhone : "") << endl;
        cout << "Additional Info: " << (additionalInfo ? additionalInfo : "") << endl;
        cout << "----------------------------------------" << endl;
    }
    void saveToFile(ofstream& file) const {
        file << "Full Name: " << fullName << endl;
        file << "Home Phone: " << homePhone << endl;
        file << "Work Phone: " << workPhone << endl;
        file << "Mobile Phone: " << mobilePhone << endl;
        file << "Additional Info: " << additionalInfo << endl;
    }
    void loadFromFile(ifstream& file) {
        string temp;

        getline(file, temp);
        setFullName(temp.c_str());

        getline(file, temp);
        setHomePhone(temp.c_str());

        getline(file, temp);
        setWorkPhone(temp.c_str());

        getline(file, temp);
        setMobilePhone(temp.c_str());

        getline(file, temp);
        setAdditionalInfo(temp.c_str());
    }

    bool compareName(const char* name) const {
        if (!fullName || !name) {
            return false;
        }
        return strcmp(fullName, name) == 0;
    }
};