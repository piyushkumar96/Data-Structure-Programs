/**
 *  author:- piyushkumar96
 *  description:- Reverse the Linked list (iterative and recursive)
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
} *HEAD;

struct LinkedList {

    LinkedList(){
        HEAD=NULL;
    }
    void insert(int item){
        if(HEAD == NULL){
            Node* newnode = new Node(item);
            HEAD=newnode;
            cout<<"Successfully Inserted "<<"\n";
        }else {
                Node* CURR = HEAD;
                while(CURR->next != NULL){
                    CURR=CURR->next;
                }
                Node* newnode = new Node(item);
                CURR->next=newnode;
                cout<<"Successfully Inserted "<<"\n";
        }
    }
    
    void reverseLLM1(){
        if(HEAD == NULL){
            cout<<"Linked list is empty "<<"\n";
        }else {
            Node* CURR = HEAD, *PREV= NULL, *NEXT=NULL;
            while(CURR != NULL){
                NEXT=CURR->next;
                CURR->next=PREV;
                PREV=CURR;
                CURR=NEXT;            
            }  
            HEAD=PREV;   
            cout<<" Linked List is reversed "<<"\n";              
        }
    }

    void reverseLLM2(struct Node** head){
        struct Node* first;
        struct Node* rest;

        if(head == NULL)
            return;
        
        first = *head;
        rest = first->next;

        if(rest == NULL)
            return;
        
        reverseLLM2(&rest);
        first->next->next = first;
        first->next = NULL;
        
        *head = rest;
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
   int i, item, ele;
   LinkedList ll;
   while(1){
       cout<<"\nSimple Linked List \n 1. insert \n 2. reverseLL (iterative method) \n 3. reverseLinkedList (recursive method)  \n 4. Display \n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  cout<<" Enter element to be insert ";
                    cin>>item;
                    ll.insert(item);
                    break;
           case 2:  ll.reverseLLM1();
                    cout<<" Reversed LL :-";
                    ll.printLL();
                    break;
           case 3:  ll.reverseLLM2(&HEAD);
                    cout<<" Reversed LL :-";
                    ll.printLL();
                    break;
           case 4:  ll.printLL();
                    break;       
           default: exit(1);
                    break;
       }

   }

    return 0;
}