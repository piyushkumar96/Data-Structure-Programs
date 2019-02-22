/**
 *  author:- piyushkumar96
 *  description:- Using(new) Double Linked List ( Insertion, Deletion, TraverseLastToFirst)
**/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int item;
    struct Node* prev;
    struct Node* next;
    Node(int item){
        this->item = item;
    }

} *HEAD;

struct DoubleLinkedList {
    DoubleLinkedList(){
        HEAD = NULL;
    }

    void insertLast(int item){
        if(HEAD == NULL){
            Node* newnode = new Node(item);
            newnode->prev = NULL;
            newnode->next = NULL;
            HEAD=newnode;
            cout<<"Successfully Inserted "<<"\n";
        }else {
                Node* CURR = HEAD;
                while(CURR->next != NULL){
                    CURR=CURR->next;
                }
                Node* newnode = new Node(item);
                CURR->next=newnode;
                newnode->prev = CURR;
                newnode->next = NULL;
                cout<<"Successfully Inserted "<<"\n";
        }
    }
    void insertBegining(int item){
        if(HEAD == NULL){
            Node* newnode = new Node(item);
            newnode->prev = NULL;
            newnode->next = NULL;
            HEAD=newnode;
            cout<<"Successfully Inserted "<<"\n";
        }else {
                Node* newnode = new Node(item);
                newnode->next = HEAD;
                newnode->prev = NULL;
                HEAD=newnode;
                cout<<"Successfully Inserted "<<"\n";
        }
    }

    void insertAfter(int ele, int item){
        if(HEAD == NULL){
            cout<<"Linked List is empty \n Use either insertLast or insertBegining to insert first element in LL "<<"\n";
        }else {
                Node* CURR = HEAD;
                while(CURR != NULL){
                    if(CURR->item == ele){
                        Node* newnode = new Node(item);
                        newnode->next = CURR->next;
                        CURR->next->prev = newnode ;
                        CURR->next = newnode;
                        newnode->prev=CURR;
                        cout<<"Successfully Inserted "<<"\n";
                        return;
                    }
                    CURR=CURR->next;
                }
                if(CURR == NULL){
                    cout<<"Element not found"<<"\n";
                }
        }
    }

    void insertBefore(int ele, int item){
        if(HEAD == NULL){
            cout<<"Linked List is empty \n Use either insertLast or insertBegining to insert first element in LL "<<"\n";
        }else {
                Node* CURR = HEAD;
                if(CURR->item == ele){
                    Node* newnode = new Node(item);
                    newnode->next = HEAD;
                    newnode->prev = NULL;
                    HEAD=newnode;
                    return;
                }else {

                    while(CURR != NULL){
                        if(CURR->next->item == ele){
                            Node* newnode = new Node(item);
                            newnode->next = CURR->next;
                            CURR->next->prev = newnode; 
                            CURR->next = newnode;
                            newnode->prev = CURR;
                            cout<<"Successfully Inserted "<<"\n";
                            return;
                        }
                        CURR=CURR->next;
                    }
                }
                if(CURR == NULL){
                    cout<<"Element not found"<<"\n";
                }
        }
    }

    void deleteLast(){
        if(HEAD == NULL){
            cout<<"Linked list is empty "<<"\n";
        }else {
                Node* CURR = HEAD;
                if(CURR->next == NULL){
                    delete(CURR);
                    HEAD = NULL;
                    cout<<"Successfully Deleted "<<"\n";
                }else {
                    while(CURR->next->next != NULL){
                    CURR=CURR->next;
                    }
                    delete(CURR->next);
                    CURR->next=NULL;
                    cout<<"Successfully Deleted "<<"\n";
                }
                
        }
    }
    void deleteFirst(){
        if(HEAD == NULL){
            cout<<"Linked list is empty "<<"\n";
        }else {
                
                if(HEAD->next == NULL){
                    delete(HEAD);
                    HEAD = NULL;
                    cout<<"Successfully Deleted "<<"\n";
                }else {
                    struct Node* CURR = HEAD;
                    HEAD = CURR->next;
                    CURR->next->prev = NULL;
                    delete(CURR);
                    cout<<"Successfully Deleted "<<"\n";
                }
            
                
        }
    }

    void deleteEle(int ele){
        if(HEAD == NULL){
            cout<<"Linked list is empty "<<"\n";
        }else {
                
                Node* CURR = HEAD;
                if(CURR->item == ele){
                    if(CURR->next == NULL){
                        delete(HEAD);
                        HEAD=NULL;
                        cout<<"Successfully Deleted "<<"\n";
                        return;
                    }else {
                        HEAD = CURR->next;
                        CURR->next->prev = NULL;
                        delete(CURR);
                        cout<<"Successfully Deleted "<<"\n";
                        return;
                    }
                }else {

                    while(CURR != NULL){
                        if(CURR->next->item == ele){
                            if(CURR->next->next == NULL){
                                struct Node* temp = CURR->next;
                                CURR->next=NULL;
                                delete(temp);
                                cout<<"Successfully Deleted "<<"\n";
                                return;
                            }else {
                                struct Node* temp = CURR->next;
                                CURR->next=CURR->next->next;
                                CURR->next->next->prev = CURR;
                                delete(temp);
                                cout<<"Successfully Deleted "<<"\n";
                                return;
                            }
                        }
                        CURR=CURR->next;
                    }
                }
                if(CURR == NULL){
                    cout<<"Element not found"<<"\n";
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
    
    void traverseLastToFirst(){
        Node* CURR = HEAD;

        if(CURR == NULL){
        cout<<" Linked List is empty. Please insert element first"<<"\n";
        }else {
            cout<<"Linked List:- ";
            while(CURR->next != NULL){
                cout<<CURR->item<<" ";
                CURR=CURR->next;
            }
            cout<<CURR->item<<" ";
            cout<<"\n";
            cout<<"Traverse Linked List From Last to First :- ";
            while(CURR != NULL){
                cout<<CURR->item<<" ";
                CURR=CURR->prev;
            }
            cout<<"\n";
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
   int i, item, ele;
   DoubleLinkedList dll;
   while(1){
       cout<<"\n Double Linked List \n 1. insertLast \n 2. insertBegining \n 3. insertAfter \n 4. insertBefore \n 5. deleteLast \n 6. deleteFirst \n 7. deleteEle \n 8. deleteLinkedList \n 9. traverseLastToFirst \n 10. Display \n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  cout<<" Enter element to be insert at last ";
                    cin>>item;
                    dll.insertLast(item);
                    break;
           case 2:  cout<<" Enter element to be insert at begining ";
                    cin>>item;
                    dll.insertBegining(item);
                    break;
           case 3:  cout<<" Enter element to be insert ";
                    cin>>item;
                    cout<<" Enter element After which You want to insert new element ";
                    cin>>ele;
                    dll.insertAfter(ele, item);
                    break;
           case 4:  cout<<" Enter element to be insert ";
                    cin>>item;
                    cout<<" Enter element After which You want to insert new element ";
                    cin>>ele;
                    dll.insertBefore(ele, item);
                    break;
           case 5:  dll.deleteLast();
                    break;
           case 6:  dll.deleteFirst();
                    break;
           case 7:  cout<<" Enter element to be deleted ";
                    cin>>ele;
                    dll.deleteEle(ele);
                    break;
           case 8:  dll.deleteLinkedList();
                    break;
           case 9:  dll.traverseLastToFirst();
                    break;                
           case 10:  dll.printLL();
                    break;       
           default: exit(1);
                    break;
       }

   }

    return 0;
}