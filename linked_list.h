#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "memtrace.h"

using namespace std;

template<typename T>
class linked_list{

    private:

        struct node{
            T data;
            node* next;
        };

        node* head;

    public:

        linked_list<T>(){head = NULL;};

        node* gethead(){return head;};

        void add_node(T* pointer){  //hozz�ad a l�ncolt list�hoz elemet

            node *tmp = new node;
            tmp->data = *pointer;
            tmp->next = NULL;

            if(head == NULL)
            {
                head = tmp;
            }
            else
            {
                node *helper = head;

                while (helper->next != NULL){
                    helper = helper->next;
                    }

                helper->next = tmp;
            }
        };

        void delete_node(int a){ //kit�rli az a. sz�m� elem�t a l�ncolt list�nak (node)

            node *jumper = head;
            node *prev = NULL;

            for(int i = 0; i < a; i++){

                prev = jumper;
                jumper = jumper->next;
            }

            if(a == 0){

                node *newhead = jumper->next;
                delete jumper;
                head = newhead;
            }

            else{

                prev->next = jumper->next;
                delete jumper;
            }
        }

        node* search_node(int num){  //visszaadja a num. sz�m� elem�t a l�ncolt list�nak (node)
            node *jumper = head;
            int i = 0;

            while(i<num){

                jumper = jumper->next;
                i++;
            }

            return jumper;

        };

        T getData(int num){  //visszaadja egy l�ncolt lista num. elem�nek T adat�t (node.data)

            node *jumper = head;
            int i = 0;

            while(i<num){

                jumper = jumper->next;
                i++;
            }

            return jumper->data;
        }

        int getCount(){  //megsz�molja a l�ncolt lista elemeit
            node *jumper;
            int i = 0;
                for (jumper = head; jumper != NULL; jumper = jumper->next){
                    i++;
                }
                return i;
        };

        virtual ~linked_list<T>(){
            node *jumper = head;

            while (jumper != NULL) {
                node* next = jumper->next;
                delete jumper;
                jumper = next;
            }
        };
};

#endif // LINKED_LIST_H
