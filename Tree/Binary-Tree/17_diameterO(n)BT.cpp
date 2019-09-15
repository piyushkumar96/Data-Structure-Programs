/**
 *  author:- piyushkumar96
 *  description:- diameter of Binary Tree
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
        int diameter(struct Node *root);
        

};

// height of BT
int height(struct Node* root, int &dia){
    if(root == NULL){
        return 0;
    }

    int lh = height(root->left, dia);
    int rh = height(root->right, dia);

    // diameter of a tree is nothing but maximum value of  (lh + rh + 1) for each node
    dia = max(dia, 1 + lh + rh);

    return 1 + max(lh, rh);
}

// diameter of BT 
int BinaryTree::diameter(struct Node *root){
    
    // root is NULL then diameter of BT is 0
    if(root == NULL)
        return 0;

    int dia = INT_MIN;
    int h = height(root, dia);

    return dia;
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
       cout<<"\nBinary Tree \n 1. insert \n 2. Display(levelorder) \n 3. diameter of tree \n 4. DeleteNode \n Press any key to Exit \n";
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
                    cout<<"diameter of Tree :- ";
                    cout<<t.diameter(root)<<"\n";
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