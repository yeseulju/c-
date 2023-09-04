#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

#include "iProduct.h"
#include "Status.h"


using namespace std;


namespace sdds
{
    class Item : public iProduct
    {
    private:
        double m_price;
        int m_qty;
        int m_qtyNeeded;
        char* m_description;

    protected:
        bool m_linear;
        Status m_state;
        int m_sku;
        bool linear();

    public:
        int readSku(istream&);
        operator double() const;
        operator bool() const;
        int operator-=(int);
        int operator+=(int);
        void linear(bool);
        void clear();
        bool operator==(int) const;
        Item();
        Item(const Item&);

        int qtyNeeded() const;
        int qty() const;

        bool operator==(const char* decription) const;
        ofstream& save(ofstream&) const;
        ifstream& load(ifstream&);
        Item& operator=(const Item&);
        ~Item();
        ostream& display(ostream&) const;

        istream& read(istream&);
    };
}

#endif 