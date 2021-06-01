#include "Choice.h"

Choice::Choice(){
    choice = 0;
}

void Choice::basic_menus(){
    for(int i = 0; i < 30; i++){cout<<endl;}
    int help;

    if(choice == 0){  //Main menu kiírása és a következõ lépés ellenõrzése
        cout << "Main menu\n\nRecipes(1)\nIngredients(2)\nSearch(3)\nSave and exit(4)\n\nYour choice: ";
        cin>>help;
        if(help > 0 && help  < 5){
            choice = help;}
        else{choice = -1;}
    }

    else if(choice==1){  //Recipes menu kiírása és a következõ lépés ellenõrzése
        cout << "Recipes\n\nList(11)\nNew recipe(12)\nDelete recipe(13)\nBack to main menu(0)\n\nYour choice: ";
        cin>>help;
        if((help > 10 && help  < 14) || help == 0){
            choice = help;}
        else{choice = -1;}
    }

    else if(choice==2){  //Ingredients menu kiírása és a következõ lépés ellenõrzése
        cout << "Ingredients\n\nList(21)\nNew(22)\nBack to main menu(0)\n\nYour choice: ";
        cin>>help;
        if((help > 20 && help  < 23) || help == 0){
            choice = help;}
        else{choice = -1;}
    }

    else if(choice==3){  //Search menu kiírása és a következõ lépés ellenõrzése
        cout << "Search\n\nBy base ingredient(31)\nBy name(32)\nBack to main menu(0)\n\nYour choice: ";
        cin>>help;
        if((help > 30 && help  < 33) || help == 0){
            choice = help;}
        else{choice = -1;}
    }
    else if(choice==4){  //Mentés és kilépés

        cout << "Thank you for using this application!\n";

    }
    else{choice = -1;}
}

void Choice::titles(){
    for(int i = 0; i < 30; i++){cout<<endl;}
    if(choice == 11){
        cout << "List of recipes\n\n";
    }
    else if(choice == 12){
        cout << "New recipe\n\n";
    }
    else if(choice == 13){
        cout << "Delete recipe\n\n";
    }
    else if(choice == 21){
        cout << "List of ingredients\n\n";
    }
    else if(choice == 22){
        cout << "New ingredient\n\n";
    }
    else if(choice == 31){
        cout << "Search by base\n\n";
    }
    else if(choice == 32){
        cout << "Search by name\n\n";
    }
}

void Choice::quit(){

    int help;

    if(choice > 10 && choice  < 14){  //Recipes menu kiírása és a következõ lépés ellenõrzése
        cout << "\nBack(1)\n\nYour choice: ";
        cin >> help;
        for(int i = 0; i < 30; i++){cout<<endl;}
        if(help == 1){
            choice = help;}
        else{choice = -1;}
    }

    else if(choice > 20 && choice  < 23){  //Main menu kiírása és a következõ lépés ellenõrzése
        cout << "\nBack(2)\n\nYour choice:";
        cin>>help;
        for(int i = 0; i < 30; i++){cout<<endl;}
        if(help == 2){
            choice = help;}
        else{choice = -1;}
    }

    else if(choice > 30 && choice  < 33){  //Main menu kiírása és a következõ lépés ellenõrzése
        cout << "\nBack(3)\n\nYour choice:";
        cin>>help;
        for(int i = 0; i < 30; i++){cout<<endl;}
        if(help == 3){
            choice = help;}
        else{choice = -1;}
    }
    else{choice = -1;}
}

Choice::~Choice(){}
