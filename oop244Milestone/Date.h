#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__

#include "Status.h"
#include <iostream>
using namespace std;

namespace sdds
{
    const int MAX_YEAR = 2030;

    class Date
    {
    private:
        Status status;
        bool format;
        bool validate();
        int month;
        int year;
        int day;

    public:
        const Status& state();
        int uniqueValue() const;
        istream& read(istream&);
        ostream& write(ostream&) const;
        bool formatted(bool);
        operator bool() const;
        Date();
        Date(int, int, int);
    };

    istream& operator>>(istream&, Date&);
    ostream& operator<<(ostream&, const Date&);
    bool operator==(const Date&, const Date&);

    bool operator<(const Date&, const Date&);
    bool operator>(const Date&, const Date&);
    bool operator!=(const Date&, const Date&);
    bool operator>=(const Date&, const Date&);
    bool operator<=(const Date&, const Date&);
}

#endif