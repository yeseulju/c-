#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

#include <iostream>
using namespace std;

namespace sdds
{
    const int sdds_testYear = 2022;
    const int sdds_testMon = 03;
    const int sdds_testDay = 31;
    class Utils
    {
        bool m_testMode = false;

    public:
        int checking_num(istream&, int, int);
        double checking_float(istream&, double, double);
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
        int daysOfMon(int, int) const;
        void testMode(bool testmode = true);
    };
    extern Utils ut;
}

#endif