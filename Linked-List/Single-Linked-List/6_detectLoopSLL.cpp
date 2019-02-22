/**
 *  author:- piyushkumar96
 *  description:- Detect Loop in Linked List (Floyd's Cycle and Hashing Method)
**/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int item;
    struct Node* next;
    Node(int item){
        this->item=item;
        next=NULL;
    }
};

struct LinkedList {
    Node* HEAD, *LAST;
    LinkedList(){
        HEAD=NULL;
        LAST=NULL;
    }
    void insert(int item){
        if(HEAD == NULL){
            //cout<<"Linked list is empty "<<"\n";
            Node* newnode = new Node(item);
            HEAD=newnode;
            LAST=newnode;
            cout<<"Successfully Inserted "<<"\n";
        }else {
                Node* CURR = HEAD;
                while(CURR->next != NULL){
                    CURR=CURR->next;
                }
                Node* newnode = new Node(item);
                CURR->next=newnode;
                LAST=newnode;
                cout<<"Successfully Inserted "<<"\n";
        }
    }
    
    // Method1 using Floyd's Cycle Algo
    void detectLoopM1(){
        if(HEAD == NULL){
            cout<<"Linked List is empty "<<"\n";
        }else {
            Node* SLOW = HEAD;
            Node* FAST = HEAD;
            while((SLOW != NULL) && (FAST != NULL) && (FAST->next != NULL)){
                FAST = FAST->next->next;
                SLOW = SLOW->next;
                if(SLOW == FAST){
                    cout<<" Loop Deteted" <<"\n";
                    return;
                }
            }
            cout<<"No Loop Detected"<<"\n";
        }
    }

    // Method2 using Hashing
    void detectLoopM2(){
        if(HEAD == NULL){
            cout<<"Linked List is empty "<<"\n";
        }else {
            unordered_set<struct Node*> s;
            struct Node* CURR = HEAD;
            while(CURR != NULL){
                if(s.find(CURR) != s.end()){
                    cout<<" Loop Deteted" <<"\n";
                    return;
                }
                s.insert(CURR);
                CURR = CURR->next;
                   
            } 
        }
    }

    void createLoop(){
        LAST->next = HEAD->next->next->next;
        cout<<" Loop is Created"<<"\n";
    }

    void printLL(){
        Node* CURR = HEAD;
        if(CURR == NULL){
            cout<<" Linked List is empty. Please insert element first"<<"\n";
        }else {
            cout<<"Linked List:- ";
            while(CURR != NULL){
                cout<<CURR->item<<" ";
                CURR=CURR->next;
            }
            cout<<"\n";
        }
    }

};

int main(){
   //ios::sync_with_stdio(false);
   //cin.tie(0);
   int i, item;
   LinkedList ll;
   ll.insert(1);
   ll.insert(2);
   ll.insert(3);
   ll.insert(4);
   ll.insert(5);
   ll.insert(6);
   ll.insert(7);
   ll.insert(8);
   ll.createLoop();
   while(1){
       cout<<"\nSimple Linked List \n 1. Floyd's Cycle Algo Method (Loop Detection) \n 2. Hashing Method (Loop Detection) \n 3. Display \n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  ll.detectLoopM1();
                    break;

           case 2:  ll.detectLoopM2();
                    break;

           case 3:  ll.printLL();
                    break;     

           default: exit(1);
                    break;
       }

   }

    return 0;
}