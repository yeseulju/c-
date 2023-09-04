#ifndef SDDS_iPRODUCT_H
#define SDDS_iPRODUCT_H

#include <fstream>
#include <iostream>
using namespace std;

namespace sdds
{
    class iProduct
    {
    public:
        virtual int qty() const;
        virtual void linear(bool);
        virtual ofstream& save(ofstream&) const;
        virtual ifstream& load(ifstream&);
        virtual ~iProduct();
        virtual int readSku(std::istream&);
        virtual int operator-=(int);
        virtual int operator+=(int);
        virtual operator double() const;
        virtual ostream& display(ostream&) const;
        virtual istream& read(istream&);
        virtual bool operator==(int) const;
        virtual bool operator==(const char*) const;

        virtual operator bool() const;
        virtual int qtyNeeded() const;


    };
    istream& operator>>(istream&, iProduct&);
    ostream& operator<<(ostream&, const iProduct&);


}
#endif 