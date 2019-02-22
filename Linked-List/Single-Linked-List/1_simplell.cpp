/**
 *  author:- piyushkumar96
 *  description:- Using(malloc) Simple Linked List ( Insertion, Deletion, Reverse, Sorting)
**/
#include<bits/stdc++.h>
using namespace std;

struct simplell {
    int item;
    struct simplell *next;
}*HEAD=NULL;

void insertLast(int item){
  if(HEAD == NULL){
     struct simplell* newnode = (struct simplell*) malloc(sizeof(struct simplell));
     newnode->item=item;
     newnode->next=NULL;
     HEAD=newnode;
     cout<<"Successfully Inserted "<<"\n";
  }else {
        struct simplell* CURR = HEAD;
        while(CURR->next != NULL){
            CURR=CURR->next;
        }
        struct simplell* newnode = (struct simplell*) malloc(sizeof(struct simplell));
        newnode->item=item;
        newnode->next=NULL;
        CURR->next=newnode;
        cout<<"Successfully Inserted "<<"\n";
  }
}
void insertBegining(int item){
  if(HEAD == NULL){
     struct simplell* newnode = (struct simplell*) malloc(sizeof(struct simplell));
     newnode->item=item;
     newnode->next=NULL;
     HEAD=newnode;
     cout<<"Successfully Inserted "<<"\n";
  }else {
        struct simplell* newnode = (struct simplell*) malloc(sizeof(struct simplell));
        newnode->item=item;
        newnode->next=HEAD;
        HEAD=newnode;
        cout<<"Successfully Inserted "<<"\n";
  }
}

void insertAfter(int ele, int item){
  if(HEAD == NULL){
     cout<<"Linked List is empty \n Use either insertLast or insertBegining to insert first element in LL "<<"\n";
  }else {
        struct simplell* CURR = HEAD;
        while(CURR != NULL){
            if(CURR->item == ele){
                struct simplell* newnode = (struct simplell*) malloc(sizeof(struct simplell));
                newnode->item=item;
                newnode->next=CURR->next;
                CURR->next=newnode;
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
        struct simplell* CURR = HEAD;
        if(CURR->item == ele){
            struct simplell* newnode = (struct simplell*) malloc(sizeof(struct simplell));
            newnode->item=item;
            newnode->next=HEAD;
            HEAD=newnode;
        }else {

            while(CURR != NULL){
                if(CURR->next->item == ele){
                    struct simplell* newnode = (struct simplell*) malloc(sizeof(struct simplell));
                    newnode->item=item;
                    newnode->next=CURR->next;
                    CURR->next=newnode;
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
            struct simplell* CURR = HEAD;
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
                struct simplell* CURR = HEAD;
                HEAD = CURR->next;
                delete(CURR);
                cout<<"Successfully Deleted "<<"\n";
            }
        
            
    }
}

void deleteEle(int ele){
    if(HEAD == NULL){
        cout<<"Linked list is empty "<<"\n";
    }else {
            
            struct simplell* CURR = HEAD;
            if(CURR->item == ele){
                if(CURR->next == NULL){
                    delete(HEAD);
                    HEAD=NULL;
                    cout<<"Successfully Deleted "<<"\n";
                    return;
                }else {

                    HEAD = CURR->next;
                    delete(CURR);
                    cout<<"Successfully Deleted "<<"\n";
                    return;
                }
            }else {

                while(CURR != NULL){
                    if(CURR->next->item == ele){
                        if(CURR->next->next == NULL){
                            struct simplell* temp = CURR->next;
                            CURR->next=NULL;
                            delete(temp);
                            cout<<"Successfully Deleted "<<"\n";
                            return;
                        }else {
                            struct simplell* temp = CURR->next;
                            CURR->next=CURR->next->next;
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

void reverseLL(){
    if(HEAD == NULL){
        cout<<"Linked list is empty "<<"\n";
    }else {
        struct simplell* CURR = HEAD, *PREV= NULL, *NEXT=NULL;
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

void printLL(){
    struct simplell* CURR = HEAD;
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

void frontbackSplit(struct simplell* source, struct simplell** frontref, struct simplell** backref){
        struct simplell* slow;
        struct simplell* fast;
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

    struct simplell* sortedMerge(struct simplell* a, struct simplell* b){
        struct simplell* result = NULL;
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
    
    void mergeSort(struct simplell** headref){
        struct simplell* head = *headref;
        struct simplell* a;
        struct simplell* b;
        if((head == NULL) && (head->next == NULL)){
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

int main(){
   int i, item, ele;
   while(1){
       cout<<"\nSimple Linked List \n 1. insertLast \n 2. insertBegining \n 3. insertAfter \n 4. insertBefore \n 5. deleteLast \n 6. deleteFirst \n 7. deleteEle \n 8. reverseLinked List \n 9. Sort Linked List \n 10. Display \n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  cout<<" Enter element to be insert at last ";
                    cin>>item;
                    insertLast(item);
                    break;
           case 2:  cout<<" Enter element to be insert at begining ";
                    cin>>item;
                    insertBegining(item);
                    break;
           case 3:  cout<<" Enter element to be insert ";
                    cin>>item;
                    cout<<" Enter element After which You want to insert new element ";
                    cin>>ele;
                    insertAfter(ele, item);
                    break;
           case 4:  cout<<" Enter element to be insert ";
                    cin>>item;
                    cout<<" Enter element After which You want to insert new element ";
                    cin>>ele;
                    insertBefore(ele, item);
                    break;
           case 5:  deleteLast();
                    break;
           case 6:  deleteFirst();
                    break;
           case 7:  cout<<" Enter element to be deleted ";
                    cin>>ele;
                    deleteEle(ele);
                    break;
           case 8:  reverseLL();
                    break;
           case 9:  sortLL();
                    break;
           case 10: printLL();
                    break;       
           default: exit(1);
                    break;
       }

   }

    return 0;
}