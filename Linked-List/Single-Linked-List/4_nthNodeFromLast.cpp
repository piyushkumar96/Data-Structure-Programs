/**
 *  author:- piyushkumar96
 *  description:- Nth Element from Last (Two Methods Used)
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
    Node* HEAD;
    LinkedList(){
        HEAD=NULL;
    }
    void insert(int item){
        if(HEAD == NULL){
            //cout<<"Linked list is empty "<<"\n";
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
    
    // Method1 using single pointer and length of Linked List
    void nthNodeFromLastM1(int n){
        if(HEAD == NULL){
            cout<<"Linked List is empty "<<"\n";
        }else {

            Node* CURR = HEAD;
            int count = 0;
            while(CURR != NULL){
                count++;
                CURR = CURR->next;
            }

            CURR = HEAD;
            for(int i=0; i<(count - n); i++){
                CURR = CURR->next;
            }
            cout<<" The "<<n<<"th element from Last is "<<CURR->item<<"\n";
        }
    }

    // Method2 using two pointers 
    void nthNodeFromLastM2(int n){
        if(HEAD == NULL){
            cout<<"Linked List is empty "<<"\n";
        }else {

            Node* CURR = HEAD;
            Node* NEXT = HEAD;
            for(int i=0; i<n; i++){
                CURR = CURR->next;
            }
            while(CURR != NULL){
                CURR = CURR->next;
                NEXT = NEXT->next;
            }
            cout<<" The "<<n<<"th element from Last is "<<NEXT->item<<"\n";
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
   int i, n, item;
   LinkedList ll;
   while(1){
       cout<<"\nSimple Linked List \n 1. insert \n 2. Single Pointer Method (for nth last element) \n 3. Double Pointer Method (for nth last element) \n 4. Display \n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  cout<<" Enter element to insert ";
                    cin>>item;
                    ll.insert(item);
                    break;

           case 2:  cout<<" Enter the value of n ";
                    cin>>n;
                    ll.nthNodeFromLastM1(n);
                    break;

           case 3:  cout<<" Enter the value of n ";
                    cin>>n;
                    ll.nthNodeFromLastM2(n);
                    break;

           case 4:  ll.printLL();
                    break;     

           default: exit(1);
                    break;
       }

   }

    return 0;
}