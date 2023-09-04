#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "iProduct.h"
#include <string>
#include <iostream>

using namespace std;

namespace sdds
{

    istream& operator>>(istream& in_param, iProduct& p_var)
    {
        return p_var.read(in_param);
    }

    ostream& operator<<(ostream& os_param, const iProduct& p_var)
    {
        return p_var.display(os_param);
    }
    iProduct::~iProduct()
    {
    }

    int iProduct::readSku(istream& istr_param)
    {
        return 0;
    }

    int iProduct::qtyNeeded() const
    {
        return 0;
    }

    int iProduct::qty() const
    {
        return 0;
    }

    void iProduct::linear(bool isLinear_param)
    {
        return;
    }
    bool iProduct::operator==(const char* description_var) const
    {
        return true;
    }

    int iProduct::operator-=(int qty_param)
    {
        return 0;
    }

    ofstream& iProduct::save(ofstream& ofstr_param) const
    {
        return ofstr_param;
    }

    ifstream& iProduct::load(ifstream& ifstr_param)
    {
        return ifstr_param;
    }

    ostream& iProduct::display(ostream& ostr_param) const
    {
        return ostr_param;
    }

    istream& iProduct::read(istream& istr_param)
    {
        return istr_param;
    }

    bool iProduct::operator==(int sku) const
    {
        return true;
    }

    int iProduct::operator+=(int qty_param)
    {
        return 0;
    }

    iProduct::operator double() const
    {
        return 0;
    }

    iProduct::operator bool() const
    {
        return 0;
    }
}