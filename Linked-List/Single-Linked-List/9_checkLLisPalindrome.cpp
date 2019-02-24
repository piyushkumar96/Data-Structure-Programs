/**
 *  author:- piyushkumar96
 *  description:- Check Linked List is Palindrome (Recursive and Iterative)
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

    void recursiveReverseLL(struct Node ** head_ref){

        struct Node* first ;
        struct Node* rest;
        if(head_ref == NULL)
            return;
        first = *head_ref;
        rest = first->next;

        if(rest == NULL){
            return;
        }
        recursiveReverseLL(&rest);
        first->next->next=first;
        first->next = NULL;

        *head_ref = rest;
    }

    bool compareList(struct Node *List1, struct Node *List2){
        
        struct Node *temp1 = List1;
        struct Node *temp2 = List2;

        while( temp1 && temp2){
            if(temp1->item != temp2->item){
                return 0;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }    
        
        if((temp1 == NULL) && (temp2 == NULL)){
            return 1;
        }

        return 0;
    }

    void iterativePalindrome(){
        if(HEAD == NULL){
            cout<<"Linked List is empty "<<"\n";
        }else if(HEAD->next == NULL){
            cout<<"Linked List is palindrome \n";
        }else {
            struct Node *slow_ptr = HEAD;
            struct Node *fast_ptr = HEAD;
            struct Node *prev_slow_ptr = HEAD;
            struct Node *second_half = HEAD;
            struct Node *mid_ptr = NULL;
            bool result = false;

            while(fast_ptr != NULL && fast_ptr->next != NULL){
                /*We need previous of the slow_ptr for linked lists  with odd elements */
                prev_slow_ptr = slow_ptr;
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next->next;
            }


            /* fast_ptr would become NULL when there are even elements in list.  
           And not NULL for odd elements. We need to skip the middle node  
           for odd case and store it somewhere so that we can restore the 
           original list*/
            if(fast_ptr != NULL){
                mid_ptr = slow_ptr;
                slow_ptr = slow_ptr->next;
            }

            second_half = slow_ptr;
            prev_slow_ptr->next = NULL;  // NULL terminate first half

             //reverse the second half and compare it with first half 
            recursiveReverseLL(&second_half);
            result = compareList(HEAD ,second_half);

            if(result == 1){
                cout<<"Linked List is palindrome \n";
            }else {
                cout<<"Linked List is not palindrome \n";
            }
            
            //reverse the second half for making back to original list 
            recursiveReverseLL(&second_half);

            // If there was a mid node (odd size case) which was not part of either first half or second half. 
            if(mid_ptr != NULL){
                prev_slow_ptr->next = mid_ptr;
            }else {
                prev_slow_ptr->next = slow_ptr;
            }

        }
    }

    bool recursivePalindrome(struct Node **left , struct Node *right){

        /* stop recursion when right becomes NULL */
        if(right == NULL){
            return true;
        }

        /* If sub-list is not palindrome then no need to  check for current left and right, return false */
        bool res1 = recursivePalindrome(left, right->next);
        if(res1 == false){
            return false;
        }

        bool res2 = ((*left)->item == right->item);
        (*left) = (*left)->next;

        return res2;
    }
    
    void isRecPalindrome(struct Node* head_ref){
        bool res = recursivePalindrome(&head_ref, head_ref);
        if(res == 1){
            cout<<"Linked List is palindrome \n";
        }else {
            cout<<"Linked List is not palindrome \n";
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
       cout<<"\nSimple Linked List \n 1. insert \n 2. iterative Method Palindrome \n 3. recursive Method Palindrome \n 4. delete Linked List \n 5. Display \n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  cout<<" Enter element to insert (integer only)";
                    cin>>item;
                    ll.insert(item);
                    break;

           case 2:  ll.iterativePalindrome();
                    break;

           case 3:  ll.isRecPalindrome(HEAD);
                    break;

           case 4:  ll.deleteLinkedList();
                    break;  

           case 5:  ll.printLL();
                    break;     

           default: exit(1);
                    break;
       }

   }

    return 0;
}