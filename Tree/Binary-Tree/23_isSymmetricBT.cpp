/**
 *  author:- piyushkumar96
 *  description:- Check symmetricity of Binary Tree
 *  TimeComplexity:- O(n)
**/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
}*root;

class BinaryTree {
   
    public:
        BinaryTree(){
            root = NULL;
        }
        queue<struct Node *> q;
        void insertNode(int item);
        Node* deleteNode(struct Node *root, int item);
        void delDeepestNode(struct Node *root, struct Node *node);
        void levelorderTraversal(struct Node *root);
        bool symmetric(struct Node *root);
        

};

// util function for checking symmerticity
bool isMirror(struct Node *root1, struct Node *root2){
    if((root1 == NULL) && (root2 == NULL))
        return true;
    if(root1 && root2 && root1->data == root2->data){
        return (isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left));
    }
    return false;
}

// Symmetricity of BT 
bool BinaryTree::symmetric(struct Node *root){
    
    // root is NULL then diameter of BT is 0
    if(root == NULL)
        return true;

     return isMirror(root, root);  
}

// level order traversal iterative function
void BinaryTree::levelorderTraversal(struct Node *root){
   
   if(root == NULL){
       cout<<"Tree is Empty \n";
       return ;
   }
   queue<Node *> qu;
   qu.push(root);
   while(!qu.empty()){
       struct Node *tmp = qu.front();
       qu.pop();
       cout<<tmp->data<<" ";
       if(tmp->left){
           qu.push(tmp->left);
       }
       if(tmp->right){
           qu.push(tmp->right);
       }
   }
     
}

// insert function
void BinaryTree::insertNode(int item){
     Node *newnode = new Node(item);
     if(root == NULL){
         root=newnode;
     }else{
         Node *temp = q.front();
         if(!temp->left){
             temp->left = newnode;
         }else{
             temp->right = newnode;
             q.pop();
         }
     }
     q.push(newnode);
}

// delete helper function
void BinaryTree::delDeepestNode(struct Node *root, struct Node *dnode){
    struct Node *tmpNode;
    queue<Node *> qu;
    qu.push(root);

    while(!qu.empty()){
        tmpNode = qu.front();
        qu.pop();
        if(tmpNode->left){
            if(tmpNode->left == dnode){
                tmpNode->left=NULL;
                delete(dnode);
                return;
            }else{
                qu.push(tmpNode->left);
            }
        }
        if(tmpNode->right){
            if(tmpNode->right == dnode){
                tmpNode->right=NULL;
                delete(dnode);
                return;
            }else {
                qu.push(tmpNode->right);
            }
        }
    }
}

// delete function 
struct Node* BinaryTree::deleteNode(struct Node *root, int item){
    struct Node *delNode = NULL, *tmpNode; 
    queue< Node *> qu;
    
    if(root == NULL){
        cout<<" Tree is empty "<<"\n";
        return NULL;
    }else if((root->right == NULL) && (root->left == NULL) ){
          if(root->data == item){
              delNode = root;
              delete(delNode);
              return NULL;
          }
          return root;
    }
    
    qu.push(root);
    while(!qu.empty()){
        tmpNode = qu.front();
        qu.pop();

        if(tmpNode->data == item){
            delNode = tmpNode;
        }
        if(tmpNode->left){
            qu.push(tmpNode->left);
        }
        
        if(tmpNode->right){
            qu.push(tmpNode->right);
        }
        
    }
   
    if(tmpNode){
        int temp = tmpNode->data;
        delDeepestNode(root, tmpNode);
        delNode->data = temp;
    }
    return root;
}


int main(){

   //ios::sync_with_stdio(false);
   //cin.tie(0);
   int i, n, item;
   BinaryTree t;
   
   while(1){
       cout<<"\nBinary Tree \n 1. insert \n 2. Display(levelorder) \n 3. Symmetricity of tree \n 4. DeleteNode \n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  cout<<" Enter element to insert ";
                    cin>>item;
                    t.insertNode(item);
                    break;

           case 2:  cout<<"Levelorder Traversal :- ";
                    t.levelorderTraversal(root);
                    break;

           case 3:  
                    cout<<"Symmetricity of Tree :- ";
                    cout<<t.symmetric(root)<<"\n";
                    break;

           case 4:  cout<<" Enter element to be deleted ";
                    cin>>item;
                    root = t.deleteNode(root,item);
                    break;                                                 

           default: exit(1);
                    break;
       }

   }

    return 0;
}