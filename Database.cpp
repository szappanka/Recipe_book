#include "Database.h"

Database::Database(){

    ifstream baseFile;
	baseFile.open("bases.txt");

    string f;
    string s;
    int t;

	while(baseFile>> f >> s >> t){

        Base* newb = new Base;
        newb->setBase(f, s, t);
        baseBook.add_node(newb);
	}

	baseFile.close();

	ifstream ingFile;
	ingFile.open("ingredients.txt");

	ingredientBook = linked_list<Ingredient>();

    string first;
    string second;
    Ingredient* new_ing = new Ingredient();

    while(ingFile >> first >> second){
        new_ing->setIng(first, second);
        ingredientBook.add_node(new_ing);
    }

	ingFile.close();

    ifstream recFile;
    recFile.open("recipes.txt");

    recipeBook = linked_list<Recipe>();

    string name;
    string alc;
    int num;
    double q;

    while(recFile >> num >> name){

        Recipe* newRec = new Recipe();
        Base* newb = new Base;
        Item* basei = new Item;
        string basename;
        string baseunit;
        double b;
        int haveA;

        recFile >> b >> baseunit >> basename >> haveA;
        newb->setBase(basename, baseunit, haveA);
        basei->setItem(newb, b);
        newRec->setBaseItem(basei);

        for(int i = 0; i < num-1; i++){
            string ingname;
            string ingunit;
            Item* newIt = new Item();
            Ingredient* newin = new Ingredient();
            recFile >> q >> ingunit >> ingname;
            newin->setIng(ingname, ingunit);
            newIt->setItem(newin, q);
            newRec->setRecipe(name, num);
            newRec->addItem(newIt);
        }

    recipeBook.add_node(newRec);
    }
    recFile.close();

}

void Database::listBases(){

    cout << "Bases\n\n";

    for(int i = 0; i < baseBook.getCount(); i++){
        cout<<baseBook.search_node(i)->data.getName()<< " (" << baseBook.search_node(i)->data.getUnit() <<")\n";
    }

    cout << "\n";

}

void Database::listIngredients(void){

    cout << "Ingredients\n"<<endl;

    for(int i = 0; i < ingredientBook.getCount(); i++){
        cout<<ingredientBook.search_node(i)->data.getName()<< " (" << ingredientBook.search_node(i)->data.getUnit() <<")\n";
    }
    cout << "\n";
}

void Database::listRecipe(){

   for(int i = 0; i < recipeBook.getCount(); i++){
        recipeBook.search_node(i)->data.printRecipe();
    }
}

void Database::addIng(){
    cout << "Give the name: ";
    string name;
    cin  >> name;
    if(inIngredientBook(name)!=-1){
        cout<<"\nIt is already in the database!\n\n";
        addIng();
    }
    else{
        Ingredient* new_ing = new Ingredient();
        cout << "Give the unit: ";
        string unit;
        cin >> unit;
        new_ing->setIng(name, unit);
        ingredientBook.add_node(new_ing);
        cout << "\nYou have successfully added a new ingredient.\n";
    }
}

void Database::addRec(){

    string name;
    int num;
    double q;
    Item* newIt = new Item();
    Recipe* newRec = new Recipe();

    cout << "Give the name of the recipe: ";
    cin >> name;
    if(inRecipeBook(name)!=-1){
        cout << "It is already in the database.\n\n";
        delete newIt;
        delete newRec;
        addRec();
    }
    cout << "Give the number of the items: ";
    cin >> num;

    while(num < 2){
        cout << "\nYou need minimum 2 ingredients.\n";
        cout << "Give the number of the items: ";
        cin >> num;
    }

    string basebase;
    cout << "Give the name of the 1st (base) ingredient: ";
    cin >> basebase;

    while(inBaseBook(basebase)==-1){
        cout << "\nThe base ingredient isn't in the database.\n";
        cout << "Give the name of the 1st/base ingredient: ";
        cin >> basebase;
    }

    cout << "Give the measure of the base ingredient("<< ingredientBook.getData(inIngredientBook(basebase)).getUnit()<<"): ";
    cin >> q;
    Base* newb = new Base();
    Item* newIte = new Item();
    *newb = baseBook.getData(inBaseBook(basebase));
    newIte->setItem(newb, q);
    newRec->setBaseItem(newIte);

    for(int i = 0; i < num-1; i++){
        string namename;
        cout << "\nGive the name of the " << i+2 << ". ingredients: ";
        cin >> namename;
        if(inIngredientBook(namename)!=-1){ // ha benne van az eddigi listában

            cout << "Give the measure of the " << i+1 << ". ingredient("<< ingredientBook.getData(inIngredientBook(namename)).getUnit()<<"): ";
            cin >> q;
            Ingredient* newin = new Ingredient();
            *newin = ingredientBook.getData(inIngredientBook(namename));
            newIt->setItem(newin, q);
            newRec->setRecipe(name, num);
            newRec->addItem(newIt);

        }
        else{cout << "\nThe ingredient isn't in the database.\n"; i--;}
        }
        recipeBook.add_node(newRec);
        cout << "\nYou have successfully added a new recipe.\n";
}

void Database::deleteRecipe(){
    string name;
    cout << "The name of the recipe: ";
    cin >> name;

    if (inRecipeBook(name) ==-1){
        cout << "It is not a existing recipe.\n\n";
        deleteRecipe();
    }
    else{
        recipeBook.delete_node(inRecipeBook(name));
        cout <<"\nYou have successfully delete a recipe!";
    }
}

void Database::searchByName(){

    string name;
    cout << "The name of the recipe: ";
    cin >> name;

    if (inRecipeBook(name) ==-1){
        cout << "It is not a existing recipe.\n\n";
        searchByName();
    }
    else{
        cout << endl;
        recipeBook.search_node(inRecipeBook(name))->data.printRecipe();
    }

}

void Database::searchByBase(){
    string name;
    cout << "The name of the base: ";
    cin >> name;

    if (inBaseBook(name) ==-1){
        cout << "It is not a existing base.\n\n";
        searchByBase();
    }
    else{

        cout<<endl;

        for(int i = 0; i < recipeBook.getCount(); i++){

            if (recipeBook.search_node(i)->data.getBaseName() == name){

                recipeBook.search_node(i)->data.printRecipe();
            }
        }
    }
}

int Database::inRecipeBook(string name){

    for(int i = 0; i < recipeBook.getCount(); i++){
            if(name==recipeBook.search_node(i)->data.getRecipeName()){return i;}
    }
    return -1;
}

int Database::inIngredientBook(string name){

    for(int i = 0; i < ingredientBook.getCount(); i++){
            if(name==ingredientBook.search_node(i)->data.getName()){return i;}
    }
    return -1;
}

int Database::inBaseBook(string name){

    for(int i = 0; i < baseBook.getCount(); i++){
            if(name==baseBook.search_node(i)->data.getName()){return i;}
    }
    return -1;
}

void Database::save(){
    ofstream recFile;
    recFile.open("recipes.txt");

    for(int i = 0; i < recipeBook.getCount(); i++){

        recipeBook.search_node(i)->data.printToFile(&recFile);
    }
    recFile.close();

    ofstream ingFile;
    ingFile.open("ingredients.txt");

    for(int i = 0; i < ingredientBook.getCount(); i++){
        ingFile<<ingredientBook.search_node(i)->data.getName()<< " " << ingredientBook.search_node(i)->data.getUnit() <<"\n";
    }
    ingFile << "\n";
    ingFile.close();
}

Database::~Database(){}
