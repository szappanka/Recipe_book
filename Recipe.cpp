#include "Recipe.h"

Recipe::Recipe(){
    items = linked_list<Item>();
}

void Recipe::addItem(Item* it){
    items.add_node(it);
}

void Recipe::printRecipe(){
    cout << recipeName;
    Base* help = (Base*)baseItem->getIngre();

    if(help->haveA()){cout<<" (alcoholic)\n";}
    else{cout<<" (alcohol-free)\n";}

    cout << baseItem->getQuantity() << " " << baseItem->getIngre()->getUnit() << " " << baseItem->getIngre()->getName() << "\n";

    for(int i = 0; i < itempc-1; i++){
        cout << items.getData(i).getQuantity()<< " " << items.getData(i).getIngre()->getUnit()<< " "<< items.getData(i).getIngre()->getName()<<"\n";

    }
    cout<<"\n";
}

void Recipe::printToFile(ofstream *file){

    Base* help = (Base*)baseItem->getIngre();

    *file << itempc << " " << recipeName << "\n" << baseItem->getQuantity() << " " << help->getUnit() << " " << help->getName() << " " << help->getAlcohol() << "\n";

    for(int i = 0; i < itempc-1; i++){

        *file << items.search_node(i)->data.getQuantity() << " " << items.search_node(i)->data.getIngre()->getUnit()<< " " << items.search_node(i)->data.getIngre()->getName()<<"\n";
    }

    *file<<"\n";
}

Recipe::~Recipe(){

}
