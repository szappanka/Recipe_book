#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <iostream>
#include <string>
#include <fstream>
#include "memtrace.h"

using namespace std;


class Ingredient
{
    private:

        string name;
        string unit;

    public:

        Ingredient();
        Ingredient(string name, string unit) :name(name), unit(unit) {};

        string getName(){ return name;};
        string getUnit(){ return unit;};

        void setIng(string n, string u){
            name = n;
            unit = u;
        };

        virtual ~Ingredient();

};

#endif // INGREDIENT_H
