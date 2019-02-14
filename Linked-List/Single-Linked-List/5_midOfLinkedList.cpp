/**
 *  author:- piyushkumar96
 *  description:- Middle Element (Two Methods Used)
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
    void midOfLinkedListM1(){
        if(HEAD == NULL){
            cout<<"Linked List is empty "<<"\n";
        }else if(HEAD->next == NULL){
            cout<<" The middle element is "<<HEAD->item<<"\n";
        }else {

            Node* CURR = HEAD;
            int count = 0;
            while(CURR != NULL){
                count++;
                CURR = CURR->next;
            }

            CURR = HEAD;
            for(int i=0; i<((count/2)-1); i++){
                    CURR = CURR->next;
            }
            if(count%2 == 0){
                cout<<" The middle elements are "<<CURR->item<<" and "<<CURR->next->item<<"\n";
            }else{
                cout<<" The middle element is "<<CURR->next->item<<"\n";
            }
        }
    }

    // Method2 using two pointers slow and fast poniters
    void midOfLinkedListM2(){
        if(HEAD == NULL){
            cout<<"Linked List is empty "<<"\n";
        }else {
            int count = 0;
            Node* SLOW = HEAD;
            Node* FAST = HEAD;
            while((FAST != NULL) && (FAST->next != NULL)){
                FAST = FAST->next->next;
                SLOW = SLOW->next;
            }
            cout<<" The middle element is "<<SLOW->item<<"\n";
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
       cout<<"\nSimple Linked List \n 1. insert \n 2. Single Pointer Method (middle element) \n 3. Double Pointer Method (middle element) \n 4. Display \n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  cout<<" Enter element to insert ";
                    cin>>item;
                    ll.insert(item);
                    break;

           case 2:  ll.midOfLinkedListM1();
                    break;

           case 3:  ll.midOfLinkedListM2();
                    break;

           case 4:  ll.printLL();
                    break;     

           default: exit(1);
                    break;
       }

   }

    return 0;
}