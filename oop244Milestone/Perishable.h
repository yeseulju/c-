#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include "Date.h"
#include <iostream>
#include "Item.h"

namespace sdds
{
    class Perishable : public Item
    {
    private:
        Date m_expiry;
        char* headline;

    public:
        Perishable();
        ostream& display(ostream&) const;
        int readSku(istream&);
        istream& read(istream&);
        Perishable(const Perishable&);
        Perishable& operator=(const Perishable&);
        ~Perishable();
        ofstream& save(ofstream&) const;
        ifstream& load(ifstream&);
        const Date& expiry() const;
    };
}

#endif