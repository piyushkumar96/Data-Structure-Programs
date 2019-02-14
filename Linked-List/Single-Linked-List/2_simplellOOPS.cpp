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
    void insertLast(int item){
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
    void insertBegining(int item){
        if(HEAD == NULL){
            Node* newnode = new Node(item);
            HEAD=newnode;
            cout<<"Successfully Inserted "<<"\n";
        }else {
                Node* newnode = new Node(item);
                newnode->next=HEAD;
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
                        newnode->next=CURR->next;
                        CURR->next=newnode;
                        cout<<"Successfully Inserted "<<"\n";
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
                    newnode->next=HEAD;
                    HEAD=newnode;
                }else {

                    while(CURR != NULL){
                        if(CURR->next->item == ele){
                            Node* newnode = new Node(item);
                            newnode->next=CURR->next;
                            CURR->next=newnode;
                            cout<<"Successfully Inserted "<<"\n";
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
                    HEAD = NULL;
                    cout<<"Successfully Deleted "<<"\n";
                }else {
                    while(CURR->next->next != NULL){
                    CURR=CURR->next;
                    }
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
                    HEAD = NULL;
                    cout<<"Successfully Deleted "<<"\n";
                }else {
                    HEAD=HEAD->next;
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
                        HEAD=NULL;
                    }else {
                        HEAD=HEAD->next;
                    }
                }else {

                    while(CURR != NULL){
                        if(CURR->next->item == ele){
                            if(CURR->next->next == NULL){
                                CURR->next=NULL;
                            }else {
                                CURR->next=CURR->next->next;
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
                free(CURR);
                CURR = NEXT;
            }
            HEAD = NULL;
            cout<<"Linked List is Successfully deleted"<<"\n";
        }
    }

    void reverseLL(){
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

    void frontbackSplit(struct Node* source, struct Node** frontref, struct Node** backref){
        struct Node* slow;
        struct Node* fast;
        slow = source;
        fast = source->next;

        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                slow = slow->next;
                fast = fast->next;
            }   
        }

        *frontref = source;
        *backref = slow->next;
        slow->next = NULL;
    }

    struct Node* sortedMerge(struct Node* a, struct Node* b){
        struct Node* result = NULL;
        if(a == NULL){
            return(b);
        }else if(b == NULL){
            return(a);
        }

        if(a->item <= b->item){
            result = a;
            result->next = sortedMerge(a->next, b);
        }else{
            result = b;
            result->next = sortedMerge(a, b->next);
        }

        return(result);
    }
    
    void mergeSort(struct Node** headref){
        struct Node* head = *headref;
        struct Node* a;
        struct Node* b;
        if((head == NULL) || (head->next == NULL)){
        return;
        }

        frontbackSplit(head, &a, &b);
        mergeSort(&a);
        mergeSort(&b);
        
        *headref = sortedMerge(a, b);
        
    }

    void sortLL(){
        mergeSort(&HEAD); 
        cout<<" Sorted Linked List :- ";
        printLL();
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
       cout<<"\nSimple Linked List \n 1. insertLast \n 2. insertBegining \n 3. insertAfter \n 4. insertBefore \n 5. deleteLast \n 6. deleteFirst \n 7. deleteEle \n 8. reverseLinkedList \n 9. deleteLinkedList \n 10. sortLinkedList \n 11. Display \n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  cout<<" Enter element to be insert at last ";
                    cin>>item;
                    ll.insertLast(item);
                    break;
           case 2:  cout<<" Enter element to be insert at begining ";
                    cin>>item;
                    ll.insertBegining(item);
                    break;
           case 3:  cout<<" Enter element to be insert ";
                    cin>>item;
                    cout<<" Enter element After which You want to insert new element ";
                    cin>>ele;
                    ll.insertAfter(ele, item);
                    break;
           case 4:  cout<<" Enter element to be insert ";
                    cin>>item;
                    cout<<" Enter element After which You want to insert new element ";
                    cin>>ele;
                    ll.insertBefore(ele, item);
                    break;
           case 5:  ll.deleteLast();
                    break;
           case 6:  ll.deleteFirst();
                    break;
           case 7:  cout<<" Enter element to be deleted ";
                    cin>>ele;
                    ll.deleteEle(ele);
                    break;
           case 8:  ll.reverseLL();
                    break;
           case 9:  ll.deleteLinkedList();
                    break;
           case 10:  ll.sortLL();
                    break;
           case 11:  ll.printLL();
                    break;       
           default: exit(1);
                    break;
       }

   }

    return 0;
}