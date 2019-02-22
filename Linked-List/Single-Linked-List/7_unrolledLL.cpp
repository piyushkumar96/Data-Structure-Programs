/**
 *  author:- piyushkumar96
 *  description:- Unrolled Linked List
**/

#include<bits/stdc++.h>
using namespace std;

struct UnrolledNode{
    int *item ;
    int num_items;
    struct UnrolledNode* next;
    UnrolledNode(int n){
        item = new int[n];
        next = NULL;
        num_items = 0; 
    }
};

struct UnrolledLinkedList {
    UnrolledNode* start_pos;
    UnrolledNode* end_pos;
    
    int size_node;
    int nNode;

    UnrolledLinkedList(int capacity){
        start_pos = NULL;
        end_pos = NULL;
        nNode = 0;
        size_node = capacity + 1;
    }

    void insert(int num){
        nNode++;
        cout<<"size_node "<<size_node<<"\n";
        // Check if the list starts from NULL
        if(start_pos == NULL){
            start_pos = new UnrolledNode(size_node);
            start_pos->item[0] = num;
            start_pos->num_items++;
            end_pos = start_pos;
            return;
        }

        // Attaching the elements into nodes 
        if((end_pos->num_items + 1) < size_node){
            end_pos->item[end_pos->num_items] = num ;
            end_pos->num_items++;
        }else{
            // Creation of new Node 
            UnrolledNode* node_pointer = new UnrolledNode(size_node);
            int j = 0;
            for(int i = end_pos->num_items / 2 + 1; i < end_pos->num_items; i++){
                node_pointer->item[j++] = end_pos->item[i];
            }

            node_pointer->item[j++] = num;
            node_pointer->num_items = j;
            end_pos->num_items = end_pos->num_items / 2 + 1;
            end_pos->next = node_pointer;
            end_pos = node_pointer ;
            cout<<"new node created";
        }
    }    

    void display(){
        cout<<" Unrolled Linked List :-\n";
        struct UnrolledNode* START = start_pos;
        while(START != NULL){
            for(int i=0; i<START->num_items; i++){
                cout<<START->item[i]<<" ";
            }
            cout<<"\n";
            START = START->next;
        }
        cout<<"\n";
    }

};

int main(){
   int i, item, capacity;
   cout<<"Enter the capacity for Unrolled Linked List:- ";
   cin>>capacity;
   UnrolledLinkedList ull(capacity);
   while(1){
       cout<<"\nUnrolled Linked List \n 1. insert \n 2. Display \n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  cout<<" Enter element to be insert ";
                    cin>>item;
                    ull.insert(item);
                    break;

           case 2:  ull.display();
                    break;       
           default: exit(1);
                    break;
       }

   }

    return 0;
}