#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "Perishable.h"
#include "Item.h"
#include "Utils.h"
#include <iomanip>
#include <iostream>

using namespace std;
namespace sdds
{
    ostream& Perishable::display(ostream& ostr_param) const
    {
        if (m_linear)
        {
            ostr_param << setfill(' ');
            Item::display(ostr_param);
            if (headline != nullptr && strlen(headline) != 0)
            {
                ostr_param << "*";
            }
            else
            {
                ostr_param << " ";
            }
            ostr_param << m_expiry;
        }
        else
        {
            ostr_param << setfill(' ');
            ostr_param << "Perishable ";
            Item::display(ostr_param);
            ostr_param << "Expiry date: " << m_expiry << endl;
            if (headline != nullptr && strlen(headline) != 0)
            {
                ostr_param << "Handling Instructions: " << headline << endl;
            }
        }
        return ostr_param;
    }
    Perishable::~Perishable()
    {
        delete[] headline;
        headline = nullptr;
        m_expiry.formatted(false);
    }

    const Date& Perishable::expiry() const
    {
        return m_expiry;
    }

    int Perishable::readSku(istream& istr_param)
    {
        Utils a;
        cout << "SKU: ";
        m_sku = a.checking_num(istr_param, 10000, 39999);
        return -1;
    }
    Perishable::Perishable() : Item::Item()
    {
        headline = nullptr;
        m_expiry.formatted(true);
    }

    Perishable::Perishable(const Perishable& perishable_param)
    {

        Item::operator=(perishable_param);

        m_expiry = perishable_param.m_expiry;

        if (perishable_param)
        {
            headline = new char[strlen(perishable_param.headline) + 1];
            strcpy(headline, perishable_param.headline);
        }
        else
        {
            headline = nullptr;
        }
    }

    Perishable& Perishable::operator=(const Perishable& perishable_param)
    {
        delete[] headline;
        headline = nullptr;
        m_expiry = perishable_param.m_expiry;

        if (perishable_param)
        {
            Item::operator=(perishable_param);
            headline = new char[strlen(perishable_param.headline) + 1];
            strcpy(headline, perishable_param.headline);
        }
        else
        {
            headline = nullptr;
        }
        return *this;
    }



    ofstream& Perishable::save(ofstream& ofstr_param) const
    {

        if (m_state)
        {
            Item::save(ofstr_param);
            ofstr_param << "\t";
            if (headline != nullptr)
            {
                ofstr_param << headline << "\t";
            }
            ofstr_param << m_expiry.uniqueValue();
        }
        return ofstr_param;
    }

    ifstream& Perishable::load(ifstream& ifstr_param)
    {

        Item::load(ifstr_param);

        delete[] headline;
        headline = nullptr;

        if (ifstr_param)
        {
            ifstr_param.ignore(1000, '\t');
            headline = new char[1000];
            ifstr_param.getline(headline, 1000, '\t');
            ifstr_param >> m_expiry;
            //ifstr_param.ignore(1000, '\n');
        }

        return ifstr_param;
    }



    istream& Perishable::read(istream& istr_param)
    {
        Item::read(istr_param);

        delete[] headline;
        headline = nullptr;
        headline = new char[1000];

        cout << "Expiry date (YYMMDD): ";
        istr_param >> m_expiry;
        istr_param.ignore(1000, '\n');

        cout << "Handling Instructions, ENTER to skip: ";
        istr_param.getline(headline, 1000);

        if (headline[0] == '\n')
        {
            headline = nullptr;
        }

        m_state = true;

        return istr_param;
    }
}