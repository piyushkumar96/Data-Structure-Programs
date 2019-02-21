/**
 *  author:- piyushkumar96
 *  description:- XOR Double Linked List 
**/

#include<bits/stdc++.h>
#include <inttypes.h>
using namespace std;

struct Node {
    int item;
    struct Node* npx;
    Node(int item){
        this->item = item;
    }

} *HEAD;

struct Node* XOR(struct Node* a, struct Node* b){
    return (struct Node* ) ((uintptr_t)(a) ^ (uintptr_t)(b));
};

struct DoubleLinkedList {
    DoubleLinkedList(){
        HEAD = NULL;
    }

    void insert(int item){

        Node* newnode = new Node(item);
        newnode->npx = XOR(HEAD,NULL);

        if(HEAD != NULL){
            struct Node* CURR = XOR(HEAD->npx,NULL);
            HEAD->npx = XOR(newnode,CURR);
        }
        HEAD = newnode;
        cout<<"Successfully Inserted "<<"\n";
    }

    void printLL(){
        struct Node* CURR = HEAD;
        if(CURR == NULL){
            cout<<" Linked List is empty. Please insert element first"<<"\n";
        }else {
            cout<<"Linked List:- ";
            struct Node* PREV = NULL;
            struct Node* CURR = HEAD;
            struct Node* NEXT;
            while(CURR != NULL){
                cout<<CURR->item<<" ";
                NEXT = XOR(PREV,CURR->npx);
                PREV = CURR;
                CURR = NEXT;
            }
            cout<<"\n";
        }
    }    

};

int main(){
   int i, item;
   DoubleLinkedList dll;
   while(1){
       cout<<"\n Double Linked List \n 1. insert \n 2. Display \n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  cout<<" Enter element to be insert at last ";
                    cin>>item;
                    dll.insert(item);
                    break;                
           case 2:  dll.printLL();
                    break;       
           default: exit(1);
                    break;
       }

   }

    return 0;
}