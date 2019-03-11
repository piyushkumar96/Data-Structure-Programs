/**
 *  author:- piyushkumar96
 *  description:- Reverse the Linked list (iterative and recursive)
**/

#include<bits/stdc++.h>
using namespace std;
typedef uintptr_t ut;

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
    
    //iterative method with three pointers

    void reverseLLIM1(){
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

    //iterative method with 2 pointers
    void reverseLLIM2(){
        if(HEAD == NULL){
            cout<<"Linked List is empty"<<"\n";
        }else{
            Node* CURR = HEAD;
            Node* PREV = NULL;
            while(CURR != NULL){
                // This example of list will clear it more 1->2->3->4 
                // initially prev = 1, current = 2 
                // Final expression will be current = 1^2^3^2^1, 
                // as we know that bitwise XOR of two same 
                // numbers will always be 0 i.e; 1^1 = 2^2 = 0 
                // After the evaluation of expression current = 3
                CURR= (struct Node*)((ut)PREV ^ (ut)CURR ^ (ut)(CURR->next) ^ (ut)(CURR->next=PREV) ^ (ut)(PREV=CURR) );
            }
            HEAD = PREV;
        }
    }

    void reverseLLRM1(struct Node** head){
        struct Node* first;
        struct Node* rest;

        if(head == NULL)
            return;
        
        first = *head;
        rest = first->next;

        if(rest == NULL)
            return;

        // to reset the HEAD to Last node
        if(rest->next == NULL){
            HEAD = rest;
        }

        /* reverse the rest list and put the first element at the end */
        reverseLLRM1(&rest);
        first->next->next = first;
        first->next = NULL;

        //Use above code or below code to set HEAD
        //*head = rest;
    }
    
    // A simple and tail recursive function to reverse  a linked list.  prev is passed as NULL initially.

    void reverseLLRM2(struct Node* curr, struct Node *prev, struct Node **head){
        
        /* If last node mark it head*/
        if(!curr->next){
            *head = curr;
            curr->next = prev;
            return;
        }

        struct Node *next = curr->next;
        curr->next = prev ;

        reverseLLRM2(next, curr, head);    
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
       cout<<"\nSimple Linked List \n 1. insert \n 2. reverseLinkedList (iterative method with 3 ptrs) \n 3. reverseLinkedList (iterative method with 2 ptrs) \n 4. reverseLinkedList (recursive method) \n 5. reverseLinkedList (tail recursive method)  \n 6. Display \n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  cout<<" Enter element to be insert ";
                    cin>>item;
                    ll.insert(item);
                    break;
           case 2:  ll.reverseLLIM1();
                    cout<<" Reversed LL :-";
                    ll.printLL();
                    break;
           case 3:  ll.reverseLLIM2();
                    cout<<" Reversed LL :-";
                    ll.printLL();
                    break;
           case 4:  ll.reverseLLRM1(&HEAD);
                    cout<<" Reversed LL :-";
                    ll.printLL();
                    break;
           case 5:  ll.reverseLLRM2(HEAD, NULL, &HEAD);
                    cout<<" Reversed LL :-";
                    ll.printLL();
                    break;
           case 6:  ll.printLL();
                    break;       
           default: exit(1);
                    break;
       }

   }

    return 0;
}