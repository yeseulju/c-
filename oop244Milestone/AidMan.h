#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include "Menu.h"
using namespace std;

namespace sdds
{
    class AidMan
    {
    private:
        unsigned int menu();
        Menu* main_menu;
        char* filename;

    public:
        void run();
        AidMan();
        ~AidMan();
    };
}

#endif