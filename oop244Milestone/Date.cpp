#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include "Utils.h"
#include "Status.h"
#include <iomanip>
#include <iostream>
#include <ctime>

#include <string>
using namespace std;

namespace sdds
{

    bool operator==(const Date& one_var, const Date& two_var)
    {
        return one_var.uniqueValue() == two_var.uniqueValue();
    }

    bool operator!=(const Date& one_var, const Date& two_var)
    {
        return one_var.uniqueValue() != two_var.uniqueValue();
    }

    bool operator>=(const Date& one_var, const Date& two_var)
    {
        return one_var.uniqueValue() >= two_var.uniqueValue();
    }

    bool operator<=(const Date& one_var, const Date& two_var)
    {
        return one_var.uniqueValue() <= two_var.uniqueValue();
    }

    bool operator<(const Date& one_var, const Date& two_var)
    {
        return one_var.uniqueValue() < two_var.uniqueValue();
    }

    bool operator>(const Date& one_var, const Date& two_var)
    {
        return one_var.uniqueValue() > two_var.uniqueValue();
    }
    std::ostream& operator<<(std::ostream& ostr_var, const Date& D)
    {
        D.write(ostr_var);
        return ostr_var;
    }
    bool Date::validate()
    {
        Utils a;
        Status b;

        if (month < 1 || month > 12)
        {

            status.status_des = new char[22];
            strcpy(status.status_des, "Invalid month in date");
            status.status_code = 2;

            return false;
        }
        else if (year < sdds_testYear || year > MAX_YEAR)
        {
            status.status_des = new char[21];
            strcpy(status.status_des, "Invalid year in date");
            status.status_code = 1;

            return false;
        }
        else if (day < 1 || day > a.daysOfMon(month, year))
        {

            status.status_des = new char[20];
            strcpy(status.status_des, "Invalid day in date");
            status.status_code = 3;

            return false;
        }
        else
        {
            b.clear();
            return true;
        }
    }

    int Date::uniqueValue() const
    {
        return (year - 2000) * 10000 + month * 100 + day;
    }

    const Status& Date::state()
    {
        return status;
    }

    bool Date::formatted(bool m_format_param)
    {
        format = m_format_param;

        return *this;
    }





    Date::Date(int m_year_param, int m_month_param, int m_day_param)
    {
        year = m_year_param;
        month = m_month_param;
        day = m_day_param;
        formatted(true);
        validate();
    }




    std::istream& operator>>(std::istream& istr_var, Date& D)
    {
        D.read(istr_var);
        return istr_var;
    }

    std::ostream& sdds::Date::write(std::ostream& ostr_var) const
    {
        if (format == true)
        {
            ostr_var << year << '/';
            ostr_var << setw(2) << setfill('0') << month << '/';
            ostr_var << setw(2) << setfill('0') << day;
        }
        else
        {
            ostr_var << year % 100 << setw(2) << setfill('0') << month << setw(2) << setfill('0') << day;
        }

        return ostr_var;
    }

    std::istream& Date::read(std::istream& istr)
    {
        int value = 0;
        string input;

        istr >> value;
        if (istr.fail())
        {
            cout << "Invalid date value";
            cin.setstate(ios::badbit);
            return istr;
        }

        if (to_string(value).length() == 4 || to_string(value).length() == 3)
        {
            year = sdds_testYear;
            day = value % 100;
            month = value / 100;
        }
        else if (to_string(value).length() == 6 || to_string(value).length() == 5)
        {
            day = value % 100;
            value = value / 100;
            month = value % 100;
            year = value / 100 + 2000;
        }
        else
        {
            month = 0;
            day = 0;
            year = 0;
        }
        if (validate() == false)
        {
            cin.setstate(ios::badbit);
        }
        return istr;
    }


    Date::operator bool() const
    {
        return 0;
    }

    Date::Date()
    {

        year = sdds_testYear;
        month = sdds_testMon;
        day = sdds_testDay;

        formatted(true);
    }
}