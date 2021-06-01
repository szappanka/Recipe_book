#ifndef BASE_H
#define BASE_H

#include "Ingredient.h"
#include "memtrace.h"
class Base : public Ingredient
{
    private:

        int haveAlcohol;

    public:

        Base();

        Base(string name, string unit, int k):Ingredient(name, unit),haveAlcohol(k) {};

        int getAlcohol(){return haveAlcohol;};

        void setBase(string n, string u, int i){

            setIng(n, u);
            haveAlcohol = i;

        };

        bool haveA();

        virtual ~Base();

};

#endif // BASE_H
