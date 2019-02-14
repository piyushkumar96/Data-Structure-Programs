#include<bits/stdc++.h>
//using namespace std;

struct simplell {
    int item;
    struct simplell *next;
}*HEAD=NULL;

void insertLast(int item){
  if(HEAD == NULL){
     //std::cout<<"Linked list is empty "<<"\n";
     struct simplell* newnode = (struct simplell*) malloc(sizeof(struct simplell));
     newnode->item=item;
     newnode->next=NULL;
     HEAD=newnode;
     std::cout<<"Successfully Inserted "<<"\n";
  }else {
        struct simplell* CURR = HEAD;
        while(CURR->next != NULL){
            CURR=CURR->next;
        }
        struct simplell* newnode = (struct simplell*) malloc(sizeof(struct simplell));
        newnode->item=item;
        newnode->next=NULL;
        CURR->next=newnode;
        std::cout<<"Successfully Inserted "<<"\n";
  }
}
void insertBegining(int item){
  if(HEAD == NULL){
     //std::cout<<"Linked list is empty "<<"\n";
     struct simplell* newnode = (struct simplell*) malloc(sizeof(struct simplell));
     newnode->item=item;
     newnode->next=NULL;
     HEAD=newnode;
     std::cout<<"Successfully Inserted "<<"\n";
  }else {
        struct simplell* newnode = (struct simplell*) malloc(sizeof(struct simplell));
        newnode->item=item;
        newnode->next=HEAD;
        HEAD=newnode;
        std::cout<<"Successfully Inserted "<<"\n";
  }
}

void insertAfter(int ele, int item){
  if(HEAD == NULL){
     std::cout<<"Linked List is empty \n Use either insertLast or insertBegining to insert first element in LL "<<"\n";
  }else {
        struct simplell* CURR = HEAD;
        while(CURR != NULL){
            if(CURR->item == ele){
                struct simplell* newnode = (struct simplell*) malloc(sizeof(struct simplell));
                newnode->item=item;
                newnode->next=CURR->next;
                CURR->next=newnode;
                std::cout<<"Successfully Inserted "<<"\n";
            }
            CURR=CURR->next;
        }
        if(CURR == NULL){
            std::cout<<"Element not found"<<"\n";
        }
  }
}

void insertBefore(int ele, int item){
  if(HEAD == NULL){
     std::cout<<"Linked List is empty \n Use either insertLast or insertBegining to insert first element in LL "<<"\n";
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
                    std::cout<<"Successfully Inserted "<<"\n";
                }
                CURR=CURR->next;
            }
        }
        if(CURR == NULL){
            std::cout<<"Element not found"<<"\n";
        }
  }
}

void deleteLast(){
    if(HEAD == NULL){
        std::cout<<"Linked list is empty "<<"\n";
    }else {
            struct simplell* CURR = HEAD;
            if(CURR->next == NULL){
                HEAD = NULL;
                std::cout<<"Successfully Deleted "<<"\n";
            }else {
                while(CURR->next->next != NULL){
                CURR=CURR->next;
                }
                CURR->next=NULL;
                std::cout<<"Successfully Deleted "<<"\n";
            }
            
    }
}
void deleteFirst(){
    if(HEAD == NULL){
        std::cout<<"Linked list is empty "<<"\n";
    }else {
            
            if(HEAD->next == NULL){
                HEAD = NULL;
                std::cout<<"Successfully Deleted "<<"\n";
            }else {
                HEAD=HEAD->next;
                std::cout<<"Successfully Deleted "<<"\n";
            }
        
            
    }
}

void deleteEle(int ele){
    if(HEAD == NULL){
        std::cout<<"Linked list is empty "<<"\n";
    }else {
            
            struct simplell* CURR = HEAD;
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
                std::cout<<"Element not found"<<"\n";
            }
        
            
    }
}

void reverseLL(){
    if(HEAD == NULL){
        std::cout<<"Linked list is empty "<<"\n";
    }else {
        struct simplell* CURR = HEAD, *PREV= NULL, *NEXT=NULL;
        while(CURR != NULL){
            NEXT=CURR->next;
            CURR->next=PREV;
            PREV=CURR;
            CURR=NEXT;            
        }  
        HEAD=PREV;   
        std::cout<<" Linked List is reversed "<<"\n";              
    }
}

void printLL(){
    struct simplell* CURR = HEAD;
    if(CURR == NULL){
        std::cout<<" Linked List is empty. Please insert element first"<<"\n";
    }else {
        std::cout<<"Linked List:- ";
        while(CURR != NULL){
            std::cout<<CURR->item<<" ";
            CURR=CURR->next;
        }
        std::cout<<"\n";
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
        std::cout<<" Sorted Linked List :- ";
        printLL();
    }

int main(){
   int i, item, ele;
   while(1){
       std::cout<<"\nSimple Linked List \n 1. insertLast \n 2. insertBegining \n 3. insertAfter \n 4. insertBefore \n 5. deleteLast \n 6. deleteFirst \n 7. deleteEle \n 8. reverseLinked List \n 9. Sort Linked List \n 10. Display \n Press any key to Exit \n";
       std::cin>>i;
       switch (i)
       {
           case 1:  std::cout<<" Enter element to be insert at last ";
                    std::cin>>item;
                    insertLast(item);
                    break;
           case 2:  std::cout<<" Enter element to be insert at begining ";
                    std::cin>>item;
                    insertBegining(item);
                    break;
           case 3:  std::cout<<" Enter element to be insert ";
                    std::cin>>item;
                    std::cout<<" Enter element After which You want to insert new element ";
                    std::cin>>ele;
                    insertAfter(ele, item);
                    break;
           case 4:  std::cout<<" Enter element to be insert ";
                    std::cin>>item;
                    std::cout<<" Enter element After which You want to insert new element ";
                    std::cin>>ele;
                    insertBefore(ele, item);
                    break;
           case 5:  deleteLast();
                    break;
           case 6:  deleteFirst();
                    break;
           case 7:  std::cout<<" Enter element to be deleted ";
                    std::cin>>ele;
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