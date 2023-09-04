#ifndef SDDS_MENU_H
#define SDDS_MENU_H
namespace sdds
{
    class Menu
    {
    private:
        unsigned int menu_options;
        char* menu_content;

    public:
        ~Menu();
        unsigned int run();
        Menu();
        Menu(char*, unsigned int);

    };
}

#endif 