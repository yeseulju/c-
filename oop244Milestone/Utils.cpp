#define _CRT_SECURE_NO_WARNINGS

#include "Utils.h"
#include <iostream>
#include <ctime>

#include <string>
using namespace std;

namespace sdds
{
    Utils ut;
    double Utils::checking_float(std::istream& istr, double x, double y)
    {

        string choice_param;
        int flag_param = 0;
        double num;
        int dec = 0;
        while (1)
        {
            flag_param = 0;
            cin >> choice_param;
            for (char c : choice_param)
            {
                if (isdigit(c))
                {
                    continue;
                }
                else if (c == '.' && dec == 0)
                {
                    dec++;
                    continue;
                }
                else
                {
                    flag_param = 1;
                    break;
                }
            }
            if (flag_param == 1)
            {
                cout << "Invalid number, retry: ";
            }
            else
            {
                num = stod(choice_param);
                if (num >= x && num <= y)
                {
                    return num;
                }
                else
                {
                    cout.setf(ios::fixed);
                    cout.precision(2);
                    cout << "Value out of range [";
                    cout << x << "<=val<=";
                    cout << y << "]: ";
                }
            }
        }
        return -1;
    }
    void Utils::testMode(bool testmode_param)
    {
        m_testMode = testmode_param;
    }

    void Utils::getSystemDate(int* year_param, int* mon_param, int* day_param)
    {
        if (m_testMode)
        {
            if (day_param)
                *day_param = sdds_testDay;
            if (mon_param)
                *mon_param = sdds_testMon;
            if (year_param)
                *year_param = sdds_testYear;
        }
        else
        {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day_param)
                *day_param = lt.tm_mday;
            if (mon_param)
                *mon_param = lt.tm_mon + 1;
            if (year_param)
                *year_param = lt.tm_year + 1900;
        }
    }

    int Utils::checking_num(std::istream& istr, int x, int y)
    {
        string choice_param;
        int flag_param = 0;
        int num;

        while (1)
        {
            flag_param = 0;
            cin >> choice_param;
            for (char c : choice_param)
            {
                if (isdigit(c))
                {
                    continue;
                }
                flag_param = 1;
                break;
            }
            if (flag_param == 1)
            {
                cout << "Invalid Integer, retry: ";
            }
            else
            {
                num = stoi(choice_param);
                if (num >= x && num <= y)
                {
                    return num;
                }
                else
                {
                    cout << "Value out of range [";
                    cout << x << "<=val<=";
                    cout << y << "]: ";
                }
            }
        }
        return -1;
    }
    int Utils::daysOfMon(int month_param, int year_param) const
    {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month_param >= 1 && month_param <= 12 ? month_param : 13) - 1;
        return days[mon] + ((mon == 1) && (((year_param % 4 == 0) && (year_param % 100 != 0)) || (year_param % 400 == 0)));
    }
}