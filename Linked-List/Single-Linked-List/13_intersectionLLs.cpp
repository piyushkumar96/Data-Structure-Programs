/**
 *  author:- piyushkumar96
 *  description:- intersection of LL  L1==> 1->2->3->4->5 and L2==> 2->4->6->8 intersection ILL==> 2->6
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
} *HEADA, *HEADB;

struct LinkedList {
    
    LinkedList(){
        HEADA=NULL;
        HEADB=NULL;
    }
    void insertA(int item){
        if(HEADA == NULL){
            Node* newnode = new Node(item);
            HEADA=newnode;
            cout<<"Successfully Inserted "<<"\n";
        }else {
                Node* CURR = HEADA;
                while(CURR->next != NULL){
                    CURR=CURR->next;
                }
                Node* newnode = new Node(item);
                CURR->next=newnode;
                cout<<"Successfully Inserted "<<"\n";
        }
    }

    void insertB(int item){
        if(HEADB == NULL){
            Node* newnode = new Node(item);
            HEADB=newnode;
            cout<<"Successfully Inserted "<<"\n";
        }else {
                Node* CURR = HEADB;
                while(CURR->next != NULL){
                    CURR=CURR->next;
                }
                Node* newnode = new Node(item);
                CURR->next=newnode;
                cout<<"Successfully Inserted "<<"\n";
        }
    }    

    // recursive method of Intersection of two LL
    struct Node* recursiveIntersection(struct Node *a, struct Node *b){
        if(HEADA == NULL){
            cout<<"Linked List A is empty "<<"\n";
        }else if(HEADB == NULL){
            cout<<"Linked List B is empty "<<"\n";
        }else{
            if(a == NULL || b == NULL)
                return NULL;

            if(a->item > b->item){
                return recursiveIntersection(a,b->next);
            }    
            if(a->item < b->item){
                return recursiveIntersection(a->next, b);
            }
              
            struct Node *temp = new Node(a->item);
            temp->next = recursiveIntersection(a->next, b->next);
            return temp;
        }
    }

    void push(struct Node **head_ref, int new_data){
        struct Node *newnode = new Node(new_data);
        newnode->next = *head_ref;
        *head_ref = newnode;
    }

    // iterative method of Intersection of two LL
    void iterativeIntersection(struct Node *a, struct Node *b){
        if(HEADA == NULL){
            cout<<"Linked List A is empty "<<"\n";
        }else if(HEADB == NULL){
            cout<<"Linked List B is empty "<<"\n";
        }else{
            struct Node* result = NULL;
            struct Node** lastPtrRef = &result;
            
            while(a != NULL && b != NULL){
                if(a->item == b->item){
                    
                    push(lastPtrRef,a->item);
                    lastPtrRef = &((*lastPtrRef)->next);
                    //struct Node *newnode = new Node(a->item);
                    //newnode->next = result;
                    //result = newnode;
                    a = a->next;
                    b = b->next;                    
                }else if(a->item > b->item){
                    b = b->next;
                }else if(a->item < b->item){
                    a = a->next;
                }
            }

            cout<<" The Intersected ";
            printLL(result);
        }
    }

    void deleteLinkedList(struct Node **head_ref){
        if(*head_ref == NULL){
            cout<<"Linked list is empty "<<"\n";
        }else{
            Node* CURR = *head_ref;
            Node* NEXT ;
            while(CURR != NULL){
                NEXT = CURR->next;
                delete(CURR);
                CURR = NEXT;
            }
            *head_ref = NULL;
            cout<<"Linked List is Successfully deleted"<<"\n";
        }
    }

    void printLL(struct Node *head_ref){
        Node* CURR = head_ref;
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
       cout<<"\nSimple Linked List \n 1. insert LL A \n 2. insert LL B \n 3. iterativeIntersection \n 4. recursive Intersection \n 5. delete LL A  \n 6. delete LL B \n 7. Display LL A \n 8. Display LL B \n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  cout<<" Enter element to insert in LL A(integer only)";
                    cin>>item;
                    ll.insertA(item);
                    break;
           case 2:  cout<<" Enter element to insert in LL B(integer only)";
                    cin>>item;
                    ll.insertB(item);
                    break;         

           case 3:  ll.iterativeIntersection(HEADA, HEADB);
                    break;

           case 4:  cout<<" The Intersected ";
                    ll.printLL(ll.recursiveIntersection(HEADA, HEADB));
                    break;

           case 5:  ll.deleteLinkedList(&HEADA);
                    break;                    

           case 6:  ll.deleteLinkedList(&HEADB);
                    break; 

           case 7:  ll.printLL(HEADA);
                    break; 
           case 8:  ll.printLL(HEADB);
                    break;        

           default: exit(1);
                    break;
       }

   }

    return 0;
}