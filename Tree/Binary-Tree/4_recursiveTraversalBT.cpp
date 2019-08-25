/**
 *  author:- piyushkumar96
 *  description:- Recursive Method Binary Tree Travesal (inorder, preorder, postorder)
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
        void inorderTraversal(struct Node *node);
        void preorderTraversal(struct Node *node);
        void postorderTraversal(struct Node *node);
        void levelOrderTraversal(struct Node *node);

};

// inorder traversal recursive function
void BinaryTree::inorderTraversal(struct Node *root){
    if(root == NULL){
        return;
    }
     
     inorderTraversal(root->left);
     cout<<root->data<<" ";
     inorderTraversal(root->right);
}

// preorder traversal recursive function
void BinaryTree::preorderTraversal(struct Node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// postorder traversal recursive function
void BinaryTree::postorderTraversal(struct Node *root){
    if(root == NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";

}

// level order Trversal helper function
void printLevelOrderTraversal(struct Node *root, int level){
    if(root == NULL){
        return ;
    }else if (level == 1){
        cout<<root->data<<" ";
    }else if (level > 1) {
        printLevelOrderTraversal(root->left,level - 1);
        printLevelOrderTraversal(root->right, level - 1 );
    }
}

// height of tree
int height(struct Node *root){
    if(root == NULL){
        return 0;
    }else{
        int lh = height(root->left);
        int rh = height(root->right);

        if(lh > rh){
            return lh + 1;
        }else{
            return rh + 1;
        }
    }
}

// level order traversal recursive function
void BinaryTree::levelOrderTraversal(struct Node *root){
   int h = height(root);

   for(int i=1; i<=h; i++){
       printLevelOrderTraversal(root,i);
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
       cout<<"\nBinary Tree \n 1. insert \n 2. Display(inorder) \n 3. Display(preorder) \n 4. Display(postorder) \n 5. Display(levelorder) \n 6. DeleteNode \n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  cout<<" Enter element to insert ";
                    cin>>item;
                    t.insertNode(item);
                    break;

           case 2:  cout<<"Inorder Traversal :- ";
                    t.inorderTraversal(root);
                    break;

           case 3:  cout<<"Preorder Traversal :- ";
                    t.preorderTraversal(root);
                    break;

           case 4:  cout<<"Postorder Traversal :- ";
                    t.postorderTraversal(root);
                    break;

           case 5:  cout<<"levelorder Traversal :- ";
                    t.levelOrderTraversal(root);
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