#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H

#include <iostream>
#include <cstring>

using namespace std;

namespace sdds
{
    class Status
    {
    public:
        Status& operator=(const int);
        operator bool() const;
        operator int() const;
        operator char* () const;
        friend ostream& operator<<(ostream&, const Status&);
        char* status_des;
        int status_code;

        ~Status();
        Status& operator=(const char*);

        Status& clear();
        Status(char* str = nullptr, int code = 0);
        Status(const Status&);
        Status& operator=(const Status&);
    };
}

#endif