/**
 *  author:- piyushkumar96
 *  description:- Nth node of inorder traversal of Binary Tree
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
        void nthNodeInorderItr(struct Node *node,int n);
        void nthNodeInorderRec(struct Node *root,int n);

};


// nth node of inorder iterative traversal 
void BinaryTree::nthNodeInorderItr(struct Node *root, int n){
    if((root == NULL) || (n <= 0)){
        return;
    }
    
    int count=0;
    stack<Node *> st;
    Node *nd = root;
    bool flag = false;
    while(nd != NULL || !st.empty()){
        
        // go to left end and simultaneously save in stack
        while(nd != NULL){
            st.push(nd);
            nd = nd->left;
        }
        nd = st.top();
        st.pop();
        count++;
        if(count == n){
            flag=true;
            cout<<nd->data<<" ";
            break;
        }

        // traverse the right side of tree
        nd = nd->right;
    }
      
    if(flag == false){
        cout<<"Enter the number is not possible \n";
    }
}

// inorder traversal recursive function
void BinaryTree::nthNodeInorderRec(struct Node *root,int n){
    static int count=0;
    if((root == NULL) || (n<=0)){
        return;
    }
        if(count <= n){
            nthNodeInorderRec(root->left,n);
            count++;
            if(count == n){
                cout<<root->data<<" ";
            }
            nthNodeInorderRec(root->right,n);
        }
}

// inorder traversal iterative function
void BinaryTree::inorderTraversal(struct Node *root){
    if(root == NULL){
        return;
    }

    stack<Node *> st;
    Node *nd = root;

    while(nd != NULL || !st.empty()){
        
        // go to left end and simultaneously save in stack
        while(nd != NULL){
            st.push(nd);
            nd = nd->left;
        }
        nd = st.top();
        st.pop();
        cout<<nd->data<<" ";

        // traverse the right side of tree
        nd = nd->right;
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
       cout<<"\nBinary Tree \n 1. insert \n 2. Display(inorder) \n 3. Nth node of inorder itr traversal \n 4. Nth node of inorder rec traversal \n 5. DeleteNode \n Press any key to Exit \n";
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

           case 3:  cout<<" Enter value of n ";
                    cin>>item;
                    cout<<"Nth node of inorder iterative Traversal :- ";
                    t.nthNodeInorderItr(root,item);
                    break;

           case 4:  cout<<" Enter value of n ";
                    cin>>item;
                    cout<<"Nth node of inorder recursive Traversal :- ";
                    t.nthNodeInorderRec(root,item);
                    break;

           case 5:  cout<<" Enter element to be deleted ";
                    cin>>item;
                    root = t.deleteNode(root,item);
                    break;                                                 

           default: exit(1);
                    break;
       }

   }

    return 0;
}