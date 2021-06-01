#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include "Ingredient.h"
#include "memtrace.h"

using namespace std;

class Item
{
    private:

        Ingredient* ingredient;
        double quantity;

    public:

        Item(){};

        double getQuantity() const { return quantity;};
        Ingredient* getIngre() const {return ingredient;};

        void setItem(Ingredient* i, double q){
            ingredient = i;
            quantity = q;
        }

        virtual ~Item(){};

};

#endif // ITEM_H
