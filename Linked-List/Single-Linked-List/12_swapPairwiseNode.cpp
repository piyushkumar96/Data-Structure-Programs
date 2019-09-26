/**
 *  author:- piyushkumar96
 *  description:- swapping pairwise nodes 1->2->3->4->5 to 2->1->4->3->5 (Recursive and Iterative)
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

    void swapData(struct Node **a, struct Node **b){
        int temp = (*a)->item;
        (*a)->item = (*b)->item;
        (*b)->item = temp;
    }

    // recursive method by swaping datas of Nodes
    void recursivePairwiseSwap(struct Node *head_ref){

        if(HEAD == NULL){
            cout<<"Linked List is empty "<<"\n";
        }else{
            if((head_ref == NULL) || (head_ref->next == NULL) ){
                return;                   
            }
            swapData(&head_ref, &(head_ref->next));
            recursivePairwiseSwap(head_ref->next->next);
        }
    }

    // recursive method by swaping linkes
    Node* recursivePairwiseSwapLink(struct Node *head_ref){
        
        if((head_ref == NULL) || (head_ref->next == NULL) ){
            return head_ref;                   
        }
       
        struct Node* remaining = head_ref->next->next;

        // Change head 
        struct Node* new_head = head_ref->next;

        // Change next of second node 
        head_ref->next->next = head_ref;

        // Recur for remaining list and change next of head 
        head_ref->next = recursivePairwiseSwapLink(remaining);

         // Return new head of modified list 
        return new_head;        
    }
    
    // iterative method by swaping datas of Nodes
    void iterativePairwiseSwap(){
        // if LL is empty or only one node then no need to swap
        if(HEAD == NULL || HEAD->next == NULL)
            return;

        struct Node *temp = HEAD;
        while(temp != NULL && temp->next != NULL){
            swapData(&temp , &(temp->next));
            temp = temp->next->next;            
        }
        
    }

        // iterative method by swaping links
    void iterativePairwiseSwapLink() {

        // if LL is empty or only one node then no need to swap
        if(HEAD == NULL || HEAD->next == NULL)
            return;
    
        // swapping the first two nodes of LL
        struct Node *curr = HEAD->next->next;
        struct Node *prev = HEAD;
        HEAD = HEAD->next;
        HEAD->next = prev;
        
        // swap other nodes of LL
        while(curr != NULL && curr->next != NULL){
            
            prev->next = curr->next;
            prev = curr;
            
            struct Node *temp = curr->next->next;
            curr->next->next = curr;
            curr = temp;
        }

        prev->next = curr;
        
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
       cout<<"\nSimple Linked List \n 1. insert \n 2. iterative Pairwise Swap \n 3. recursive Pairwise Swap \n 4. iterative Pairwise Link Swap \n 5. recursive Pairwise Link Swap  \n 6. delete Linked List \n 7. Display \n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  cout<<" Enter element to insert (integer only)";
                    cin>>item;
                    ll.insert(item);
                    break;

           case 2:  ll.iterativePairwiseSwap();
                    cout<<"After pairwise swapping the  ";
                    ll.printLL();
                    break;

           case 3:  ll.recursivePairwiseSwap(HEAD);
                    cout<<"After pairwise swapping the  ";
                    ll.printLL();
                    break;

           case 4:  ll.iterativePairwiseSwapLink();
                    cout<<"After pairwise swapping the  ";
                    ll.printLL();
                    break;                    

           case 5:  HEAD = ll.recursivePairwiseSwapLink(HEAD);
                    cout<<"After pairwise swapping the  ";
                    ll.printLL();
                    break;

           case 6:  ll.deleteLinkedList();
                    break;  

           case 7:  ll.printLL();
                    break;     

           default: exit(1);
                    break;
       }

   }

    return 0;
}