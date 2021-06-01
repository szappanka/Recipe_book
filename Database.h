#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include <fstream>

#include "Ingredient.h"
#include "Base.h"
#include "Recipe.h"
#include "linked_list.h"
#include "memtrace.h"

using namespace std;

class Database
{
    private:

        linked_list <Recipe> recipeBook;
        linked_list <Ingredient> ingredientBook;
        linked_list <Base> baseBook;

    public:
        Database();

        void listBases();
        void listIngredients();
        void listRecipe();

        void addIng();
        void addRec();
        void deleteRecipe();

        void searchByName();
        void searchByBase();

        int inRecipeBook(string name);
        int inIngredientBook(string name);
        int inBaseBook(string name);

        void save();

        virtual ~Database();
};

#endif // DATABASE_H
