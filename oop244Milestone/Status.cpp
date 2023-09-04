#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include "Status.h"
#include <iostream>
#include <string>

using namespace std;
namespace sdds
{
    Status& Status::clear()
    {
        delete[] status_des;
        status_des = nullptr;
        status_code = 0;
        return *this;
    }


    Status& Status::operator=(const Status& status_param)
    {
        delete[] status_des;
        status_des = nullptr;
        status_code = status_param.status_code;

        if (status_param)
        {
            status_des = new char[strlen(status_param.status_des) + 1];
            strcpy(status_des, status_param.status_des);
        }
        else
        {
            status_des = NULL;
        }

        return *this;
    }

    Status::~Status()
    {
        delete[] status_des;
        status_des = nullptr;
    }

    Status& Status::operator=(const char* str_param)
    {
        delete[] status_des;
        status_des = nullptr;
        if (str_param == nullptr)
            return *this;
        status_des = new char[strlen(str_param) + 1];
        strcpy(status_des, str_param);
        return *this;
    }

    Status& Status::operator=(const int code_param)
    {
        status_code = code_param;
        return *this;
    }

    Status::operator bool() const
    {
        if (status_des != nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Status::operator int() const
    {
        return status_code;
    }

    Status::Status(char* str_param, int code_param)
    {
        status_code = code_param;

        if (str_param != NULL)
        {
            status_des = new char[strlen(str_param) + 1];
            strcpy(status_des, str_param);
        }
        else
        {
            status_des = NULL;
        }
    }

    Status::Status(const Status& status_param)
    {
        status_code = status_param.status_code;

        if (!status_param)
        {
            status_des = new char[strlen(status_param.status_des) + 1];
            strcpy(status_des, status_param.status_des);
        }
        else
        {
            status_des = NULL;
        }
    }

    Status::operator char* () const
    {
        return status_des;
    }

    ostream& operator<<(ostream& os_param, const Status& status_param)
    {
        if (!status_param)
        {
            if (status_param.status_code != 0)
                os_param << "ERR#" << status_param.status_code << ": ";
            os_param << status_param.status_des;
        }
        return os_param;
    }

}