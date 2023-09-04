#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <cstring>
#include <string>
#include "Menu.h"
using namespace std;

namespace sdds
{
    unsigned int Menu::run()
    {
        string choice_param;
        int flag = 0;
        int num_param;

        cout << menu_content;
        cout << "0 - Exit" << endl;
        cout << "> ";
        while (1)
        {
            flag = 0;
            cin >> choice_param;
            for (char c : choice_param)
            {
                if (isdigit(c))
                    continue;
                flag = 1;
                break;
            }
            if (flag == 1)
            {
                cout << "Invalid Integer, retry: ";
            }
            else
            {
                num_param = stoi(choice_param);
                if (num_param >= 0 && num_param <= 7)
                    return num_param;
                else
                {
                    cout << "Value out of range [0<=val<=7]: ";
                }
            }
        }
        return -1;
    }
    Menu::Menu()
    {
        menu_content = nullptr;
        menu_options = 0;
    }

    Menu::Menu(char* content_param, unsigned int options_param)
    {
        if (options_param <= 15 || content_param != nullptr)
        {
            menu_options = options_param;
            menu_content = new char[strlen(content_param) + 1];
            strcpy(menu_content, content_param);
        }
        else
        {
            menu_options = 0;
            menu_content = nullptr;
        }
    }

    Menu::~Menu()
    {
        delete[] menu_content;
        menu_content = nullptr;
    }

}