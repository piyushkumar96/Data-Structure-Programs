/**
 *  author:- piyushkumar96
 *  description:- Check identicity of Binary Trees
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
}*root1, *root2;

class BinaryTree {
   
    public:
        BinaryTree(){
            root1 = NULL;
            root2 = NULL;
        }
        queue<struct Node *> q1, q2;
        void insertNode1(int item);
        void insertNode2(int item);
        Node* deleteNode(struct Node *root, int item);
        void delDeepestNode(struct Node *root, struct Node *node);
        void levelorderTraversal(struct Node *root);
        bool checkIdentical(struct Node *root1, struct Node *root2);
        

};

// Check identicity of BTs
bool BinaryTree::checkIdentical(struct Node *root1, struct Node *root2){
    
    // if both roots are NULL
    if((root1 == NULL) && (root2 == NULL))
        return true;

    if( root1 != NULL && root2 != NULL){
        return (root1->data == root2->data) && checkIdentical(root1->left, root2->left) && checkIdentical(root1->right, root2->right);
    }

    return false;
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
void BinaryTree::insertNode1(int item){
     Node *newnode = new Node(item);
     if(root1 == NULL){
         root1=newnode;
     }else{
         Node *temp = q1.front();
         if(!temp->left){
             temp->left = newnode;
         }else{
             temp->right = newnode;
             q1.pop();
         }
     }
     q1.push(newnode);
}

// insert function for second tree
void BinaryTree::insertNode2(int item){
     Node *newnode = new Node(item);
     if(root2 == NULL){
         root2=newnode;
     }else{
         Node *temp = q2.front();
         if(!temp->left){
             temp->left = newnode;
         }else{
             temp->right = newnode;
             q2.pop();
         }
     }
     q2.push(newnode);
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
       cout<<"\nBinary Tree \n 1. insert in Tree 1 \n 2. insert in Tree 2 \n 3. Display(levelorder) \n 4. Check Identicity of trees \n 5. DeleteNode in Tree 1\n 6. DeleteNode in Tree 2\n Press any key to Exit \n";
       cin>>i;
       switch (i)
       {
           case 1:  cout<<" Enter element to insert in Tree 1 :- ";
                    cin>>item;
                    t.insertNode1(item);
                    break;

           case 2:  cout<<" Enter element to insert in Tree 2 :- ";
                    cin>>item;
                    t.insertNode2(item);
                    break;

           case 3:  cout<<"Levelorder Traversal of Tree 1 :- ";
                    t.levelorderTraversal(root1);
                    cout<<"\nLevelorder Traversal of Tree 2 :- ";
                    t.levelorderTraversal(root2);
                    break;

           case 4:  cout<<"Check Identical Trees :- ";
                    if(t.checkIdentical(root1 , root2))
                        cout<<"Identicals"<<"\n";
                    else
                        cout<<"Non Identicals \n";
                    break;

           case 5:  cout<<" Enter element to be deleted from Tree 1 :- ";
                    cin>>item;
                    root1 = t.deleteNode(root1,item);
                    break; 

           case 6:  cout<<" Enter element to be deleted from Tree 2 :- ";
                    cin>>item;
                    root2 = t.deleteNode(root2,item);
                    break;                                                 

           default: exit(1);
                    break;
       }

   }

    return 0;
}