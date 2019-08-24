/**
 *  author:- piyushkumar96
 *  description:- Iterative Method Binary Tree Travesal (inorder, preorder, postorder)
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

// preorder traversal recursive function
void BinaryTree::preorderTraversal(struct Node *root){
    if(root == NULL){
        return;
    }
    
    stack<Node *> st;
    st.push(root);

    Node *nd = st.top();

    while(!st.empty()){
        struct Node *tmp = st.top();
        st.pop();

        cout<<tmp->data<<" ";
        if(tmp->right)
            st.push(tmp->right);
        
        if(tmp->left)
            st.push(tmp->left);
    }
}

// postorder traversal recursive function
void BinaryTree::postorderTraversal(struct Node *root){
    if(root == NULL){
        return;
    }
    
    stack<Node *> st;

    struct Node *tmp = root;
    do{
        
        while(tmp != NULL){
            if(tmp->right){
                st.push(tmp->right);
            }
            st.push(tmp);
            tmp = tmp->left;
        }
        tmp = st.top();
        st.pop();

        // checking that currents right is equal to top of stack
        if(tmp->right && tmp->right == st.top()){
            st.pop();
            st.push(tmp);
            tmp = tmp->right;
        }else{
            cout<<tmp->data<<" ";
            tmp = NULL;
        }

    } while( !st.empty());

}

// level order traversal recursive function
void BinaryTree::levelOrderTraversal(struct Node *root){
   
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