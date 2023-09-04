#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Menu.h"
#include "AidMan.h"
#include "Perishable.h"
#include "Item.h"
#include "Utils.h"
#include <iomanip>
#include <iostream>

using namespace std;

namespace sdds
{

    AidMan::AidMan()
    {
        char content[143] = "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n";
        filename = nullptr;
        main_menu = new Menu(content, 7);
    }


    void AidMan::save()
    {
        if (filename != nullptr)
        {
            std::ofstream out(filename);
            for (int i = 0; i < m_nop; i++)
            {
                m_pro[i]->save(out);
            }
        }
    }


    void AidMan::run()
    {
        do
        {
            int num = menu();
            if (num == 0)
            {
                cout << "Exiting Program!\n";
                break;
            }
            else if (num == 1)
            {
                cout << "\n****List Items****\n\n";
                list("as");
            }

            else if (num == 2)
                cout << "\n****Add Item****\n\n";
            else if (num == 3)
                cout << "\n****Remove Item****\n\n";
            else if (num == 4)
                cout << "\n****Update Quantity****\n\n";
            else if (num == 5)
                cout << "\n****Sort****\n\n";
            else if (num == 6)
                cout << "\n****Ship Items****\n\n";
            else
            {

                cout << "\n****New/Open Aid Database****\n";
                filename = new char[50];
                cout << "Enter file name: ";
                cin.ignore(1000, '\n');
                cin.getline(filename, 50, '\n');

                load();

                cout << m_nop << " records loaded!\n\n";

            }
        } while (1);
    }
    unsigned int AidMan::menu()
    {
        Menu m;
        unsigned int num_param = 0;
        cout << "Aid Management System Version 0.1";
        cout << endl;
        cout << "Date: 2022/03/31";
        cout << endl;
        cout << "Data file: ";
        if (filename == nullptr)
        {
            cout << "No file" << endl;
        }
        else
        {
            cout << filename << endl;
        }
        cout << "---------------------------------\n";
        num_param = main_menu->run();
        if (filename == nullptr)
        {
            num_param = 7;
        }
        return num_param;
    }

    AidMan::~AidMan()
    {
        delete filename;

        delete main_menu;

        main_menu = nullptr;

        for (int i = 0; i < m_nop; i++)
        {
            delete m_pro[i];
        }
    }

    bool AidMan::load()
    {
        for (int i = 0; i < m_nop; i++)
        {
            delete m_pro[i];
            m_pro[i] = nullptr;
        }



        std::ifstream infile(filename);


        if (!infile)
        {

            cout << "Failed to open " << filename << " for reading!";


            char content[20] = "1- Yes!\n0- Exit\n";

            filename = nullptr;

            Menu yn(content, 2);

            int opn = yn.run();

            if (opn == 0)

                return false;

            infile.open(filename);
        }




        if (infile)
        {

            for (int i = 0; infile; i++) {


                char ch = infile.peek();



                if (!isdigit(ch)) break;

                if (ch - '0' < 4)
                {
                    m_pro[i] = new Perishable;
                }
                else
                {
                    m_pro[i] = new Item;

                }





                if (m_pro[i]) {

                    m_pro[i]->load(infile);


                    m_nop++;



                }


                infile.ignore();

            }


        }

        if (m_nop > 0) return true;
        return false;


    }

    bool is_empty(std::ifstream& f)
    {
        return f.peek() == std::ifstream::traits_type::eof();
    }


    int AidMan::list(const char* sub_desc)
    {
        cout << setfill(' ');

        if (m_nop <= 0)
        {
            cout << "The list is emtpy!\n";
        }
        else
        {
            cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
            cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

            for (int i = 0; i < m_nop; i++) {

                cout.width(4);
                cout << i + 1 << " ";
                cout.setf(ios::right);
                cout << "| ";
                m_pro[i]->linear(true);
                cout << *m_pro[i];
                cout << endl;
            }

            cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;


            char opn;
            cout << "Enter row number to display details or <ENTER> to continue:\n";
            cout << "> ";
            cin.ignore();
            opn = getchar();

            if (isdigit(opn))
            {
                int op = (opn - '0') - 1;

                m_pro[op]->linear(false);
                cout << *m_pro[op] << "\n";
            }

            cout << "\n";


        }
        return m_nop;

    }


}
