#include <iostream>
#include <string>
#include <fstream>
#include "Ingredient.h"
#include "Base.h"
#include "Item.h"
#include "Recipe.h"
#include "Database.h"
#include "linked_list.h"
#include "Choice.h"
#include "memtrace.h"

using namespace std;

int main(){

    bool run = true;
    Choice choice;
    Database* database = new Database();

    while(run){

        switch(choice.getChoice()){

            case 0:  //main menu
                choice.basic_menus();
                for(int i = 0; i < 30; i++){cout<<endl;}
                break;

            case 1:  //recipes
                choice.basic_menus();
                break;

            case 2:  //ingredients
                choice.basic_menus();
                break;

            case 3:  //search
                choice.basic_menus();
                break;

            case 4:  //save and exit
                choice.basic_menus();
                database->save();
                delete database;
                run = false;
                break;

            case 11:  //recipes->list
                choice.titles();
                database->listRecipe();
                choice.quit();
                break;

            case 12: //recipes->new
                choice.titles();
                database->addRec();
                choice.quit();
                break;

            case 13:  //recipes->delete
                choice.titles();
                database->deleteRecipe();
                choice.quit();
                break;

            case 21:  //ingredients->list
                choice.titles();
                database->listBases();
                database->listIngredients();
                choice.quit();
                break;

            case 22:  //ingredients->new
                choice.titles();
                database->addIng();
                choice.quit();
                break;

            case 31:  //search->by base ingredients
                choice.titles();
                database->searchByBase();
                choice.quit();
                break;

            case 32:  //search->by name
                choice.titles();
                database->searchByName();
                choice.quit();
                break;

            case -1:
                choice.setChoice(0);
                break;

            default:
                choice.setChoice(0);

        }
    }
    return 0;
}
