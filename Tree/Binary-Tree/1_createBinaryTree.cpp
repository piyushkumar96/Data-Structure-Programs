/**
 *  author:- piyushkumar96
 *  description:- Binary Tree Creation
**/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int item;
    struct Node* left;
    struct Node* right;
    Node(int item){
        this->item=item;
        this->left=NULL;
        this->right=NULL;
    }
};

struct Tree {
    Node* root;
    //this is used storing nodes whose left or right child is empty
    queue<Node*> q;

    Tree(){
        root=NULL;
    }

    //inserting the new node in tree
    void insertNode(int item){

        Node* newnode = new Node(item);
        if(root == NULL){
            root=newnode;
        }else if(q.front()->left == NULL){
            // The left child of the current Node is used if it is available. 
            q.front()->left=newnode;
        }else{
            // The right child of the current Node is used 
            // if it is available. Since the left child of this 
            // node has already been used, the Node is popped 
            // from the queue after using its right child.
            q.front()->right=newnode;
            q.pop();
        }

        // Whenever a new Node is added to the tree, its 
        // address is pushed into the queue. 
        // So that its children Nodes can be used later. 
        q.push(newnode);
    }

    //display the nodes in levelorder
    void levelorder(){
        
        if(root == NULL){
            cout<<"Tree is empty"<<"\n";
        }else{
            queue<Node*> n;
            n.push(root);

            while(!n.empty()){
                cout<<n.front()->item<<" ";
                if(n.front()->left != NULL){
                    n.push(n.front()->left);
                }
                if(n.front()->right != NULL){
                    n.push(n.front()->right);
                }
                n.pop();
            }
        }
    }
    
};

int main(){
   //ios::sync_with_stdio(false);
   //cin.tie(0);
   int i, n, item;
   Tree t;
   while(1){
       cout<<"\nBinary Tree \n 1. insert \n 2. Display(levelorder) \n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  cout<<" Enter element to insert ";
                    cin>>item;
                    t.insertNode(item);
                    break;

           case 2:  t.levelorder();
                    break;     

           default: exit(1);
                    break;
       }

   }

    return 0;
}