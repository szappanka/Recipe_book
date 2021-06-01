#ifndef RECIPE_H
#define RECIPE_H

#include <iostream>
#include <string>
#include <fstream>
#include "Item.h"
#include "Base.h"
#include "linked_list.h"
#include "memtrace.h"

using namespace std;


class Recipe
{
    private:

        string recipeName;
        int itempc;
        linked_list<Item> items;
        Item* baseItem;

    public:
        Recipe();
        Recipe(string name, int i): recipeName(name), itempc(i) {};

        string getRecipeName(){return recipeName;};
        int getItempc(){ return itempc;};
        string getBaseName(){return baseItem->getIngre()->getName();}

        void setRecipe(string name, int i){
            recipeName = name;
            itempc = i;
        }

        void setBaseItem(Item* base){
            baseItem = base;
        }

        void addItem(Item* it);
        void printRecipe();
        void printToFile(ofstream *help);

        virtual ~Recipe();

};

#endif // RECIPE_H
