#ifndef CHOICE_H
#define CHOICE_H

#include <iostream>
#include "memtrace.h"

using namespace std;

class Choice
{
    private:

        int choice;

    public:
        Choice();

        int getChoice(){return choice;};
        void setChoice(int help){choice = help;};
        void basic_menus();
        void titles();
        void quit();

        virtual ~Choice();

};

#endif // CHOICE_H
