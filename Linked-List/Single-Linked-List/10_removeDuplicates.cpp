/**
 *  author:- piyushkumar96
 *  description:- Remove duplicates from Linked List
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

    void removeDuplicates(){
        if(HEAD == NULL){
            cout<<"Linked List is empty "<<"\n";
        }else{
            struct Node *curr_ptr = HEAD;
            struct Node *prev_ptr = NULL;

            unordered_set<int> visited ;
            while(curr_ptr != NULL){
                if(visited.find(curr_ptr->item) != visited.end()){
                    prev_ptr->next = curr_ptr->next;
                    delete(curr_ptr);
                }else{
                    visited.insert(curr_ptr->item);
                    prev_ptr = curr_ptr;
                }
                curr_ptr = prev_ptr->next;
            }
        }
    }

    void deleteLinkedList(){
        if(HEAD == NULL){
            cout<<"Linked list is empty "<<"\n";
        }else{
            Node* CURR = HEAD;
            Node* NEXT ;
            while(CURR != NULL){
                NEXT = CURR->next;
                delete(CURR);
                CURR = NEXT;
            }
            HEAD = NULL;
            cout<<"Linked List is Successfully deleted"<<"\n";
        }
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
   while(1){
       cout<<"\nSimple Linked List \n 1. insert \n 2. remove Duplicates  \n 3. delete Linked List \n 4. Display \n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  cout<<" Enter element to insert (integer only)";
                    cin>>item;
                    ll.insert(item);
                    break;

           case 2:  ll.removeDuplicates();
                    cout<<"After removal of duplicates in ";
                    ll.printLL();
                    break;

           case 3:  ll.deleteLinkedList();
                    break;  

           case 4:  ll.printLL();
                    break;     

           default: exit(1);
                    break;
       }

   }

    return 0;
}