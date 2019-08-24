/**
 *  author:- piyushkumar96
 *  description:- Binary Tree Deletion
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
} *root;

struct Tree { 
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
            queue<struct Node*> n;
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

    //display the nodes in inorder
    void inorder(struct Node* node){
        if(root == NULL){
            cout<<"Tree is empty"<<"\n";
        }else if(node == NULL){
            return;
        }else{
            inorder(node->left);
            cout<<node->item<<" ";
            inorder(node->right);
        }
    }
    
    //display the nodes in preorder
    void preorder(struct Node* node){
        if(root == NULL){
            cout<<"Tree is empty"<<"\n";
        }else if(node == NULL){
            return;
        }else{
            inorder(node->left);
            inorder(node->right);
            cout<<node->item<<" ";
        }
    }

    //display the node in postorder
    void postorder(struct Node* node){
        if(root == NULL){
            cout<<"Tree is empty"<<"\n";
        }else if(node == NULL){
            return;
        }else{
            cout<<node->item<<" ";
            inorder(node->left);
            inorder(node->right);        
        }
    }

    //function to delete the deepest node in tree
    void deleteDeepestNode(struct Node* root, struct Node* dnode){
        queue<struct Node*> q;
        q.push(root);

        //doing the level order traversal until last node
        struct Node* temp;
        while(!q.empty()){
            temp = q.front();
            q.pop();

            if(temp->right){
                if(temp->right == dnode){
                    temp->right = NULL;
                    delete(dnode);
                    return;
                }else{
                    q.push(temp->right);
                }
            }

            if(temp->left){
                if(temp->left == dnode){
                    temp->left = NULL;
                    delete(dnode);
                    return;
                }else{
                    q.push(temp->left);
                }
            } 
        }
    }

    //delete the node 
   struct Node * deleteNode(struct Node* node, int key){

        if(root == NULL){
            cout<<"Tree is empty"<<"\n";
            return NULL;
        }else if((node->left == NULL) && (node->right == NULL)){     // when single node in tree left for deletion
            delete(node);
            return NULL;
        }else {

            queue<struct Node*> q;
            q.push(node);

            struct Node *temp ;
            struct Node *delnode = NULL;
            while(!q.empty()){

                temp = q.front();
                q.pop();

                if(temp->item == key){
                    delnode = temp;
                }

                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }
            }

            cout<<"Levelorder Traversal Before Deletion:- ";
            levelorder();
            cout<<"\n";
            int x = temp->item;
            deleteDeepestNode(root,temp);
            delnode->item=x;

            cout<<"Levelorder Traversal After Deletion:- ";
            levelorder();

            return root;
        }
    }

};

int main(){
   //ios::sync_with_stdio(false);
   //cin.tie(0);
   int i, n, item;
   Tree t;
   while(1){
       cout<<"\nBinary Tree \n 1. insert \n 2. Display(inorder) \n 3. Display(preorder) \n 4. Display(postorder) \n 5. Display(levelorder) \n 6. DeleteNode \n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  cout<<" Enter element to insert ";
                    cin>>item;
                    t.insertNode(item);
                    break;

           case 2:  cout<<"Inorder Traversal :- ";
                    t.inorder(root);
                    break;

           case 3:  cout<<"Preorder Traversal :- ";
                    t.preorder(root);
                    break;

           case 4:  cout<<"Postorder Traversal :- ";
                    t.postorder(root);
                    break;

           case 5:  cout<<"levelorder Traversal :- ";
                    t.levelorder();
                    break;

           case 6:  cout<<" Enter element to be deleted ";
                    cin>>item;
                     root = t.deleteNode(root,item);
                    
                    break;                                                 

           default: exit(1);
                    break;
       }

   }

    return 0;
}