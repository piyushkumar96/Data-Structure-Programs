/**
 *  author:- piyushkumar96
 *  description:- Searching the Element (Recursive and Iterative)
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

    void iterativeSearch(int item){
        if(HEAD == NULL){
            cout<<"Linked List is empty "<<"\n";
        }else {

            Node* CURR = HEAD;
            int count = 0;
            while(CURR != NULL){
                count++;
                if(CURR->item == item){
                    cout<<" Element found at position "<<count<<"\n";
                    return;
                }
                CURR = CURR->next;
            }
        }
        cout<<" Element not found \n";
    }

    void rSearch(Node* headref, int item, int count){
        if(HEAD == NULL){
            cout<<"Linked List is empty "<<"\n";
        }else {

            if(headref->item == item){
               cout<<" Element found at position "<<count<<"\n";
               return;
            }
            if(headref->next == NULL){
                cout<<" Element not found \n";
                return;
            }else{
                rSearch(headref->next,item,++count);
            }
        }
    }

    void recursiveSearch(int item){
        int count = 1;
        rSearch(HEAD,item,count);
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
       cout<<"\nSimple Linked List \n 1. insert \n 2. iterativeSearch \n 3. recursiveSearch \n 4. Display \n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  cout<<" Enter element to insert ";
                    cin>>item;
                    ll.insert(item);
                    break;

           case 2:  cout<<" Enter element for searching ";
                    cin>>item;
                    ll.iterativeSearch(item);
                    break;

           case 3:  cout<<" Enter element for searching ";
                    cin>>item;
                    ll.recursiveSearch(item);
                    break;

           case 4:  ll.printLL();
                    break;     

           default: exit(1);
                    break;
       }

   }

    return 0;
}