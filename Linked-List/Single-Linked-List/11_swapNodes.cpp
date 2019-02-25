/**
 *  author:- piyushkumar96
 *  description:- swap two nodes in linked list (by swapping pointers)
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

    void swapNodes(int x, int y){
        if(HEAD == NULL){
            cout<<"Linked List is empty "<<"\n";
        }else{
            
            //if x and y are same 
            if(x == y){
                return;
            }

            struct Node *prevX = NULL;
            struct Node *currX = HEAD;
            while(currX != NULL){
                if(currX->item == x){
                    break;
                }
                prevX = currX;
                currX = currX->next;
            }


            struct Node *prevY = NULL;
            struct Node *currY = HEAD;
            while(currY != NULL){
                if(currY->item == y){
                    break;
                }
                prevY = currY;
                currY = currY->next;
            }

            //checking if either of node exits or not
            if(currX == NULL || currY == NULL)
                return;

            //if x is head then replace with y as new head
            if(prevX != NULL){
                prevX->next = currY;
            }else{
                HEAD = currY;
            }

            //if y is head then replace with x as new head
            if(prevY != NULL){
                prevY->next = currX;
            }else{
                HEAD = currX;
            }
            
            //swap pointers 
            struct Node *temp = currY->next;
            currY->next = currX->next;
            currX->next = temp;
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
       cout<<"\nSimple Linked List \n 1. insert \n 2. swap nodes  \n 3. delete Linked List \n 4. Display \n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  cout<<" Enter element to insert (integer only )";
                    cin>>item;
                    ll.insert(item);
                    break;

           case 2:  int x , y;
                    cout<<" Enter the nodes x and y for swapping :- ";
                    cin>>x>>y;
                    ll.swapNodes(x,y);
                    cout<<"After swapping the  ";
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